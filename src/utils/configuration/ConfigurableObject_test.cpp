#include <gtest/gtest.h>
#include "ConfigurableObject.hpp"
#include <utils/files/files.hpp>
#include <utils/log/log.hpp>

using namespace ntt;

class ConfigObjectTest : public ::testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        String m_Data = R"({
            "speed": 23.5,
            "shipCount": 18,
            "negative": -1,
            "title": "Hello world",
            "active": false,
            "fibonacci": [1, 1, 2, 3, 5, 7],
            "urls": ["http://google.com", "http://facebook.com"],
            "speeds": [23.5, 24.5, 25.5],
            "actives": [true, false, true],
            "size": {
                "width": 800,
                "height": 600
            },
            "position": {
                "x": 32.3,
                "y": 45.6
            },
            "vocab": {
                "hello": "xin chao",
                "world": "the gioi",
                "goodbye": "tam biet"
            },
            "machines": {
                "machine1": true,
                "machine2": false,
                "machine3": true
            },
            "nonPureIntList": [1, "Hello", 3],
            "nonPureFloatList": [1.0, "Hello", 3.0],
            "nonPureBoolList": [true, "Hello", false],
            "nonPureStringList": ["Hello", 1, "World"],
            "nonPureIntMap": {
                "key1": 1,
                "key2": "Hello",
                "key3": 3
            },
            "nonPureFloatMap": {
                "key1": 1.0,
                "key2": "Hello",
                "key3": 3.0
            },
            "nonPureBoolMap": {
                "key1": true,
                "key2": "Hello",
                "key3": false
            },
            "nonPureStringMap": {
                "key1": 1,
                "key2": "Hello",
                "key3": "World"
            },
            "object": {
                "height": 100,
                "width": 200
            },
            "scenes": [
                {
                    "name": "Scene1",
                    "id": 1
                },
                {
                    "name": "Scene2",
                    "id": 2
                },
                {
                    "name": "Scene3",
                    "id": 3
                }
            ],
            "resources": {
                "texture": {
                    "path": "res/texture.png",
                    "filter": "linear"
                },
                "sound": {
                    "path": "res/sound.wav",
                    "volume": 0.5
                }
            }
        })";
        CreateFile("config.json", m_Data);
    }

    void SetUp() override
    {
        m_ConfigObject.FromFile("config.json");
    }

    void TearDown() override
    {
    }

    ConfigurableObject m_ConfigObject;
};

template <typename T>
static void AssertListEqual(List<T> src, List<T> dest)
{
    ASSERT_EQ(src.size(), dest.size());
    for (int i = 0; i < src.size(); i++)
    {
        EXPECT_EQ(src[i], dest[i]);
    }
}

template <typename T>
static void AssertMapEqual(Map<String, T> src, Map<String, T> dest)
{
    ASSERT_EQ(src.size(), dest.size());
    for (auto &pair : src)
    {
        EXPECT_EQ(pair.second, dest[pair.first]);
    }
}

TEST_F(ConfigObjectTest, WhenGet_ThenReturnValue)
{
    // Get without default value assigned
    EXPECT_EQ(m_ConfigObject.Get<float>("speed"), 23.5f);
    EXPECT_EQ(m_ConfigObject.Get<String>("title"), "Hello world");
    EXPECT_EQ(m_ConfigObject.Get<int>("shipCount"), 18);
    EXPECT_EQ(m_ConfigObject.Get<bool>("active"), false);
    EXPECT_EQ(m_ConfigObject.Get<int>("negative"), -1);

    // Get with default value assigned
    EXPECT_EQ(m_ConfigObject.Get<float>("speed", 0.0f), 23.5f);
    EXPECT_EQ(m_ConfigObject.Get<String>("title", ""), "Hello world");
    EXPECT_EQ(m_ConfigObject.Get<int>("shipCount", 0), 18);
    EXPECT_EQ(m_ConfigObject.Get<bool>("active", true), false);
    EXPECT_EQ(m_ConfigObject.Get<int>("negative", 0), -1);

    // Can get int from float
    EXPECT_EQ(m_ConfigObject.Get<int>("speed"), 23);

    // Can get float from int
    EXPECT_EQ(m_ConfigObject.Get<float>("shipCount"), 18.0f);

    // Get configured object
    auto object = m_ConfigObject.Get<ConfigurableObject>("object");

    EXPECT_EQ(object.Get<int>("height"), 100);
    EXPECT_EQ(object.Get<int>("width"), 200);
}

