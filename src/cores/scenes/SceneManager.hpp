#pragma once
#include <cores/commons/common.hpp>
#include <cores/interfaces/IUpdatable.hpp>

namespace ntt
{
    class Scene;

    class SceneManager : public IUpdatable
    {
    public:
        SceneManager();
        ~SceneManager();

        void AddScene(Ref<Scene> scene);

        void Update(float delta) override;

        void ChangeScene(String sceneName);

    private:
        Map<String, Ref<Scene>> m_Scenes;
        Ref<Scene> m_CurrentScene;
    };
}