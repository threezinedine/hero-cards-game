#include "HomeScene.hpp"
#include <utils/utils.hpp>
#include "Game.hpp"

HomeScene::HomeScene()
{
}

HomeScene::~HomeScene()
{
}

void HomeScene::InitImpl()
{

    m_StartButton = CreateScope<Button>(
        CreateScope<ResourcePath>("images/button.png"), 0, 0, 100);
    m_StartButton->ConfigLoad(Config::GetSceneData(0)["button"]);
    m_StartButton->BindOnClicked(std::bind(&OnClickedStartButton, this));
    m_StartButton->Load();

    m_MenuButton = CreateScope<Sprite>(
        CreateScope<ResourcePath>("images/new-btn.png"), 1, 2, 500);
    m_MenuButton->SetPosX(200);
    m_MenuButton->SetPosY(200);
    m_MenuButton->SetWidth(300);
    m_MenuButton->Load();
}

void HomeScene::OnClickedStartButton()
{
    GetSceneManagement()->ChangeScene(1);
}

void HomeScene::UpdateImpl(float delta)
{
    m_StartButton->Update(delta);
    m_MenuButton->Update(delta);
}

void HomeScene::RenderImpl()
{
    m_StartButton->Render();
    m_MenuButton->Render();
}

void HomeScene::ReleaseImpl()
{
    m_StartButton->Unload();
    m_MenuButton->Unload();
}