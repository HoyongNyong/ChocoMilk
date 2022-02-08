#pragma once
#include<memory>

namespace ChocoMilk {
	template<typename T>
	using owned = std::unique_ptr<T>;

	template<typename T>
	using res = std::shared_ptr<T>;
}
