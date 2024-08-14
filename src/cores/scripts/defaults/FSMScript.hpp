#pragma once
#include "default_scripts_include.hpp"
#include "FSMState.hpp"

namespace ntt
{
    class FSMScript : public Script
    {
    public:
        FSMScript(sid_t id);
        virtual ~FSMScript();

        inline void SetState(Ref<FSMState> state) { m_State = state; }

    protected:
        void UpdateImpl(float delta) override;
        void RenderImpl() override;

    private:
        Ref<FSMState> m_State;
    };
} // namespace ntt
