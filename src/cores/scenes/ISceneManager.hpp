#pragma once

#include <cores/commons/common.hpp>
#include <cores/interfaces/IUpdatable.hpp>

namespace ntt
{
    class IScene;

    class ISceneManager : public IUpdatable
    {
    public:
        virtual ~ISceneManager() = default;

        virtual void AddScene(Ref<IScene> scene) = 0;
        virtual void ChangeScene(String sceneName) = 0;
    };
} // namespace ntt