#pragma once
#include <common.hpp>
#include "IRenderable.hpp"

class Scene;

class SceneManagement : public IRenderable
{
public:
    SceneManagement();
    ~SceneManagement();

    void AddScene(Scope<Scene> scene);

    void Update(float delta) override;
    void Render() override;

    void ChangeScene(int index);

protected:
private:
    List<Scope<Scene>> m_Scenes;
    int m_CurrentSceneIndex;
};