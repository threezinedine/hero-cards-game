#pragma once
#include <cores/commons/common.hpp>
#include <cores/core.hpp>

using namespace ntt;

class Button : public Entity
{
public:
    Button(eid_t entityId, rid_t resourceId);
    virtual ~Button();

    inline void SetOnClicked(std::function<void()> onClicked) { m_OnClicked = onClicked; }

protected:
    void LoadConfigureImpl(JSON config) override;
    void LoadImpl() override;
    void UpdateImpl(float delta) override;
    void RenderImpl() override;

    void OnIdle();
    void OnHover();
    void OnPressed();

    void HandleClick();

    bool IsHovered();
    bool IsLeftPressed();

private:
    unsigned int m_ResourceId;
    Size m_ResourceSize;
    Size m_FrameSize;

    unsigned int m_NumCols;
    unsigned int m_NumRows;

    unsigned int m_CurrentColIndex;
    unsigned int m_CurrentRowIndex;

    float m_ChangePerSecond;

    std::function<void()> m_OnClicked = []() {};
};