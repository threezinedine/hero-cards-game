#pragma once
#include <cores/commons/common.hpp>
#include <cores/resources/ResourceManager.hpp>
#include <cores/entities/EntityManager.hpp>
#include <cores/interfaces/Loadable.hpp>
#include <cores/interfaces/IConfigurable.hpp>
#include <cores/interfaces/IUpdatable.hpp>

namespace ntt
{
    class SceneManager;
    class ResourceManager;
    class Application;

    class Scene : public IUpdatable, public Loadable, public IConfigurable
    {
    public:
        Scene(String sceneName);
        virtual ~Scene();

        void Load() override;
        void Update(float delta) override;
        virtual void Unload() override;

        inline void SetSceneManager(SceneManager *sceneManager) { m_SceneManager = sceneManager; }
        inline String GetSceneName() const { return m_SceneName; }

        void LoadConfigure(JSON config) override;

    protected:
        virtual void LoadImpl();
        virtual void UpdateImpl(float delta);
        virtual void UnloadImpl();

        virtual void LoadConfigureImpl(JSON config);

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