TEST_F(ConfigObjectTest, WhenGetNonExistedKey_ThenReturnDefault)
{
    // Get without default value assigned
    EXPECT_EQ(m_ConfigObject.Get<int>("nonExistedKey"), 0);
    EXPECT_EQ(m_ConfigObject.Get<String>("nonExistedKey"), "");
    EXPECT_EQ(m_ConfigObject.Get<float>("nonExistedKey"), 0.0f);
    EXPECT_EQ(m_ConfigObject.Get<bool>("nonExistedKey"), false);

    // Get with non-existed key and default value assigned
    EXPECT_EQ(m_ConfigObject.Get<int>("nonExistedKey", 3), 3);
    EXPECT_EQ(m_ConfigObject.Get<String>("nonExistedKey", "default"), "default");
    EXPECT_EQ(m_ConfigObject.Get<float>("nonExistedKey", 0.0f), 0.0f);
    EXPECT_EQ(m_ConfigObject.Get<bool>("nonExistedKey", true), true);

    // Get configure object with non-existed key
    auto object = m_ConfigObject.Get<ConfigurableObject>("nonExistedKey");

    EXPECT_EQ(object.Get<int>("height"), 0);
}

TEST_F(ConfigObjectTest, WhenGetExistedKeyWithWrongType_ThenReturnDefault)
{
    // Get without default value assigned
    EXPECT_EQ(m_ConfigObject.Get<String>("speed"), "");
    EXPECT_EQ(m_ConfigObject.Get<int>("title"), 0);
    EXPECT_EQ(m_ConfigObject.Get<float>("active"), 0.0f);
    EXPECT_EQ(m_ConfigObject.Get<bool>("shipCount"), false);
    EXPECT_EQ(m_ConfigObject.Get<bool>("speed"), false);
    EXPECT_EQ(m_ConfigObject.Get<int>("active"), 0);
    EXPECT_EQ(m_ConfigObject.Get<String>("shipCount"), "");
    EXPECT_EQ(m_ConfigObject.Get<unsigned int>("negative"), 0);

    // Get with default value assigned
    EXPECT_EQ(m_ConfigObject.Get<String>("speed", "default"), "default");
    EXPECT_EQ(m_ConfigObject.Get<int>("title", 3), 3);
    EXPECT_EQ(m_ConfigObject.Get<float>("active", 0.0f), 0.0f);
    EXPECT_EQ(m_ConfigObject.Get<bool>("shipCount", true), true);
    EXPECT_EQ(m_ConfigObject.Get<bool>("speed", true), true);
    EXPECT_EQ(m_ConfigObject.Get<int>("active", 3), 3);
    EXPECT_EQ(m_ConfigObject.Get<String>("shipCount", "default"), "default");
    EXPECT_EQ(m_ConfigObject.Get<unsigned int>("negative", 3), 3);

    // when get the configurable object with wrong type
    auto object = m_ConfigObject.Get<ConfigurableObject>("speed");

    EXPECT_EQ(object.Get<int>("height"), 0);
}

