#include "Script.hpp"

namespace ntt
{
    Script::Script()
    {
    }

    Script::~Script()
    {
    }

    void Script::Update(Component *sender, void *data)
    {
        UpdateImpl(sender, data);
    }

    void Script::UpdateImpl(Component *sender, void *data)
    {
    }
} // namespace ntt
