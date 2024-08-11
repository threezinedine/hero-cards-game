#pragma once
#include <chrono>

namespace ntt
{
    class DeltaTimer
    {
    public:
        DeltaTimer();
        ~DeltaTimer();

        void Start();

        inline const float GetDelta() const { return m_delta; }

    private:
        std::chrono::high_resolution_clock::time_point m_start;
        float m_delta = 0.0f;
    };
} // namespace ntt
