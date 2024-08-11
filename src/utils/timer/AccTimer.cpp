#include "AccTimer.hpp"

namespace ntt
{
    AccTimer::AccTimer()
    {
        Reset();
    }

    AccTimer::~AccTimer()
    {
    }

    void AccTimer::Reset()
    {
        m_start = std::chrono::high_resolution_clock::now();
    }

    float AccTimer::GetDelta() const
    {
        auto newPoint = std::chrono::high_resolution_clock::now();

        return std::chrono::duration<float, std::chrono::seconds::period>(newPoint - m_start).count();
    }
}