TEST_F(ConfigObjectTest, WhenGetList_ThenReturnList)
{
    AssertListEqual<int>(
        m_ConfigObject.GetList<int>("fibonacci"),
        List<int>({1, 1, 2, 3, 5, 7}));

    AssertListEqual<String>(
        m_ConfigObject.GetList<String>("urls"),
        List<String>({"http://google.com", "http://facebook.com"}));

    AssertListEqual<float>(
        m_ConfigObject.GetList<float>("speeds"),
        List<float>({23.5, 24.5, 25.5}));

    AssertListEqual<bool>(
        m_ConfigObject.GetList<bool>("actives"),
        List<bool>({true, false, true}));

    // Can get int list from float list
    AssertListEqual<int>(
        m_ConfigObject.GetList<int>("speeds"),
        List<int>({23, 24, 25}));

    // Can get float list from int list
    AssertListEqual<float>(
        m_ConfigObject.GetList<float>("fibonacci"),
        List<float>({1.0f, 1.0f, 2.0f, 3.0f, 5.0f, 7.0f}));

    // Remove all non pure int from int list
    AssertListEqual<int>(
        m_ConfigObject.GetList<int>("nonPureIntList"),
        List<int>({1, 3}));

    // Remove all non pure float from float list
    AssertListEqual<float>(
        m_ConfigObject.GetList<float>("nonPureFloatList"),
        List<float>({1.0f, 3.0f}));

    // Remove all non pure bool from bool list
    AssertListEqual<bool>(
        m_ConfigObject.GetList<bool>("nonPureBoolList"),
        List<bool>({true, false}));

    // Remove all non pure string from string list
    AssertListEqual<String>(
        m_ConfigObject.GetList<String>("nonPureStringList"),
        List<String>({"Hello", "World"}));
}

TEST_F(ConfigObjectTest, WhenGetListWithNonExistedKey_ThenReturnEmptyList)
{
    AssertListEqual<int>(
        m_ConfigObject.GetList<int>("nonExistedKey"),
        List<int>());

    AssertListEqual<String>(
        m_ConfigObject.GetList<String>("nonExistedKey"),
        List<String>());

    AssertListEqual<float>(
        m_ConfigObject.GetList<float>("nonExistedKey"),
        List<float>());

    AssertListEqual<bool>(
        m_ConfigObject.GetList<bool>("nonExistedKey"),
        List<bool>());
}

TEST_F(ConfigObjectTest, WhenGetListWithWrongType_ThenReturnEmptyList)
{
    AssertListEqual<int>(
        m_ConfigObject.GetList<int>("title"),
        List<int>());

    AssertListEqual<String>(
        m_ConfigObject.GetList<String>("active"),
        List<String>());

    AssertListEqual<float>(
        m_ConfigObject.GetList<float>("shipCount"),
        List<float>());

    AssertListEqual<bool>(
        m_ConfigObject.GetList<bool>("speed"),
        List<bool>());
}

TEST_F(ConfigObjectTest, WhenGetListObject_ThenReturnConfigObjectList)
{
    auto scenes = m_ConfigObject.GetList<ConfigurableObject>("scenes");
    ASSERT_EQ(scenes.size(), 3);

    EXPECT_EQ(scenes[0].Get<String>("name"), "Scene1");
    EXPECT_EQ(scenes[0].Get<int>("id"), 1);

    EXPECT_EQ(scenes[1].Get<String>("name"), "Scene2");
    EXPECT_EQ(scenes[1].Get<int>("id"), 2);

    EXPECT_EQ(scenes[2].Get<String>("name"), "Scene3");
    EXPECT_EQ(scenes[2].Get<int>("id"), 3);
}

TEST_F(ConfigObjectTest, WhenGetListObjectWithNonExistedKey_ThenReturnEmptyList)
{
    auto scenes = m_ConfigObject.GetList<ConfigurableObject>("nonExistedKey");
    ASSERT_EQ(scenes.size(), 0);
}

TEST_F(ConfigObjectTest, WhenGetListObjectWithWrongType_ThenReturnEmptyList)
{
    EXPECT_EQ(m_ConfigObject.GetList<ConfigurableObject>("title").size(), 0);
    EXPECT_EQ(m_ConfigObject.GetList<ConfigurableObject>("active").size(), 0);
    EXPECT_EQ(m_ConfigObject.GetList<ConfigurableObject>("speeds").size(), 0);
    EXPECT_EQ(m_ConfigObject.GetList<ConfigurableObject>("resources").size(), 0);
}

