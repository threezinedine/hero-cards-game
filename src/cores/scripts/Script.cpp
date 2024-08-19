#include "Script.hpp"
#include <cores/entities/IEntity.hpp>

namespace ntt
{
    Script::Script(sid_t scriptId)
        : m_ScriptID(scriptId)
    {
    }

    Script::Script(sid_t scriptId, IEntity *entity)
        : m_ScriptID(scriptId)
    {
    }

    Script::~Script()
    {
    }

    void Script::Load()
    {
        LoadImpl();
    }

    void Script::LoadImpl()
    {
    }

    void Script::Update(void *sender, float delta)
    {
        UpdateImpl(sender, delta);
    }

    void Script::UpdateImpl(void *sender, float delta)
    {
    }

    void Script::Unload()
    {
        UnloadImpl();
    }

    void Script::UnloadImpl()
    {
    }

    void Script::LoadConfigure(JSON config)
    {
        if (config.is_object())
        {
            LoadConfigureImpl(config);
        }
    }

    void Script::LoadConfigureImpl(JSON config)
    {
    }
} // namespace ntt
