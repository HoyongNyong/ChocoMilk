#pragma once
#include "Component.h"

#include "ChocoMilk/core/Render/Sprite.h"

namespace ChocoMilk {

	class positionComponent COMPONENT {
	public:
		positionComponent(entityID id) : Component(id) {}
	public:
		int x = 0;
		int y = 0;
	};

}
