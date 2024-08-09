#include "Img.hpp"

Img::Img(Scope<IPath> path, int numCols, int numRows)
    : m_NumCols(numCols), m_NumRows(numRows),
      m_ColIndex(0), m_RowIndex(0),
      m_Texture(nullptr), m_PosX(0), m_PosY(0),
      m_Path(std::move(path))
{
}

Img::~Img()
{
}

void Img::LoadImpl()
{
    auto img = LoadImage(m_Path->Get().c_str());
    m_ColWidth = img.width / m_NumCols;
    m_RowHeight = img.height / m_NumRows;

    m_Texture = CreateScope<Texture2D>(LoadTextureFromImage(img));

    UnloadImage(img);

    SetSize(DEFAULT_SIZE);
}

void Img::UnloadImpl()
{
    UnloadTexture(*m_Texture);
}

void Img::RenderImpl()
{
    int drawColIndex = m_ColIndex < m_NumCols ? m_ColIndex : m_NumCols - 1;
    int drawRowIndex = m_RowIndex < m_NumRows ? m_RowIndex : m_NumRows - 1;

    DrawTexturePro(*m_Texture,
                   {drawColIndex * m_ColWidth, drawRowIndex * m_RowHeight, m_ColWidth, m_RowHeight},
                   {m_PosX, m_PosY, m_width, m_height},
                   {m_width / 2, m_height / 2},
                   0,
                   WHITE);
}

void Img::SetSize(float width)
{
    if (width == DEFAULT_SIZE)
    {
        m_width = m_ColWidth;
    }
    else
    {
        m_width = width;
    }

    m_height = m_width * m_RowHeight / m_ColWidth;
}
