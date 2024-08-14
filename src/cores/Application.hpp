#pragma once

#include <common.hpp>
#include "interfaces/IRenderable.hpp"
#include "SceneManagement.hpp"

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

        inline Ref<SceneManagement> GetSceneManagement() const { return m_SceneManagement; }

    private:
        bool m_Running;
        Ref<SceneManagement> m_SceneManagement;
    };
}