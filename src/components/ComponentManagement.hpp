#pragma once
#include <common.hpp>
#include <cores/core.hpp>

namespace ntt
{
    class Component;

    class ComponentManagement : public IRenderable
    {
    public:
        ComponentManagement(String sceneName);
        ~ComponentManagement();

        void Load();
        void Update(float delta) override;
        void Render() override;
        void Unload();

        void Configure(JSON config);

        void RegisterComponent(String componentName, Scope<Component> component);

    protected:
    private:
        String m_SceneName;
        Map<String, Scope<Component>> m_Components;
    };
}