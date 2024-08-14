#pragma once
#include <common.hpp>

namespace ntt
{
    class FSMState;

    struct FSMTransition
    {
        std::function<bool()> condition = []()
        { return false; };
        Ref<FSMState> targetState = nullptr;
        bool inverse = false;
    };

    class FSMState
    {
    public:
        FSMState(String name);
        virtual ~FSMState();

        inline String GetName() const { return m_Name; }
        inline void SetOnEnter(std::function<void()> onEnter) { m_OnEnter = onEnter; }
        inline void SetOnExit(std::function<void()> onExit) { m_OnExit = onExit; }
        inline void SetOnState(std::function<void()> onState) { m_OnState = onState; }
        inline void SetState(Ref<FSMState> state) { m_CurrentState = state; }
        void AddTransition(FSMTransition transition);

        inline void OnEnter() { m_OnEnter(); }
        void Update();
        inline void OnExit() { m_OnExit(); }

    private:
        String m_Name;
        std::function<void()> m_OnEnter = []() {};
        std::function<void()> m_OnExit = []() {};
        std::function<void()> m_OnState = []() {};

        Ref<FSMState> m_CurrentState;
        List<FSMTransition> m_Transitions;
    };

} // namespace ntt
