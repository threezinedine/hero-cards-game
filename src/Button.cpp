#include "Button.hpp"
#include "renderer/renderer.hpp"
#include <cores/scripts/defaults/defaults.hpp>

#define BIND(x) std::bind(&Button::x, this)

Button::Button(eid_t entityId, rid_t resourceId)
    : Entity(entityId), m_ResourceId(m_ResourceId),
      m_NumCols(1), m_NumRows(3),
      m_CurrentColIndex(0), m_CurrentRowIndex(0),
      m_ChangePerSecond(1)
{
    auto fsm = CreateScope<FSMScript>(2);

    auto state = CreateRef<FSMState>("button");

    auto idle = CreateRef<FSMState>("idle");
    auto hover = CreateRef<FSMState>("hover");
    auto hoverIdle = CreateRef<FSMState>("hoverIdle");
    auto pressed = CreateRef<FSMState>("pressed");

    idle->SetOnState(BIND(OnIdle));
    idle->AddTransition({BIND(IsHovered), hover});

    hover->AddTransition({BIND(IsHovered), idle, true});
    hover->SetOnState(BIND(OnHover));

    hoverIdle->AddTransition({BIND(IsLeftPressed), pressed});
    pressed->AddTransition({BIND(IsLeftPressed), hoverIdle, true});
    pressed->SetOnExit(BIND(HandleClick));

    pressed->SetOnState(BIND(OnPressed));

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
        m_ResourceId = config["rid"];
    }

    if (config.contains("grid") && config["grid"].is_object())
    {
        auto gridCfg = config["grid"];
        if (gridCfg.contains("numCols") && gridCfg["numCols"].is_number_unsigned())
        {
            m_NumCols = gridCfg["numCols"];
        }

        if (gridCfg.contains("numRows") && gridCfg["numRows"].is_number_unsigned())
        {
            m_NumRows = gridCfg["numRows"];
        }
    }

    if (config.contains("changePerSecond") && config["changePerSecond"].is_number())
    {
        m_ChangePerSecond = config["changePerSecond"];
    }
}

void Button::LoadImpl()
{
    auto textureSize = renderer::GetTextureSize(m_ResourceId);

    m_ResourceSize.width = textureSize.width;
    m_ResourceSize.height = textureSize.height;

    m_FrameSize.width = m_ResourceSize.width / m_NumCols;
    m_FrameSize.height = m_ResourceSize.height / m_NumRows;

    auto width = GetGeometry().GetSize().width;
    GetGeometry().GetSize().height = m_FrameSize.height / m_FrameSize.width * width;
}

void Button::UpdateImpl(float delta)
{

    renderer::DrawTexture(
        m_ResourceId,
        {m_FrameSize.width * m_CurrentColIndex, m_FrameSize.height * m_CurrentRowIndex},
        m_FrameSize,
        GetGeometry().GetPoint(),
        GetGeometry().GetSize());
}

void Button::RenderImpl()
{
}

bool Button::IsHovered()
{
    auto mouse = renderer::GetMousePosition();
    auto pos = GetGeometry().GetPoint();
    auto size = GetGeometry().GetSize();

    bool res = mouse.x >= pos.x - size.width / 2 && mouse.x <= pos.x + size.width / 2 &&
               mouse.y >= pos.y - size.height / 2 && mouse.y <= pos.y + size.height / 2;

    return res;
}

bool Button::IsLeftPressed()
{
    return renderer::IsMouseButtonPressed(renderer::MouseButton::LEFT);
}

void Button::OnIdle()
{
    m_CurrentColIndex = 0;
    m_CurrentRowIndex = 0;
}

void Button::OnHover()
{
    m_CurrentColIndex = 0;
    m_CurrentRowIndex = 1;
}

void Button::HandleClick()
{
    m_OnClicked();
}

void Button::OnPressed()
{
    m_CurrentColIndex = 0;
    m_CurrentRowIndex = 2;
}