#include "Enemy.hpp"
#include <utils/random/Random.hpp>
#include <utils/distance/distance.hpp>
#include <inputs/MouseInput.hpp>

Enemy::Enemy(float posX, float posY,
             float radius, float speedX, float speedY)
    : m_Position({posX, posY}), m_Radius(radius),
      m_SpeedX(speedX), m_SpeedY(speedY),
      m_IsAlive(true)
{
}

Enemy::~Enemy()
{
}

Scope<Enemy> Enemy::SpawnRandomly()
{
    const float minAsbSpeed = 200.0f;
    const float maxAbsSpeed = 300.0f;
    const float minRadius = 30.0f;
    const float maxRadius = 50.0f;

    const float radius = RandomFloatUniform(minRadius, maxRadius);
    const float posX = RandomFloatUniform(radius, static_cast<float>(GetScreenWidth()) - radius);
    const float posY = RandomFloatUniform(radius, static_cast<float>(GetScreenHeight()) - radius);
    const float speedX = RandomFloatUniform(minAsbSpeed, maxAbsSpeed);
    const float speedY = RandomFloatUniform(minAsbSpeed, maxAbsSpeed);

    return CreateScope<Enemy>(posX, posY, radius, speedX, speedY);
}

void Enemy::Update(float delta)
{
    m_Position.x += m_SpeedX * delta;
    m_Position.y += m_SpeedY * delta;

    if (m_Position.x + m_Radius > GetScreenWidth() || m_Position.x - m_Radius < 0)
    {
        m_SpeedX *= -1;
    }

    if (m_Position.y + m_Radius > GetScreenHeight() || m_Position.y - m_Radius < 0)
    {
        m_SpeedY *= -1;
    }

    if (IsMouseOn())
    {
        m_Color = GREEN;

        if (MouseInput::Get()->HasMouseLeftClicked())
        {
            m_IsAlive = false;
        }
    }
    else
    {
        m_Color = RED;
    }
}

void Enemy::Render()
{
    DrawCircleV(m_Position, m_Radius, m_Color);
}

bool Enemy::IsMouseOn() const
{
    auto mousePosition = GetMousePosition();
    auto distance = CalculateDistance(m_Position, mousePosition);

    return distance < m_Radius;
}