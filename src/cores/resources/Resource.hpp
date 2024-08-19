#pragma once
#include <cores/commons/common.hpp>
#include <utils/path/IPath.hpp>
#include "ResourceType.hpp"
#include "IResource.hpp"

namespace ntt
{
    class Resource : public IResource
    {
    public:
        Resource(rid_t id, Scope<IPath> path, ResourceType type);
        ~Resource();

        void Load() override;
        void Unload() override;

        inline rid_t GetResourceID() const override { return m_ResourceID; }
        inline String GetPath() const override { return m_Path->Get(); }
        inline ResourceType GetType() const override { return m_Type; }

        void LoadConfigure(JSON config) override;

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
