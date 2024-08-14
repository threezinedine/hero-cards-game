#pragma once
#include <cores/commons/common.hpp>
#include "Entity.hpp"
#include <cores/interfaces/Loadable.hpp>
#include <cores/interfaces/IRenderable.hpp>
#include <cores/interfaces/IConfigurable.hpp>

namespace ntt
{
    class EntityManager : public IRenderable, public Loadable, public IConfigurable
    {
    public:
        EntityManager(String sceneName);
        virtual ~EntityManager();

        void Load() override;
        void Update(float delta) override;
        void Render() override;
        void Unload() override;

        void AddEntity(Scope<Entity> entity);

        void LoadConfigure(JSON config) override;

    protected:
    private:
        String m_SceneName;
        Map<eid_t, Scope<Entity>> m_Entities;
    };
} // namespace ntt
