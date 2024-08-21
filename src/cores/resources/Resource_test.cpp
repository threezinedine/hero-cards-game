#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Resource.hpp"

using namespace ntt;

class MockResourceIns : public Resource
{
public:
    MockResourceIns(rid_t id)
        : Resource(id, "test", ResourceType::IMAGE)
    {
    }

    int m_LoadCount = 0;
    int m_UnloadCount = 0;

    inline String ResourceName() const override { return "Test"; }

protected:
    void LoadImpl() override
    {
        m_LoadCount++;
    }

    void UnloadImpl() override
    {
        m_UnloadCount++;
    }
};

class ResourceTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        m_Resource = CreateRef<MockResourceIns>(3);
    }

    Ref<MockResourceIns> m_Resource;
};

TEST_F(ResourceTest, Load)
{
    m_Resource->Load();

    EXPECT_TRUE(m_Resource->IsLoaded());
    EXPECT_EQ(m_Resource->m_LoadCount, 1);
}

TEST_F(ResourceTest, Unload)
{
    m_Resource->Load();
    m_Resource->Unload();

    EXPECT_FALSE(m_Resource->IsLoaded());
    EXPECT_EQ(m_Resource->m_UnloadCount, 1);
}