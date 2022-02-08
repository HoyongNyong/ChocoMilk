#include "Entity.h"

namespace ChocoMilk {
	void scriptableEntity::registerSingleCall(EntitySingleFuncType funcName, std::function<void()> func)
	{
		static int num = 0;
		if (num < __ENTITY_SINGLEFUNC_NUM__)
			singleCall[num++] = func;
		else
			std::cout << "singleCallFunctionTable is FULL" << std::endl;
	}

	void scriptableEntity::registerFrameCall(EntityFrameFuncType funcName, std::function<void(int)> func)
	{
		static int num = 0;
		if (num < __ENTITY_FRAMEFUNC_NUM__)
			frameCall[num++] = func;
		else
			std::cout << "frameCallFunctionTable is FULL" << std::endl;
	}

}