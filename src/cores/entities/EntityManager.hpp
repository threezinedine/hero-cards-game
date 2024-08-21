#pragma once
#include <cores/commons/common.hpp>
#include "IEntityManager.hpp"

namespace ntt
{
    class EntityManager : public IEntityManager
    {
    public:
        EntityManager(String sceneName);
        virtual ~EntityManager();

        void Load() override;
        void Update(float delta) override;
        void Unload() override;

        void AddEntity(Scope<IEntity> entity) override;

        void LoadConfigure(List<ConfigurableObject> configs) override;

    protected:
    private:
        String m_SceneName;
        Map<eid_t, Scope<IEntity>> m_Entities;
    };
} // namespace ntt
