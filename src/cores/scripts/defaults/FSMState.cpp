#include "FSMState.hpp"

namespace ntt
{
    FSMState::FSMState(String name)
        : m_Name(name), m_CurrentState(nullptr)
    {
    }

    FSMState::~FSMState()
    {
    }

    void FSMState::AddTransition(FSMTransition transition)
    {
        m_Transitions.push_back(transition);
    }

    void FSMState::Update()
    {
        m_OnState();

        if (m_CurrentState == nullptr)
        {
            return;
        }

        m_CurrentState->Update();

        for (auto const &transition : m_CurrentState->m_Transitions)
        {
            if (transition.condition() != transition.inverse)
            {
                m_CurrentState->OnExit();
                m_CurrentState = transition.targetState;
                m_CurrentState->OnEnter();
                break;
            }
        }
    }
}