#pragma once

#include"Component.h"
#include"Entity.h"
#include<typeinfo>
#include<typeindex>
#include<unordered_map>

namespace ChocoMilk{
	class ComponentMaster {
	public:

		template<typename Cmp>
		void CreateComponent();
		template<typename Cmp>
		Cmp& AddComponent(entityID entity);
		template<typename Cmp>
		Cmp& GetComponent(entityID entity);

	private:
		std::unordered_map<std::type_index, void*> CompHolders;
	};
}