TEST_F(ConfigObjectTest, WhenGetMap_ThenReturnMap)
{
    AssertMapEqual<int>(
        m_ConfigObject.GetMap<int>("size"),
        Map<String, int>({{"width", 800}, {"height", 600}}));

    AssertMapEqual<float>(
        m_ConfigObject.GetMap<float>("position"),
        Map<String, float>({{"x", 32.3f}, {"y", 45.6f}}));

    AssertMapEqual<String>(
        m_ConfigObject.GetMap<String>("vocab"),
        Map<String, String>({{"hello", "xin chao"},
                             {"world", "the gioi"},
                             {"goodbye", "tam biet"}}));

    AssertMapEqual<bool>(
        m_ConfigObject.GetMap<bool>("machines"),
        Map<String, bool>({{"machine1", true},
                           {"machine2", false},
                           {"machine3", true}}));

    // Can get int map from float map
    AssertMapEqual<int>(
        m_ConfigObject.GetMap<int>("position"),
        Map<String, int>({{"x", 32}, {"y", 45}}));

    // Can get float map from int map
    AssertMapEqual<float>(
        m_ConfigObject.GetMap<float>("size"),
        Map<String, float>({{"width", 800.0f}, {"height", 600.0f}}));

    // Remove all non pure value from map
    AssertMapEqual<int>(
        m_ConfigObject.GetMap<int>("nonPureIntMap"),
        Map<String, int>({{"key1", 1}, {"key3", 3}}));

    AssertMapEqual<float>(
        m_ConfigObject.GetMap<float>("nonPureFloatMap"),
        Map<String, float>({{"key1", 1.0f}, {"key3", 3.0f}}));

    AssertMapEqual<bool>(
        m_ConfigObject.GetMap<bool>("nonPureBoolMap"),
        Map<String, bool>({{"key1", true}, {"key3", false}}));

    AssertMapEqual<String>(
        m_ConfigObject.GetMap<String>("nonPureStringMap"),
        Map<String, String>({{"key2", "Hello"}, {"key3", "World"}}));
}

TEST_F(ConfigObjectTest, WhenGetMapWithNonExistedKey_ThenReturnEmptyMap)
{
    AssertMapEqual<int>(
        m_ConfigObject.GetMap<int>("nonExistedKey"),
        Map<String, int>());

    AssertMapEqual<String>(
        m_ConfigObject.GetMap<String>("nonExistedKey"),
        Map<String, String>());

    AssertMapEqual<float>(
        m_ConfigObject.GetMap<float>("nonExistedKey"),
        Map<String, float>());

    AssertMapEqual<bool>(
        m_ConfigObject.GetMap<bool>("nonExistedKey"),
        Map<String, bool>());
}

TEST_F(ConfigObjectTest, WhenGetMapWithWrongType_ThenReturnEmptyMap)
{
    AssertMapEqual<int>(
        m_ConfigObject.GetMap<int>("title"),
        Map<String, int>());

    AssertMapEqual<String>(
        m_ConfigObject.GetMap<String>("active"),
        Map<String, String>());

    AssertMapEqual<bool>(
        m_ConfigObject.GetMap<bool>("speed"),
        Map<String, bool>());
}

TEST_F(ConfigObjectTest, WhenGetMapObject_ThenReturnMap)
{
    auto resources = m_ConfigObject.GetMap<ConfigurableObject>("resources");
    ASSERT_EQ(resources.size(), 2);

    EXPECT_EQ(resources["texture"].Get<String>("path"), "res/texture.png");
    EXPECT_EQ(resources["texture"].Get<String>("filter"), "linear");

    EXPECT_EQ(resources["sound"].Get<String>("path"), "res/sound.wav");
    EXPECT_EQ(resources["sound"].Get<float>("volume"), 0.5f);
}

TEST_F(ConfigObjectTest, WhenGetMapObjectWithNonExistedKey_ThenReturnEmptyMap)
{
    auto resources = m_ConfigObject.GetMap<ConfigurableObject>("nonExistedKey");
    ASSERT_EQ(resources.size(), 0);
}

TEST_F(ConfigObjectTest, WhenGetMapObjectWithWrongType_ThenReturnEmptyMap)
{
    EXPECT_EQ(m_ConfigObject.GetMap<ConfigurableObject>("title").size(), 0);
    EXPECT_EQ(m_ConfigObject.GetMap<ConfigurableObject>("active").size(), 0);
    EXPECT_EQ(m_ConfigObject.GetMap<ConfigurableObject>("scenes").size(), 0);
}