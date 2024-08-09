#pragma once
#include <common.hpp>
#include "IRenderable.hpp"
#include "ILifetime.hpp"
#include "Application.hpp"

class SceneManagement;

class Scene : public IRenderable, public ILifetime
{
public:
    Scene();
    virtual ~Scene();

    void Init() override;
    void Update(float delta) override;
    virtual void Render() override;
    virtual void Release() override;

    inline bool IsInitialized() const override { return m_IsInitialized; }

    inline void SetSceneManagement(SceneManagement *sceneManagement) { m_SceneManagement = sceneManagement; }

protected:
    virtual void InitImpl();
    virtual void UpdateImpl(float delta);
    virtual void RenderImpl();
    virtual void ReleaseImpl();

    inline SceneManagement *GetSceneManagement() const { return m_SceneManagement; }

private:
    SceneManagement *m_SceneManagement;
    bool m_IsInitialized = false;
};
