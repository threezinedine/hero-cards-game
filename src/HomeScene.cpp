#include "HomeScene.hpp"
#include <utils/utils.hpp>
#include "Game.hpp"
#include <renderer/renderer.hpp>
#include "Button.hpp"
#include <cores/scripts/defaults/defaults.hpp>

HomeScene::HomeScene()
    : Scene("home")
{
    // m_StartButton = CreateScope<Button>(
    //     CreateScope<ResourcePath>("images/button.png"), 0, 0, 100,
    //     std::bind(&HomeScene::OnClickedStartButton, this));

    // m_ComponentManagement->RegisterComponent("button", std::move(m_StartButton));

    // m_MenuButton = CreateScope<Sprite>(
    //     CreateScope<ResourcePath>("images/new-btn.png"), 1, 2, 500);
    // m_ComponentManagement->RegisterComponent("menu", std::move(m_MenuButton));
    GetResourceManager()->AddResource(
        CreateScope<ImageResource>(
            0,
            CreateScope<ResourcePath>("images/button.png")));

    auto button = CreateScope<Button>(0, 0);
    // button->AddScript(CreateScope<HoverCheckScript>(23));
    button->AddScript(CreateScope<SpriteScript>(1));
    GetEntityManager()->AddEntity(std::move(button));
}

HomeScene::~HomeScene()
{
}

void HomeScene::LoadImpl()
{
    // m_Texture = renderer::LoadTexture(CreateScope<ResourcePath>("images/button.png"));
}

void HomeScene::OnClickedStartButton()
{
    // GetSceneManagement()->ChangeScene(1);
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