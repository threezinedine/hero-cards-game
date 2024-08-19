#pragma once
#include <cores/interfaces/Loadable.hpp>
#include <cores/interfaces/IConfigurable.hpp>
#include <cores/interfaces/IUpdatable.hpp>

namespace ntt
{
    class IScript;

    class IScriptManager : public Loadable, public IUpdatable, public IConfigurable
    {
    public:
        virtual ~IScriptManager() = default;

        virtual void AddScript(Ref<IScript> script) = 0;
        virtual void SetSender(void *) = 0;
    };
} // namespace ntt
