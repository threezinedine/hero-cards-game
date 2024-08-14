#pragma once
#include <common.hpp>
#include <cores/datatypes.hpp>

namespace ntt
{
    class Geometry
    {
    public:
        Geometry();
        Geometry(const Point &point, const Size &size);
        virtual ~Geometry();

        inline Point &GetPoint() { return point; }
        inline Size &GetSize() { return size; }

        void LoadConfigure(JSON config);

    private:
        Point point;
        Size size;
    };
} // namespace ntt
