#pragma once

#include <common.hpp>
#include "IRenderable.hpp"

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

private:
    bool m_Running;
};