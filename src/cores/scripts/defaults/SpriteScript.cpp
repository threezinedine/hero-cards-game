#include "SpriteScript.hpp"
#include <renderer/renderer.hpp>
#include "FSMScript.hpp"

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

    void SpriteScript::LoadConfigureImpl(JSON config)
    {
        if (config.contains("rid") && config["rid"].is_number_unsigned())
        {
            m_Texture.SetResourceId(config["rid"]);
        }

        if (config.contains("grid") && config["grid"].is_object())
        {
            auto gridCfg = config["grid"];
            if (gridCfg.contains("numCols") && gridCfg["numCols"].is_number_unsigned())
            {
                m_Texture.SetNumCols(gridCfg["numCols"]);
            }

            if (gridCfg.contains("numRows") && gridCfg["numRows"].is_number_unsigned())
            {
                m_Texture.SetNumRows(gridCfg["numRows"]);
            }
        }

        if (config.contains("changePerSecond") && config["changePerSecond"].is_number())
        {
            m_ChangePerSecond = config["changePerSecond"];
        }

        if (config.contains("frames") && config["frames"].is_array())
        {
            auto framesCfg = config["frames"];
            for (auto frameCfg : framesCfg)
            {
                if (frameCfg.is_object())
                {
                    Frame frame;
                    if (frameCfg.contains("colIndex") && frameCfg["colIndex"].is_number_unsigned() && frameCfg.contains("rowIndex") && frameCfg["rowIndex"].is_number_unsigned())
                    {
                        frame.colIndex = frameCfg["colIndex"];
                        frame.rowIndex = frameCfg["rowIndex"];
                        m_Frames.push_back(frame);
                    }
                }
            }
        }
    }

    void SpriteScript::LoadImpl()
    {
        m_Texture.SetGeometry(GetEntity()->GetGeometry());
        m_Texture.Load();
    }

    void SpriteScript::UpdateImpl(float delta)
    {
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
