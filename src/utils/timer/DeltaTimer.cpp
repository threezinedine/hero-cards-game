#include "DeltaTimer.hpp"
#include <iostream>

namespace ntt
{
    DeltaTimer::DeltaTimer()
    {
        Start();
    }

    DeltaTimer::~DeltaTimer()
    {
    }

    void DeltaTimer::Start()
    {
        auto newPoint = std::chrono::high_resolution_clock::now();

        m_delta = std::chrono::duration<float, std::chrono::seconds::period>(newPoint - m_start).count();

        m_start = newPoint;
    }
}