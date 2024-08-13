#include "HoverCheckScript.hpp"
#include <renderer/renderer.hpp>

namespace ntt
{
    HoverCheckScript::HoverCheckScript(sid_t scriptId)
        : Script(scriptId)
    {
    }

    void HoverCheckScript::UpdateImpl(float delta)
    {
        auto mousePos = renderer::GetMousePosition();
        std::cout << "Mouse position: (" << mousePos.x * m_Factor
                  << ", " << mousePos.y * m_Factor << ")" << std::endl;
    }

    void HoverCheckScript::LoadConfigureImpl(JSON config)
    {
        DEBUG_POINT();
        if (config.contains("factor") && config["factor"].is_number())
        {
            DEBUG_POINT();
            m_Factor = config["factor"];
        }
    }
} // namespace ntt
