#include "SpriteScript.hpp"
#include <renderer/renderer.hpp>

namespace ntt
{
    SpriteScript::SpriteScript(sid_t scriptId)
        : Script(scriptId), m_ResourceId(0),
          m_ResourceSize({100, 100}), m_FrameSize({100, 100}),
          m_NumCols(1), m_NumRows(1),
          m_CurrentColIndex(0), m_CurrentRowIndex(0),
          m_ChangePerSecond(0.1)
    {
    }

    SpriteScript::~SpriteScript()
    {
    }

    void SpriteScript::LoadConfigureImpl(JSON config)
    {
        if (config.contains("rid") && config["rid"].is_number_unsigned())
        {
            m_ResourceId = config["rid"];
        }

        if (config.contains("grid") && config["grid"].is_object())
        {
            auto gridCfg = config["grid"];
            if (gridCfg.contains("numCols") && gridCfg["numCols"].is_number_unsigned())
            {
                m_NumCols = gridCfg["numCols"];
            }

            if (gridCfg.contains("numRows") && gridCfg["numRows"].is_number_unsigned())
            {
                m_NumRows = gridCfg["numRows"];
            }
        }

        if (config.contains("changePerSecond") && config["changePerSecond"].is_number())
        {
            m_ChangePerSecond = config["changePerSecond"];
        }
    }

    void SpriteScript::LoadImpl()
    {
        auto textureSize = renderer::GetTextureSize(m_ResourceId);

        m_ResourceSize.width = textureSize.width;
        m_ResourceSize.height = textureSize.height;

        m_FrameSize.width = m_ResourceSize.width / m_NumCols;
        m_FrameSize.height = m_ResourceSize.height / m_NumRows;

        m_Timer.Reset();
    }

    void SpriteScript::UpdateImpl(float delta)
    {
        if (m_Timer.GetDelta() > m_ChangePerSecond)
        {
            NextFrame();
            m_Timer.Reset();
        }

        auto width = GetEntity()->GetGeometry().GetSize().width;
        Size size = {width, m_FrameSize.height / m_FrameSize.width * width};

        renderer::DrawTexture(
            m_ResourceId,
            {m_FrameSize.width * m_CurrentColIndex, m_FrameSize.height * m_CurrentRowIndex},
            m_FrameSize,
            GetEntity()->GetGeometry().GetPoint(),
            size);
    }

    void SpriteScript::NextFrame()
    {
        if (m_CurrentColIndex < m_NumCols - 1)
        {
            m_CurrentColIndex++;
        }
        else
        {
            m_CurrentColIndex = 0;

            if (m_CurrentRowIndex < m_NumRows - 1)
            {
                m_CurrentRowIndex++;
            }
            else
            {
                m_CurrentRowIndex = 0;
            }
        }
    }
} // namespace ntt
