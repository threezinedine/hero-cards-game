#pragma once
#include <cores/core.hpp>
#include <common.hpp>
#include <components/components.hpp>

class HomeScene : public Scene
{
public:
    HomeScene();
    virtual ~HomeScene();

protected:
    void InitImpl() override;
    void UpdateImpl(float delta) override;
    void RenderImpl() override;
    void ReleaseImpl() override;

    void LoadData();
    void OnClickedStartButton();

private:
    Scope<Button> m_StartButton = nullptr;
};