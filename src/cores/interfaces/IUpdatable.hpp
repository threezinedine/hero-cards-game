#pragma once

namespace ntt
{
	class IUpdatable
	{
	public:
		virtual ~IUpdatable() = default;
		virtual void Update(float delta) = 0;
	};
} // namespace ntt
