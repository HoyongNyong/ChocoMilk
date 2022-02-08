#pragma once
#include "Entity.h"

#define COMPONENT :public Component

namespace ChocoMilk {
	struct Component {
		Component(entityID id) : owner(id) {}
		entityID owner;
	};
}
