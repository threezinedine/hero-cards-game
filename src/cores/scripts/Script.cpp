#include "Script.hpp"
#include <cores/entities/IEntity.hpp>
#include <utils/log/log.hpp>

namespace ntt
{
    Script::Script(sid_t scriptId)
        : m_ScriptID(scriptId)
    {
        FUNCTION_LOG();
    }

    Script::Script(sid_t scriptId, IEntity *entity)
        : m_ScriptID(scriptId)
    {
        FUNCTION_LOG();
    }

    Script::~Script()
    {
        FUNCTION_LOG();
    }

    void Script::Load()
    {
        FUNCTION_LOG();
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
        FUNCTION_LOG();
        UnloadImpl();
    }

    void Script::UnloadImpl()
    {
    }

    void Script::LoadConfigure(ConfigurableObject &config)
    {
        FUNCTION_LOG();
        LoadConfigureImpl(config);
    }

    void Script::LoadConfigureImpl(ConfigurableObject &config)
    {
    }
} // namespace ntt
