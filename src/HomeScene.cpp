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
    LoadData();

    m_StartButton = CreateScope<Button>(ResourcePath(m_ImgPath), m_Pos, m_Size);
    m_StartButton->BindOnClicked(std::bind(&OnClickedStartButton, this));
}

void HomeScene::LoadData()
{
    auto config = Config::GetSceneData(0);
    m_ImgPath = "images/button.png";
    m_Pos = Vector2{0, 0};
    m_Size = Vector2{800, 600};

    if (config.contains("button"))
    {
        auto button = config["button"];

        if (button.contains("path"))
        {
            m_ImgPath = button["path"].get<String>();
        }

        if (button.contains("position") &&
            button["position"].contains("x") &&
            button["position"]["x"].is_number() &&
            button["position"].contains("y") &&
            button["position"]["y"].is_number())
        {
            auto pos = button["position"];
            m_Pos = Vector2{button["position"]["x"].get<float>(),
                            button["position"]["y"].get<float>()};
        }

        if (button.contains("size") &&
            button["size"].contains("width") &&
            button["size"]["width"].is_number())
        {
            float width = button["size"]["width"].get<float>();
            m_Size = Vector2{width, width};
        }
    }
}

void HomeScene::OnClickedStartButton()
{
    static_cast<Game *>(GetApp())->ChangeScene(1);
}

void HomeScene::UpdateImpl(float delta)
{
    m_StartButton->Update();
}

void HomeScene::RenderImpl()
{
    m_StartButton->Draw();
}

void HomeScene::ReleaseImpl()
{
}