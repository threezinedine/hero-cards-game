#pragma once
#include <cores/interfaces/IConfigurable.hpp>
#include <cores/interfaces/IUpdatable.hpp>
#include <cores/interfaces/Loadable.hpp>

namespace ntt
{
    class ISceneManager;
    class IScript;

    class IScene : public IConfigurable, public IUpdatable, public Loadable
    {
    public:
        virtual ~IScene() = default;

        virtual void SetSceneManager(ISceneManager *sceneManager) = 0;
        virtual const String &GetSceneName() const = 0;

        virtual void AddScript(Ref<IScript> script) = 0;
    };
} // namespace ntt
