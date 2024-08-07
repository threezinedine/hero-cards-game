#include "MouseInput.hpp"

MouseInput *MouseInput::s_Instance = nullptr;

void MouseInput::Update()
{
    m_MousePosition = GetMousePosition();
}

void MouseInput::Initialize()
{
    s_Instance = new MouseInput();
}

MouseInput *MouseInput::Get()
{
    return s_Instance;
}

void MouseInput::Release()
{
    delete s_Instance;
    s_Instance = nullptr;
}