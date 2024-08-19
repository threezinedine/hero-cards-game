#include "Script.hpp"
#include <cores/entities/IEntity.hpp>

namespace ntt
{
    Script::Script(sid_t scriptId)
        : m_ScriptID(scriptId), m_Entity(nullptr)
    {
    }

    Script::Script(sid_t scriptId, IEntity *entity)
        : m_ScriptID(scriptId), m_Entity(entity)
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

    void Script::Update(float delta)
    {
        UpdateImpl(delta);
    }

    void Script::UpdateImpl(float delta)
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
