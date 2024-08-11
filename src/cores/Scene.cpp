#include "Scene.hpp"
#include <components/ComponentManagement.hpp>
#include <utils/utils.hpp>

Scene::Scene(String sceneName)
    : m_SceneManagement(nullptr), m_SceneName(sceneName)
{
    m_ComponentManagement = CreateScope<ComponentManagement>(sceneName);
}

Scene::~Scene()
{
}

void Scene::Init()
{
    DEBUG_POINT();
    m_IsInitialized = true;
    DEBUG_POINT();
    m_ComponentManagement->Load();

    DEBUG_POINT();
    InitImpl();
    DEBUG_POINT();
}

void Scene::InitImpl()
{
}

void Scene::Update(float delta)
{
    UpdateImpl(delta);
    m_ComponentManagement->Update(delta);
}

void Scene::UpdateImpl(float delta)
{
}

void Scene::Render()
{
    RenderImpl();
    m_ComponentManagement->Render();
}

void Scene::RenderImpl()
{
}

void Scene::Release()
{
    m_ComponentManagement->Unload();
    ReleaseImpl();
    m_IsInitialized = false;
}

void Scene::ReleaseImpl()
{
}