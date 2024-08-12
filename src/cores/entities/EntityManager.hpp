#pragma once
#include <common.hpp>
#include "Entity.hpp"
#include <cores/ILoadable.hpp>
#include <cores/IRenderable.hpp>

namespace ntt
{
    class EntityManager : public IRenderable, public ILoadable
    {
    public:
        EntityManager(String sceneName);
        virtual ~EntityManager();

        void Load() override;
        void Update(float delta) override;
        void Render() override;
        void Unload() override;

        inline bool IsLoaded() const override { return true; }

        void AddEntity(Scope<Entity> entity);

    protected:
    private:
        String m_SceneName;
        List<Scope<Entity>> m_Entities;
    };
} // namespace ntt
