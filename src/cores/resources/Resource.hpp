#pragma once
#include <cores/commons/common.hpp>
#include <cores/interfaces/Loadable.hpp>
#include <utils/path/IPath.hpp>
#include "ResourceType.hpp"

namespace ntt
{
    class Resource : public Loadable
    {
    public:
        Resource(rid_t id, Scope<IPath> path, ResourceType type);
        ~Resource();

        void Load() override;
        void Unload() override;

        inline rid_t GetResourceID() const { return m_ResourceID; }
        inline String GetPath() const { return m_Path->Get(); }
        inline ResourceType GetType() const { return m_Type; }
        virtual String ResourceName() const = 0;

        bool IsValid() const { return m_ResourceID != INVALID_RID; }

        void LoadConfigure(JSON config);

    protected:
        virtual void LoadImpl();
        virtual void UnloadImpl();

        virtual void LoadConfigureImpl(JSON config);

        inline rid_t &GetResourceIDRef()
        {
            return m_ResourceID;
        }

    private:
        rid_t m_ResourceID;
        Scope<IPath> m_Path;
        ResourceType m_Type;
    };
} // namespace ntt
