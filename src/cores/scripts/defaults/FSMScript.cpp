#include "FSMScript.hpp"

namespace ntt
{
    FSMScript::FSMScript(sid_t id)
        : Script(id), m_State(nullptr)
    {
    }

    FSMScript::~FSMScript()
    {
    }

    void FSMScript::UpdateImpl(void *sender, float delta)
    {
        if (m_State == nullptr)
        {
            return;
        }

        m_State->Update();
    }
} // namespace ntt
