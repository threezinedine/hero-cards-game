#include "HoverCheckScript.hpp"
#include <renderer/renderer.hpp>

namespace ntt
{
    HoverCheckScript::HoverCheckScript(sid_t scriptId)
        : Script(scriptId)
    {
    }

    void HoverCheckScript::UpdateImpl(void *sender, float delta)
    {
        auto mousePos = renderer::GetMousePosition();
        std::cout << "Mouse position: (" << mousePos.x * m_Factor
                  << ", " << mousePos.y * m_Factor << ")" << std::endl;
    }

    void HoverCheckScript::LoadConfigureImpl(ConfigurableObject &config)
    {
        m_Factor = config.Get<float>("factor", m_Factor);
    }
} // namespace ntt
