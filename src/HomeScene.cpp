#include "HomeScene.hpp"
#include <utils/utils.hpp>
#include "Game.hpp"

HomeScene::HomeScene()
    : Scene("home")
{
    m_StartButton = CreateScope<Button>(
        CreateScope<ResourcePath>("images/button.png"), 0, 0, 100,
        std::bind(&HomeScene::OnClickedStartButton, this));

    m_ComponentManagement->RegisterComponent("button", std::move(m_StartButton));

    m_MenuButton = CreateScope<Sprite>(
        CreateScope<ResourcePath>("images/new-btn.png"), 1, 2, 500);
    m_ComponentManagement->RegisterComponent("menu", std::move(m_MenuButton));
}

HomeScene::~HomeScene()
{
}

void HomeScene::InitImpl()
{
}

void HomeScene::OnClickedStartButton()
{
    GetSceneManagement()->ChangeScene(1);
}

void HomeScene::UpdateImpl(float delta)
{
}

void HomeScene::RenderImpl()
{
}

void HomeScene::ReleaseImpl()
{
}