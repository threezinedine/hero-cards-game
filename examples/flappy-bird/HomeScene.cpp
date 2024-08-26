#include "HomeScene.hpp"
#include "Button.hpp"

#define BIND(fn) std::bind(&HomeScene::fn, this)

HomeScene::HomeScene()
    : Scene("home")
{
    // auto button = CreateScope<Button>(0);
    // button->SetOnClicked([this]()
    //                      { GetSceneManager()->ChangeScene("game"); });
    // GetEntityManager()->AddEntity(std::move(button));

    auto sprite = CreateScope<Entity>(1);
    sprite->AddScript(CreateScope<SpriteScript>(3));

    GetEntityManager()->AddEntity(std::move(sprite));
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

void HomeScene::UnloadImpl()
{
}