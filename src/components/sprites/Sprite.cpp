#include "Sprite.hpp"

Sprite::Sprite(Scope<IPath> path, int numCols, int numRows, int changePerMillis)
    : m_ChangePerMillis(changePerMillis)
{
    m_Img = CreateScope<Img>(std::move(path), numCols, numRows);
}

Sprite::~Sprite()
{
}

void Sprite::LoadImpl()
{
    m_Img->Load();
    m_Img->SetPosX(GetPosX());
    m_Img->SetPosY(GetPosY());
    m_Img->SetWidthKeepRatio(GetWidth());
    m_Timer.Reset();
}

void Sprite::UnloadImpl()
{
    m_Img->Unload();
}

void Sprite::UpdateImpl(float delta)
{
    if (m_Timer.GetDelta() >= float(m_ChangePerMillis) / 1000)
    {
        NextFrame();
        m_Timer.Reset();
    }

    m_Img->SetIndexes(m_CurrentColIndex, m_CurrentRowIndex);
}

void Sprite::NextFrame()
{
    if (m_CurrentRowIndex < m_Img->GetNumRows() - 1)
    {
        m_CurrentRowIndex++;
    }
    else
    {
        m_CurrentRowIndex = 0;

        if (m_CurrentColIndex < m_Img->GetNumCols() - 1)
        {
            m_CurrentColIndex++;
        }
        else
        {
            m_CurrentColIndex = 0;
        }
    }
}

void Sprite::RenderImpl()
{
    m_Img->Render();
}