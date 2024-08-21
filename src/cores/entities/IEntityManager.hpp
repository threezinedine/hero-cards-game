#pragma once
#include <cores/interfaces/IConfigurable.hpp>
#include <cores/interfaces/Loadable.hpp>
#include <cores/interfaces/IUpdatable.hpp>

namespace ntt
{
    class IEntity;

    class IEntityManager : public IUpdatable, public Loadable
    {
    public:
        virtual ~IEntityManager() = default;

        virtual void AddEntity(Scope<IEntity> entity) = 0;
        virtual void LoadConfigure(List<ConfigurableObject> configs) = 0;
    };
} // namespace ntt
