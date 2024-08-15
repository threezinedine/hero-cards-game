#pragma once
#include <cores/commons/common.hpp>
#include <cores/core.hpp>

using namespace ntt;

class Button : public Entity
{
public:
    Button(eid_t entityId);
    virtual ~Button();

    inline void SetOnClicked(const std::function<void()> &onClicked)
    {
        m_OnClicked = onClicked;
    }

protected:
    void LoadConfigureImpl(JSON config) override;
    void LoadImpl() override;
    void UpdateImpl(float delta) override;

    void HandleClick();

    bool IsHovered();

private:
    Texture m_Texture;
    std::function<void()> m_OnClicked = []() {};
};