#pragma once
#include <common.hpp>
#include <components/components.hpp>
#include <cores/core.hpp>
#include <utils/utils.hpp>

namespace ntt
{
    class Img;

    class Sprite : public Component
    {
    public:
        Sprite(Scope<IPath> path, int numCols = 1,
               int numRows = 1, int changePerMillis = 100);
        virtual ~Sprite();

    protected:
        void LoadImpl() override;
        void UnloadImpl() override;

        void UpdateImpl(float delta) override;
        void RenderImpl() override;

        void NextFrame();

    private:
        Scope<Img> m_Img;
        AccTimer m_Timer;

        int m_ChangePerMillis;
        int m_CurrentRowIndex = 0;
        int m_CurrentColIndex = 0;
    };
}