#include "Scene.hpp"

Scene::Scene()
    : m_App(nullptr)
{
}

Scene::Scene(Application *app)
    : m_App(app)
{
}

Scene::~Scene()
{
}

void Scene::Init()
{
    m_IsInitialized = true;

    InitImpl();
}

void Scene::InitImpl()
{
}

void Scene::Update(float delta)
{
    UpdateImpl(delta);
}

void Scene::UpdateImpl(float delta)
{
}

void Scene::Render()
{
    RenderImpl();
}

void Scene::RenderImpl()
{
}

void Scene::Release()
{
    ReleaseImpl();
    m_IsInitialized = false;
}

void Scene::ReleaseImpl()
{
}