#include "Img.hpp"

Img::Img(const IPath &path, int numCols, int numRows)
    : m_NumCols(numCols), m_NumRows(numRows)
{
    auto img = LoadImage(path.Get().c_str());
    m_ColWidth = img.width / m_NumCols;
    m_RowHeight = img.height / m_NumRows;

    m_Texture = LoadTextureFromImage(img);

    UnloadImage(img);

    SetSize(DEFAULT_SIZE);
}

Img::~Img()
{
    UnloadTexture(m_Texture);
}

void Img::Render(int colIndex, int rowIndex,
                 float posX, float posY)
{
    int drawColIndex = colIndex < m_ColWidth ? colIndex : m_NumCols - 1;
    int drawRowIndex = rowIndex < m_RowHeight ? rowIndex : m_NumRows - 1;

    DrawTexturePro(m_Texture,
                   {drawColIndex * m_ColWidth, drawRowIndex * m_RowHeight, m_ColWidth, m_RowHeight},
                   {posX, posY, m_width, m_height},
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