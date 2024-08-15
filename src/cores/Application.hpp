#pragma once

#include <cores/commons/common.hpp>
#include "interfaces/IUpdatable.hpp"
#include "scenes/SceneManager.hpp"
#include "resources/ResourceManager.hpp"

namespace ntt
{
    class Application : public IUpdatable
    {
    public:
        Application();
        virtual ~Application();

        void Update(float delta) override;

        inline bool IsRunning() const { return m_Running; }

    protected:
        virtual void UpdateImpl(float delta);

        inline Ref<SceneManager> GetSceneManager() const { return m_SceneManager; }

    private:
        bool m_Running;
        Ref<SceneManager> m_SceneManager;
        Ref<ResourceManager> m_GlobalResourceManager;
    };
}