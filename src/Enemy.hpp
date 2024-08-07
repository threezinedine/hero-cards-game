#pragma once
#include <common.hpp>

class Enemy
{
public:
    Enemy(float posX = 0.0f, float posY = 0.0f,
          float radius = 10.0f,
          float speedX = 1.0f, float speedY = 1.0f);
    ~Enemy();

    static Scope<Enemy> SpawnRandomly();
    void Update(float delta);
    void Render();

    inline const bool IsAlive() const { return m_IsAlive; }

protected:
    bool IsMouseOn() const;

private:
    Vector2 m_Position;
    float m_Radius;

    float m_SpeedX;
    float m_SpeedY;

    bool m_IsAlive;
    Color m_Color = RED;
};