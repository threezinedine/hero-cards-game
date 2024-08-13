#pragma once

#include "default_scripts_include.hpp"
#include <utils/timer/AccTimer.hpp>

namespace ntt
{
    class SpriteScript : public Script
    {
    public:
        SpriteScript(sid_t scriptId);
        virtual ~SpriteScript();

    protected:
        void LoadImpl() override;
        void LoadConfigureImpl(JSON config) override;
        void UpdateImpl(float delta) override;

        void NextFrame();

    private:
        unsigned int m_ResourceId;
        Size m_ResourceSize;
        Size m_FrameSize;

        unsigned int m_NumCols;
        unsigned int m_NumRows;

        unsigned int m_CurrentColIndex;
        unsigned int m_CurrentRowIndex;

        float m_ChangePerSecond;

        AccTimer m_Timer;
    };
}