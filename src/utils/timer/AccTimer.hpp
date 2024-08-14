#pragma once
#include <cores/commons/common.hpp>
#include <chrono>

namespace ntt
{
    class AccTimer
    {
    public:
        AccTimer();
        ~AccTimer();

        void Reset();

        float GetDelta() const;

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
    };
}