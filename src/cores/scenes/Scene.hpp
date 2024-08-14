#pragma once
#include <cores/commons/common.hpp>
#include <cores/interfaces/interfaces.hpp>
#include <cores/resources/ResourceManager.hpp>
#include <cores/entities/EntityManager.hpp>

namespace ntt
{
    class SceneManager;
    class ResourceManager;
    class Application;

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

        inline void SetSceneManager(SceneManager *sceneManager) { m_SceneManager = sceneManager; }
        inline String GetSceneName() const { return m_SceneName; }

    protected:
        virtual void LoadImpl();
        virtual void UpdateImpl(float delta);
        virtual void RenderImpl();
        virtual void UnloadImpl();

        // Scope<ComponentManagement> m_ComponentManagement;
        inline SceneManager *GetSceneManager() const { return m_SceneManager; }
        inline Ref<ResourceManager> GetResourceManager() const { return m_ResourceManager; }
        inline Ref<EntityManager> GetEntityManager() const { return m_EntityManager; }

    private:
        SceneManager *m_SceneManager;
        Ref<ResourceManager> m_ResourceManager;
        Ref<EntityManager> m_EntityManager;
        bool m_Loaded = false;
        String m_SceneName;
    };
}