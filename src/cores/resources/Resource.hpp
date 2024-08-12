#pragma once
#include <common.hpp>
#include <cores/ILoadable.hpp>
#include <utils/path/IPath.hpp>
#include "ResourceType.hpp"

namespace ntt
{
    class Resource : public ILoadable
    {
    public:
        Resource(rid_t id, Scope<IPath> path, ResourceType type);
        ~Resource();

        void Load() override;
        void Unload() override;

        inline bool IsLoaded() const { return m_Loaded; }
        inline rid_t GetResourceID() const { return m_ResourceID; }
        inline String GetPath() const { return m_Path->Get(); }
        inline ResourceType GetType() const { return m_Type; }
        virtual String ResourceName() const = 0;

        bool IsValid() const { return m_ResourceID != INVALID_RID; }

        void LoadConfigure(JSON config);

    protected:
        virtual void LoadImpl();
        virtual void UnloadImpl();

        inline rid_t &GetResourceIDRef() { return m_ResourceID; }

    private:
        bool m_Loaded = false;
        rid_t m_ResourceID;
        Scope<IPath> m_Path;
        ResourceType m_Type;
    };
} // namespace ntt
