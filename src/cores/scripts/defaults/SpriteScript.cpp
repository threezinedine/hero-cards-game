#include "SpriteScript.hpp"
#include <renderer/renderer.hpp>
#include "FSMScript.hpp"

namespace ntt
{
    SpriteScript::SpriteScript(sid_t scriptId)
        : Script(scriptId), m_Texture(0), m_ChangePerSecond(100.0f)
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
            m_Texture.NextFrame();
            m_Timer.Reset();
        }

        m_Texture.Render();
    }
} // namespace ntt
