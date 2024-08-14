#pragma once

#include <cores/commons/common.hpp>
#include "interfaces/IRenderable.hpp"
#include "scenes/SceneManager.hpp"

namespace ntt
{
    class Application : public IRenderable
    {
    public:
        Application();
        virtual ~Application();

        void Update(float delta) override;
        void Render() override;

        inline bool IsRunning() const { return m_Running; }

    protected:
        virtual void UpdateImpl(float delta);
        virtual void RenderImpl();

        inline Ref<SceneManager> GetSceneManager() const { return m_SceneManager; }

    private:
        bool m_Running;
        Ref<SceneManager> m_SceneManager;
    };
}