#pragma once
#include <cores/commons/common.hpp>
#include <cores/interfaces/IRenderable.hpp>

namespace ntt
{
    class Scene;

    class SceneManager : public IRenderable
    {
    public:
        SceneManager();
        ~SceneManager();

        void AddScene(Ref<Scene> scene);

        void Update(float delta) override;
        void Render() override;

        void ChangeScene(String sceneName);

    private:
        Map<String, Ref<Scene>> m_Scenes;
        Ref<Scene> m_CurrentScene;
    };
}