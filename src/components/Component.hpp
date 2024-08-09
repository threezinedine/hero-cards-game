#pragma once
#include <common.hpp>
#include <cores/core.hpp>

class Component : IRenderable
{
public:
    Component() = default;
    virtual ~Component() = default;
    void Load();
    void Unload();
    void Update(float delta) override;
    void Render() override;

    void ConfigLoad(JSON config);

protected:
    virtual void LoadImpl();
    virtual void UnloadImpl();

    virtual void UpdateImpl(float delta);
    virtual void RenderImpl();

    virtual void ConfigLoadImpl(JSON config);

private:
    bool m_Loaded = false;
    bool m_ConfigLoaded = false;
};