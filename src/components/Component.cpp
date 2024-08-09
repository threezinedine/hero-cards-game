#include "Component.hpp"

void Component::Load()
{
    if (!m_Loaded)
    {
        LoadImpl();
        m_Loaded = true;
    }
}

void Component::LoadImpl()
{
}

void Component::Unload()
{
    if (m_Loaded)
    {
        UnloadImpl();
        m_Loaded = false;
    }
}

void Component::UnloadImpl()
{
}

void Component::Update(float delta)
{
    UpdateImpl(delta);
}

void Component::UpdateImpl(float delta)
{
}

void Component::Render()
{
    RenderImpl();
}

void Component::RenderImpl()
{
}

void Component::ConfigLoad(JSON config)
{
    ConfigLoadImpl(config);
    m_ConfigLoaded = true;
}

void Component::ConfigLoadImpl(JSON config)
{
}