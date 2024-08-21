#include "SpriteScript.hpp"
#include <renderer/renderer.hpp>
#include "FSMScript.hpp"
#include <cores/entities/Geometry.hpp>
#include <cores/entities/IEntity.hpp>

namespace ntt
{
    SpriteScript::SpriteScript(sid_t scriptId)
        : Script(scriptId), m_Texture(0), m_ChangePerSecond(100.0f),
          m_CurrentFrameIndex(0)
    {
    }

    SpriteScript::~SpriteScript()
    {
    }

    void SpriteScript::LoadConfigureImpl(ConfigurableObject &config)
    {
        if (rid_t rid = config.Get<rid_t>("rid", INVALID_RID); rid != INVALID_RID)
        {
            m_Texture.SetResourceId(rid);
        }

        auto gridConfig = config.GetMap<int>("grid", {{"numCols", 1},
                                                      {"numRows", 1}});

        m_Texture.SetNumCols(gridConfig["numCols"]);
        m_Texture.SetNumRows(gridConfig["numRows"]);

        m_ChangePerSecond = config.Get<float>("changePerSecond", m_ChangePerSecond);

        auto frameConfigs = config.GetList<ConfigurableObject>("frames");
        for (auto frameConfig : frameConfigs)
        {
            Frame frame;
            frame.colIndex = frameConfig.Get<int>("colIndex", 0);
            frame.rowIndex = frameConfig.Get<int>("rowIndex", 0);
            m_Frames.push_back(frame);
        }
    }

    void SpriteScript::LoadImpl()
    {
    }

    void SpriteScript::UpdateImpl(void *sender, float delta)
    {
        if (!IsLoaded())
        {
            auto entity = static_cast<IEntity *>(sender);
            m_Texture.SetGeometry(entity->GetGeometry());
            m_Texture.Load();
        }

        if (m_Timer.GetDelta() > m_ChangePerSecond)
        {
            if (m_Frames.size() == 0)
            {
                m_Texture.NextFrame();
            }
            else
            {
                m_CurrentFrameIndex++;
                if (m_CurrentFrameIndex >= m_Frames.size())
                {
                    m_CurrentFrameIndex = 0;
                }

                auto frame = m_Frames[m_CurrentFrameIndex];
                m_Texture.SetCurrentFrame(frame.colIndex, frame.rowIndex);
            }
            m_Timer.Reset();
        }

        m_Texture.Render();
    }
} // namespace ntt
