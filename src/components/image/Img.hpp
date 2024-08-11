#pragma once
#include <common.hpp>
#include <utils/utils.hpp>
#include <components/components.hpp>

#define DEFAULT_SIZE -1

namespace ntt
{
    class Img : public Component
    {
    public:
        Img(Scope<IPath> path, int numCols = 1,
            int numRows = 1);
        ~Img();

        inline void SetIndexes(int colIndex, int rowIndex)
        {
            m_ColIndex = colIndex;
            m_RowIndex = rowIndex;
        }

        void SetWidthKeepRatio(float width);

        inline int GetNumCols() const { return m_NumCols; }
        inline int GetNumRows() const { return m_NumRows; }
        inline void SetNumCols(int numCols) { m_NumCols = numCols; }
        inline void SetNumRows(int numRows) { m_NumRows = numRows; }

    protected:
        void LoadImpl() override;
        void UnloadImpl() override;

        void RenderImpl() override;

        // void ConfigLoadImpl(JSON config) override;

    private:
        int m_NumCols;
        int m_NumRows;
        int m_ColIndex;
        int m_RowIndex;
        float m_ColWidth;
        float m_RowHeight;
        Scope<Texture2D> m_Texture;
        Scope<IPath> m_Path;
    };
}