#include "HomeScene.hpp"
#include "Button.hpp"

#define BIND(fn) std::bind(&HomeScene::fn, this)

HomeScene::HomeScene()
    : Scene("home")
{
    auto button = CreateScope<Button>(0, 0);
    button->SetOnClicked([this]()
                         { GetSceneManager()->ChangeScene("game"); });
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
}