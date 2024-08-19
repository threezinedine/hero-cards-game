#pragma once
#include <cores/interfaces/Loadable.hpp>
#include <cores/interfaces/IConfigurable.hpp>
#include <cores/interfaces/IUpdatable.hpp>
#include <cores/commons/common.hpp>

namespace ntt
{
    class IEntity;

    class IScript : public IUpdatable, public Loadable, public IConfigurable
    {
    public:
        virtual ~IScript() = default;

        virtual sid_t GetScriptID() const = 0;
        virtual void SetEntity(IEntity *entity) = 0;
    };
} // namespace ntt
