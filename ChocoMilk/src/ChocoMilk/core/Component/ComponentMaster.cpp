#include"ComponentMaster.h"

namespace ChocoMilk {

	template<typename Cmp>
	void ComponentMaster::CreateComponent() {
		CompHolders[typeid(Cmp)] = new std::vector<Cmp>();
	}

	template<typename Cmp>
	Cmp& ComponentMaster::AddComponent(entityID entity) {
		std::vector<Cmp>& holder = *(static_cast<std::vector<Cmp>*>(CompHolders[typeid(Cmp)]));
		holder.emplace_back(entity);
		return holder.back();
	}

	template<typename Cmp>
	Cmp& ComponentMaster::GetComponent(entityID entity) {
		std::vector<Cmp>& holder = *(static_cast<std::vector<Cmp>*>(CompHolders[typeid(Cmp)]));
		for (int i = 0; i < holder.size(); i++) {
			Cmp& com = holder[i];
			if (com.owner == entity) {
				return com;
			}
			else { continue; }
		}
		std::cout << "Failed to load!" << std::endl;
	}
}
