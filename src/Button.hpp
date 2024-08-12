#pragma once
#include <common.hpp>
#include <cores/core.hpp>

using namespace ntt;

class Button : public Entity
{
public:
    Button(eid_t entityId, rid_t resourceId);
    virtual ~Button();

protected:
    void UpdateImpl(float delta) override;
    void RenderImpl() override;
};