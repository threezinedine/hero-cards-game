#pragma once
#include <cores/commons/common.hpp>
#include "ISceneManager.hpp"

namespace ntt
{
    class SceneManager : public ISceneManager
    {
    public:
        SceneManager();
        ~SceneManager();

        void AddScene(Ref<IScene> scene) override;

        void Update(float delta) override;

        void ChangeScene(String sceneName) override;

    private:
        Map<String, Ref<IScene>> m_Scenes;
        Ref<IScene> m_CurrentScene;
    };
}