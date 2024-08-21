#pragma once

#include "default_scripts_include.hpp"
#include <cores/data/Texture.hpp>
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
        void LoadConfigureImpl(ConfigurableObject &config) override;
        void UpdateImpl(void *sender, float delta) override;

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

        ntt::AccTimer m_Timer;
    };
}