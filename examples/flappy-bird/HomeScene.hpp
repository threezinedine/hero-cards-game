#pragma once
#include <NTTEngine.hpp>

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
};