#include "Enemy.hpp"
#include <utils/random/Random.hpp>
#include <utils/distance/distance.hpp>
#include <renderer/renderer.hpp>

Enemy::Enemy(float posX, float posY,
             float radius, float speedX, float speedY)
    : m_PosX(posX), m_PosY(posY), m_Radius(radius),
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
    const float posX = RandomFloatUniform(radius, ntt::renderer::GetWindowWidth() - radius);
    const float posY = RandomFloatUniform(radius, ntt::renderer::GetWindowHeight() - radius);
    const float speedX = RandomFloatUniform(minAsbSpeed, maxAbsSpeed);
    const float speedY = RandomFloatUniform(minAsbSpeed, maxAbsSpeed);

    return CreateScope<Enemy>(posX, posY, radius, speedX, speedY);
}

void Enemy::Update(float delta)
{
    m_PosX += m_SpeedX * delta;
    m_PosY += m_SpeedY * delta;

    if (m_PosX + m_Radius > ntt::renderer::GetWindowWidth() || m_PosX - m_Radius < 0)
    {
        m_SpeedX *= -1;
    }

    if (m_PosY + m_Radius > ntt::renderer::GetWindowHeight() || m_PosY - m_Radius < 0)
    {
        m_SpeedY *= -1;
    }
}

void Enemy::Render()
{
}