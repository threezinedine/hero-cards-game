#pragma once
#include <common.hpp>
#include "IRenderable.hpp"
#include "ILifetime.hpp"
#include "Application.hpp"

class Scene : public IRenderable, public ILifetime
{
public:
    Scene();
    Scene(Application *app);
    virtual ~Scene();

    void Init() override;
    void Update(float delta) override;
    virtual void Render() override;
    virtual void Release() override;

    inline void SetApplication(Application *app) { m_App = app; }

    inline bool IsInitialized() const override { return m_IsInitialized; }

protected:
    virtual void InitImpl();
    virtual void UpdateImpl(float delta);
    virtual void RenderImpl();
    virtual void ReleaseImpl();

    inline Application *GetApp() const { return m_App; }

private:
    Application *m_App;
    bool m_IsInitialized = false;
};
