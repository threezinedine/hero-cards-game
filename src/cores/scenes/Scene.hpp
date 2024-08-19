#pragma once
#include <cores/commons/common.hpp>
#include <cores/interfaces/Loadable.hpp>
#include "IScene.hpp"

namespace ntt
{
    class IEntityManager;
    class IResourceManager;
    class IScriptManager;

    class Scene : public IScene
    {
    public:
        Scene(String sceneName);
        virtual ~Scene();

        void Load() override;
        void Update(float delta) override;
        virtual void Unload() override;

        inline void SetSceneManager(ISceneManager *sceneManager) override { m_SceneManager = sceneManager; }
        inline const String &GetSceneName() const { return m_SceneName; }

        void LoadConfigure(JSON config) override;

        void AddScript(Ref<IScript> script) override;

    protected:
        virtual void LoadImpl();
        virtual void UpdateImpl(float delta);
        virtual void UnloadImpl();

        virtual void LoadConfigureImpl(JSON config);

        inline ISceneManager *GetSceneManager() const { return m_SceneManager; }
        inline Ref<IResourceManager> GetResourceManager() const { return m_ResourceManager; }
        inline Ref<IEntityManager> GetEntityManager() const { return m_EntityManager; }

    private:
        ISceneManager *m_SceneManager;
        Ref<IResourceManager> m_ResourceManager;
        Ref<IEntityManager> m_EntityManager;
        Ref<IScriptManager> m_ScriptManager;
        Map<sid_t, Ref<IScript>> m_Scripts;
        bool m_Loaded = false;
        String m_SceneName;
    };
}