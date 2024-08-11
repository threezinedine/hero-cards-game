#pragma once
#include <common.hpp>
#include "IRenderable.hpp"
#include "ILifetime.hpp"
#include "Application.hpp"

class SceneManagement;
class ComponentManagement;

class Scene : public IRenderable, public ILifetime
{
public:
    Scene(String sceneName);
    virtual ~Scene();

    void Init() override;
    void Update(float delta) override;
    virtual void Render() override;
    virtual void Release() override;

    inline bool IsInitialized() const override { return m_IsInitialized; }

    inline void SetSceneManagement(SceneManagement *sceneManagement) { m_SceneManagement = sceneManagement; }
    inline String GetSceneName() const { return m_SceneName; }

protected:
    virtual void InitImpl();
    virtual void UpdateImpl(float delta);
    virtual void RenderImpl();
    virtual void ReleaseImpl();

    inline SceneManagement *GetSceneManagement() const { return m_SceneManagement; }

    Scope<ComponentManagement> m_ComponentManagement;

private:
    SceneManagement *m_SceneManagement;
    bool m_IsInitialized = false;
    String m_SceneName;
};
