#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ResourceManager.hpp"
#include "IResource.hpp"
#include "MockResource.hpp"

using namespace ntt;

class ResourceManagerTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        m_ResourceManager = CreateScope<ResourceManager>();

        m_Resource = CreateRef<MockResource>();
        m_Resource->SetResourceID(1);
    }

    Ref<MockResource> m_Resource;
    Scope<ResourceManager> m_ResourceManager;
};

TEST_F(ResourceManagerTest, AddResource)
{
    EXPECT_CALL(*m_Resource, Load()).Times(0);
    EXPECT_CALL(*m_Resource, Unload()).Times(0);
    m_ResourceManager->AddResource(m_Resource);
}

TEST_F(ResourceManagerTest, GetResource)
{
    EXPECT_CALL(*m_Resource, Load()).Times(1);
    EXPECT_CALL(*m_Resource, Unload()).Times(1);
    m_ResourceManager->AddResource(m_Resource);

    m_ResourceManager->Load();
    m_ResourceManager->Unload();
}