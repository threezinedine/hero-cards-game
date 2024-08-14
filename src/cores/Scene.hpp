#pragma once
#include <common.hpp>
#include "interfaces/IRenderable.hpp"
#include "interfaces/ILoadable.hpp"
#include "Application.hpp"
#include "resources/ResourceManager.hpp"
#include "entities/EntityManager.hpp"

namespace ntt
{
    class SceneManagement;
    class ComponentManagement;
    class ResourceManager;

    class Scene : public IRenderable, public ILoadable
    {
    public:
        Scene(String sceneName);
        virtual ~Scene();

        void Load() override;
        void Update(float delta) override;
        virtual void Render() override;
        virtual void Unload() override;

        inline bool IsLoaded() const override { return m_Loaded; }

        inline void SetSceneManagement(SceneManagement *sceneManagement) { m_SceneManagement = sceneManagement; }
        inline String GetSceneName() const { return m_SceneName; }

    protected:
        virtual void LoadImpl();
        virtual void UpdateImpl(float delta);
        virtual void RenderImpl();
        virtual void UnloadImpl();

        // Scope<ComponentManagement> m_ComponentManagement;
        inline SceneManagement *GetSceneManagement() const { return m_SceneManagement; }
        inline Ref<ResourceManager> GetResourceManager() const { return m_ResourceManager; }
        inline Ref<EntityManager> GetEntityManager() const { return m_EntityManager; }

    private:
        SceneManagement *m_SceneManagement;
        Ref<ResourceManager> m_ResourceManager;
        Ref<EntityManager> m_EntityManager;
        bool m_Loaded = false;
        String m_SceneName;
    };
}