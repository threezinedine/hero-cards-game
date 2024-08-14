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

    void FSMScript::UpdateImpl(float delta)
    {
        if (m_State == nullptr)
        {
            return;
        }

        m_State->Update();
    }

    void FSMScript::RenderImpl()
    {
    }
} // namespace ntt
