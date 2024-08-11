#pragma once
#include <common.hpp>
#include <cores/core.hpp>

namespace ntt
{
    class Component : public IRenderable
    {
    public:
        Component(float posX = 0.0f, float posY = 0.0f,
                  float width = 100.0f, float height = 100.0f);
        virtual ~Component() = default;
        void Load();
        void Unload();
        void Update(float delta) override;
        void Render() override;

        bool IsLoaded() const { return m_Loaded; }
        bool IsConfigLoaded() const { return m_ConfigLoaded; }

        void ConfigLoad(JSON config);

        const float GetPosX() const { return m_PosX; }
        void SetPosX(float posX) { m_PosX = posX; }
        const float GetPosY() const { return m_PosY; }
        void SetPosY(float posY) { m_PosY = posY; }

        const float GetWidth() const { return m_Width; }
        void SetWidth(float width) { m_Width = width; }
        const float GetHeight() const { return m_Height; }
        void SetHeight(float height) { m_Height = height; }

    protected:
        virtual void LoadImpl();
        virtual void UnloadImpl();

        virtual void UpdateImpl(float delta);
        virtual void RenderImpl();

        virtual void ConfigLoadImpl(JSON config);

    private:
        bool m_Loaded = false;
        bool m_ConfigLoaded = false;
        float m_PosX = 0;
        float m_PosY = 0;
        float m_Width = 100;
        float m_Height = 100;
    };
}