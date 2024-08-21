#pragma once
#include "default_scripts_include.hpp"

namespace ntt
{
    class HoverCheckScript : public Script
    {
    public:
        HoverCheckScript(sid_t scriptId);

    protected:
        void UpdateImpl(void *sender, float delta) override;
        void LoadConfigureImpl(ConfigurableObject &config) override;

    private:
        unsigned int m_Factor = 1;
    };
}