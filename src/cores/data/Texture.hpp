#pragma once
#include <cores/commons/commons.hpp>
#include <cores/entities/Geometry.hpp>
#include <cores/interfaces/IRenderable.hpp>

namespace ntt
{
    class Texture : public IRenderable
    {
    public:
        Texture(rid_t resourceId);
        virtual ~Texture();

        inline rid_t GetResourceId() const { return m_ResourceId; }
        inline void SetResourceId(rid_t resourceId) { m_ResourceId = resourceId; }

        inline void SetGeometry(Ref<Geometry> geometry) { m_Geometry = geometry; }

        inline void SetNumCols(unsigned int numCols) { m_NumCols = numCols; }
        inline void SetNumRows(unsigned int numRows) { m_NumRows = numRows; }
        inline void SetGridData(unsigned int numCols, unsigned int numRows)
        {
            m_NumCols = numCols;
            m_NumRows = numRows;
        }

        inline void SetRowIndex(unsigned int rowIndex) { m_CurrentRowIndex = rowIndex; }
        inline void SetColIndex(unsigned int colIndex) { m_CurrentColIndex = colIndex; }
        inline void SetCurrentFrame(unsigned int colIndex, unsigned int rowIndex)
        {
            m_CurrentColIndex = colIndex;
            m_CurrentRowIndex = rowIndex;
        }

        void Load();
        void Render() override;
        void NextFrame();

    private:
        rid_t m_ResourceId;
        Size m_FrameSize;

        unsigned int m_NumCols;
        unsigned int m_NumRows;

        float m_ColWidth;
        float m_RowHeight;

        Ref<Geometry> m_Geometry;

        unsigned int m_CurrentColIndex;
        unsigned int m_CurrentRowIndex;
    };
} // namespace ntt
