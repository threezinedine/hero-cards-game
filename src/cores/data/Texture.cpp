#include "Texture.hpp"
#include <renderer/renderer.hpp>
#include <utils/log/log.hpp>

namespace ntt
{
    Texture::Texture(rid_t resourceId)
        : m_ResourceId(resourceId),
          m_FrameSize({100.0f, 100.0f}),
          m_NumCols(1),
          m_NumRows(1),
          m_ColWidth(0.0f),
          m_RowHeight(0.0f),
          m_CurrentColIndex(0),
          m_CurrentRowIndex(0)
    {
    }

    Texture::~Texture()
    {
    }

    void Texture::SetRowIndex(unsigned int rowIndex)
    {
        if (rowIndex >= m_NumRows)
            return;
        m_CurrentRowIndex = rowIndex;
    }

    void Texture::SetColIndex(unsigned int colIndex)
    {
        if (colIndex >= m_NumCols)
            return;
        m_CurrentColIndex = colIndex;
    }

    void Texture::SetCurrentFrame(unsigned int colIndex, unsigned int rowIndex)
    {
        if (!IsValidFrame(colIndex, rowIndex))
            return;
        m_CurrentColIndex = colIndex;
        m_CurrentRowIndex = rowIndex;
    }

    bool Texture::IsValidFrame(unsigned int colIndex, unsigned int rowIndex) const
    {
        return colIndex < m_NumCols && rowIndex < m_NumRows;
    }

    void Texture::Load()
    {
        auto textureSize = renderer::GetTextureSize(m_ResourceId);

        m_FrameSize.width = textureSize.width / m_NumCols;
        m_FrameSize.height = textureSize.height / m_NumRows;

        auto width = m_Geometry->GetSize().width;
        m_Geometry->GetSize().height = m_FrameSize.height / m_FrameSize.width * width;
    }

    void Texture::Render()
    {
        renderer::DrawTexture(
            m_ResourceId,
            {m_FrameSize.width * m_CurrentColIndex, m_FrameSize.height * m_CurrentRowIndex},
            m_FrameSize,
            m_Geometry->GetPoint(),
            m_Geometry->GetSize());
    }

    void Texture::NextFrame()
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
