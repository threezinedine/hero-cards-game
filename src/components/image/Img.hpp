#pragma once
#include <common.hpp>
#include <utils/utils.hpp>

#define DEFAULT_SIZE -1

class Img
{
public:
    Img(const IPath &path, int numCols = 1,
        int numRows = 1);
    ~Img();

    void Render(int colIndex, int rowIndex,
                float posX, float posY);

    void SetSize(float width = DEFAULT_SIZE);
    inline Vector2 GetSize() const { return Vector2{m_width, m_height}; }

private:
    int m_NumCols;
    int m_NumRows;
    float m_ColWidth;
    float m_RowHeight;
    float m_width;
    float m_height;
    Texture2D m_Texture;
};