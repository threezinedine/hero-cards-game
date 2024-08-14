#pragma once
#include <cores/core.hpp>
#include <cores/commons/common.hpp>
// #include <components/components.hpp>

using namespace ntt;

class HomeScene : public Scene
{
public:
    HomeScene();
    virtual ~HomeScene();

protected:
    void LoadImpl() override;
    void UpdateImpl(float delta) override;
    void RenderImpl() override;
    void UnloadImpl() override;

    void LoadData();
    void OnClickedStartButton();

private:
    int m_Texture;
    // Scope<Button> m_StartButton = nullptr;
    // Scope<Sprite> m_MenuButton = nullptr;
};