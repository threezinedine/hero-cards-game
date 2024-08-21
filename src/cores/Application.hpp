#pragma once

#include <cores/commons/common.hpp>
#include "interfaces/IUpdatable.hpp"
#include <utils/configuration/ConfigurableObject.hpp>

namespace ntt
{
    class ISceneManager;
    class IResourceManager;

    class Application : public IUpdatable
    {
    public:
        Application(const ConfigurableObject &config);
        virtual ~Application();

        void Update(float delta) override;

        inline bool IsRunning() const { return m_Running; }

    protected:
        virtual void UpdateImpl(float delta);

        inline Ref<ISceneManager> GetSceneManager() const { return m_SceneManager; }

    private:
        ConfigurableObject m_Config;
        bool m_Running;
        Ref<ISceneManager> m_SceneManager;
        Ref<IResourceManager> m_GlobalResourceManager;
    };
}