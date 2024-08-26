#pragma once
#include <cores/commons/common.hpp>
#include <cores/commons/datatypes.hpp>
#include <cores/interfaces/IConfigurable.hpp>

namespace ntt
{
    class Geometry : public IConfigurable
    {
    public:
        Geometry();
        Geometry(const Point &point, const Size &size);
        virtual ~Geometry();

        inline Point &GetPoint() { return m_Point; }
        inline Size &GetSize() { return m_Size; }

        void LoadConfigure(ConfigurableObject &config) override;

    private:
        Point m_Point;
        Size m_Size;
    };
} // namespace ntt
