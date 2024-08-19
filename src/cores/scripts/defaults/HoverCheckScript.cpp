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

    void HoverCheckScript::LoadConfigureImpl(JSON config)
    {
        if (config.contains("factor") && config["factor"].is_number())
        {
            m_Factor = config["factor"];
        }
    }
} // namespace ntt
