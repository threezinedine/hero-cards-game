#include "ComponentManagement.hpp"
#include "Component.hpp"
#include "utils/utils.hpp"

namespace ntt
{
    ComponentManagement::ComponentManagement(String sceneName)
        : m_SceneName(sceneName)
    {
    }

    ComponentManagement::~ComponentManagement()
    {
    }

    void ComponentManagement::Load()
    {
        Configure(Config::GetSceneData(m_SceneName));
    }

    void ComponentManagement::Update(float delta)
    {
        for (auto &component : m_Components)
        {
            component.second->Update(delta);
        }
    }

    void ComponentManagement::Render()
    {
        for (auto &component : m_Components)
        {
            component.second->Render();
        }
    }

    void ComponentManagement::Unload()
    {
        for (auto &component : m_Components)
        {
            component.second->Unload();
        }
    }

    void ComponentManagement::Configure(JSON config)
    {
        for (auto &component : m_Components)
        {
            if (config.contains(component.first))
            {
                component.second->ConfigLoad(config[component.first]);
            }
        }
    }

    void ComponentManagement::RegisterComponent(String name, Scope<Component> component)
    {
        m_Components[name] = std::move(component);
    }
}