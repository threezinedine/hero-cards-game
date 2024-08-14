#include "HomeScene.hpp"
#include <utils/utils.hpp>
#include "Game.hpp"
#include <renderer/renderer.hpp>
#include "Button.hpp"
#include <cores/scripts/defaults/defaults.hpp>

HomeScene::HomeScene()
    : Scene("home")
{
    // GetResourceManager()->AddResource(
    //     CreateScope<ImageResource>(
    //         0,
    //         CreateScope<ResourcePath>("images/button.png")));

    // GetResourceManager()->AddResource(
    //     CreateScope<ImageResource>(
    //         1,
    //         CreateScope<ResourcePath>("images/button.png")));

    auto button = CreateScope<Button>(0, 0);
    GetEntityManager()->AddEntity(std::move(button));
}

HomeScene::~HomeScene()
{
}

void HomeScene::LoadImpl()
{
}

void HomeScene::OnClickedStartButton()
{
}

void HomeScene::UpdateImpl(float delta)
{
}

void HomeScene::RenderImpl()
{
}

void HomeScene::UnloadImpl()
{
    // renderer::UnloadTexture(m_Texture);
}