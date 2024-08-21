#pragma once
#include <cores/interfaces/Loadable.hpp>
#include <cores/interfaces/IConfigurable.hpp>
#include <cores/interfaces/IUpdatable.hpp>

namespace ntt
{
    class IScript;

    class IScriptManager : public Loadable, public IUpdatable
    {
    public:
        virtual ~IScriptManager() = default;

        virtual void AddScript(Ref<IScript> script) = 0;
        virtual void SetSender(void *) = 0;
        virtual void LoadConfigure(List<ConfigurableObject> configs) = 0;
    };
} // namespace ntt
