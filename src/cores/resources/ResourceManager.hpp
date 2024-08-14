#pragma once
#include <cores/commons/common.hpp>
#include <cores/commons/datatypes.hpp>
#include <cores/interfaces/Loadable.hpp>
#include <cores/interfaces/IConfigurable.hpp>
#include "Resource.hpp"

namespace ntt
{
    class ResourceManager : public Loadable, public IConfigurable
    {
    public:
        ResourceManager(const String &sceneName);
        ~ResourceManager();

        void AddResource(Scope<Resource> resource);
        void Load() override;
        void Unload() override;

        void LoadConfigure(JSON config) override;

    private:
        Map<rid_t, Scope<Resource>> m_Resources;
        String m_SceneName;
    };
} // namespace ntt
