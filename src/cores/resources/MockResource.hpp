#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <utils/configuration/ConfigurableObject.hpp>
#include "IResource.hpp"

using namespace ntt;

class MockResource : public IResource
{
public:
    inline rid_t GetResourceID() const { return m_ResourceID; };
    inline void SetResourceID(rid_t id) { m_ResourceID = id; };

    inline const String &GetPath() const override { return m_Path; };
    inline void SetPath(const String &path) { m_Path = path; };

    MOCK_METHOD0(Load, void());
    MOCK_METHOD0(Unload, void());
    MOCK_METHOD(void, LoadConfigure, (ConfigurableObject & config), (override));

    inline ResourceType GetType() const override { return ResourceType::IMAGE; };
    inline String ResourceName() const override { return "Image"; };

private:
    rid_t m_ResourceID;
    String m_Path;
};