#include "Button.hpp"
#include "renderer/renderer.hpp"

Button::Button(eid_t entityId, rid_t resourceId)
    : Entity(entityId, resourceId)
{
}

Button::~Button()
{
}

void Button::UpdateImpl(float delta)
{
}

void Button::RenderImpl()
{
    // PRINT("Position: (%f, %f)\n", GetGeometry().GetPoint().x, GetGeometry().GetPoint().y);
    // PRINT("Size: (%f, %f)\n", GetGeometry().GetSize().width, GetGeometry().GetSize().height);
    renderer::DrawTexture(GetResourceID(), GetGeometry().GetPoint(), GetGeometry().GetSize());
}