#pragma once
#include <common.hpp>
#include <cores/interfaces/IRenderable.hpp>

namespace ntt
{
    class Scene;

    class SceneManager : public IRenderable
    {
    public:
        SceneManager();
        ~SceneManager();

        void AddScene(Scope<Scene> scene);

        void Update(float delta) override;
        void Render() override;

        void ChangeScene(int index);

    protected:
    private:
        List<Scope<Scene>> m_Scenes;
        int m_CurrentSceneIndex;
    };
}