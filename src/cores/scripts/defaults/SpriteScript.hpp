#pragma once

#include "default_scripts_include.hpp"
#include <utils/timer/AccTimer.hpp>
#include <cores/data/Texture.hpp>

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

    private:
        struct Frame
        {
            unsigned int colIndex;
            unsigned int rowIndex;
        };

        Texture m_Texture;
        float m_ChangePerSecond;
        List<Frame> m_Frames;
        unsigned int m_CurrentFrameIndex;

        AccTimer m_Timer;
    };
}