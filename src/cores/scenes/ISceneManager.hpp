#pragma once

#include <cores/commons/common.hpp>
#include <cores/interfaces/IUpdatable.hpp>
#include <utils/configuration/ConfigurableObject.hpp>

namespace ntt
{
    class IScene;

    class ISceneManager : public IUpdatable
    {
    public:
        virtual ~ISceneManager() = default;

        virtual void AddScene(Ref<IScene> scene) = 0;
        virtual void ChangeScene(String sceneName) = 0;
        virtual void SetConfig(ConfigurableObject &config) = 0;
    };
} // namespace ntt