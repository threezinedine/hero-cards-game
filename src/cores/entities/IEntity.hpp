#pragma once
#include <cores/interfaces/IConfigurable.hpp>
#include <cores/interfaces/Loadable.hpp>
#include <cores/interfaces/IUpdatable.hpp>

namespace ntt
{
    class Geometry;
    class IScript;

    class IEntity : public IUpdatable, public Loadable, public IConfigurable
    {
    public:
        virtual ~IEntity() = default;

        virtual Ref<Geometry> GetGeometry() = 0;
        virtual eid_t GetEntityID() const = 0;

        virtual void AddScript(Scope<IScript> script) = 0;
    };
} // namespace ntt
