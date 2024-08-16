#include "Button.hpp"
#include "renderer/renderer.hpp"
#include <cores/scripts/defaults/defaults.hpp>

#define BIND(x) std::bind(&Button::x, this)

Button::Button(eid_t entityId)
    : Entity(entityId), m_Texture(0)
{
    auto fsm = CreateScope<FSMScript>(2);

    auto state = CreateRef<FSMState>("button");

    auto idle = CreateRef<FSMState>("idle");
    auto hover = CreateRef<FSMState>("hover");
    auto hoverIdle = CreateRef<FSMState>("hoverIdle");
    auto pressed = CreateRef<FSMState>("pressed");

    std::function<void()> Update = [this]()
    {
        this->m_Texture.Render();
    };

    std::function<bool()> IsLeftPressed = []()
    {
        return renderer::IsMouseButtonPressed(renderer::MouseButton::LEFT);
    };

    idle->SetOnState(Update);
    idle->AddTransition({BIND(IsHovered), hover});
    idle->SetOnEnter([this]()
                     { this->m_Texture.SetRowIndex(0); });

    hover->AddTransition({BIND(IsHovered), idle, true});
    hover->SetOnEnter([this]()
                      { this->m_Texture.SetRowIndex(1); });
    hover->SetOnState(Update);

    hoverIdle->AddTransition({IsLeftPressed, pressed});
    hoverIdle->SetOnEnter([this]()
                          { this->m_Texture.SetRowIndex(1); });

    pressed->SetOnEnter([this]()
                        { this->m_Texture.SetRowIndex(2); });
    pressed->AddTransition({IsLeftPressed, hoverIdle, true});
    pressed->SetOnExit([this]()
                       { 
                        if (this->IsHovered()) {
                            this->HandleClick();
                       } });

    pressed->SetOnState(Update);

    hover->SetState(hoverIdle);

    state->SetState(idle);
    fsm->SetState(state);

    AddScript(std::move(fsm));
}

Button::~Button()
{
}

void Button::LoadConfigureImpl(JSON config)
{
    if (config.contains("rid") && config["rid"].is_number_unsigned())
    {
        m_Texture.SetResourceId(config["rid"]);
    }

    if (config.contains("grid") && config["grid"].is_object())
    {
        auto gridCfg = config["grid"];
        if (gridCfg.contains("numCols") && gridCfg["numCols"].is_number_unsigned())
        {
            m_Texture.SetNumCols(gridCfg["numCols"]);
        }

        if (gridCfg.contains("numRows") && gridCfg["numRows"].is_number_unsigned())
        {
            m_Texture.SetNumRows(gridCfg["numRows"]);
        }
    }
}

void Button::LoadImpl()
{
    m_Texture.SetGeometry(GetGeometry());
    m_Texture.Load();
}

void Button::UpdateImpl(float delta)
{
}

bool Button::IsHovered()
{
    auto mouse = renderer::GetMousePosition();
    auto pos = GetGeometry()->GetPoint();
    auto size = GetGeometry()->GetSize();

    return mouse.x >= pos.x - size.width / 2 && mouse.x <= pos.x + size.width / 2 &&
           mouse.y >= pos.y - size.height / 2 && mouse.y <= pos.y + size.height / 2;
}

void Button::HandleClick()
{
    m_OnClicked();
}