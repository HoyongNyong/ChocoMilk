#pragma once
#include"ChocoMilk/cmpch.h"
#include<functional>

#define __ENTITY_SINGLEFUNC_NUM__ 2
#define __ENTITY_FRAMEFUNC_NUM__ 2

#define CREATE registerSingleCall(EntitySingleFuncType::created,[=]()->void{
#define DESTROY registerSingleCall(EntitySingleFuncType::destroyed,[=]()->void{
#define STEP registerFrameCall(EntityFrameFuncType::update,[=](int ts)->void{
#define DRAW registerFrameCall(EntityFrameFuncType::update,[=](int ts)->void{
#define END });

enum class EntitySingleFuncType{
	created = 0, destroyed
};
enum class EntityFrameFuncType {
	update = 0, draw
};

using entityID = uint32_t;

namespace ChocoMilk {
	static entityID s_entity = 0;
	inline static entityID createNativeEntity() {
		return s_entity++;
	}

	class staticEntity {
	protected:
		entityID id;
	};
	
	class scriptableEntity {
	public:
		void registerSingleCall(EntitySingleFuncType funcName, std::function<void()> func);
		void registerFrameCall(EntityFrameFuncType funcName, std::function<void(int)> func);
	protected:
		entityID id;
		std::function<void()> singleCall[__ENTITY_SINGLEFUNC_NUM__];
		std::function<void(int)> frameCall[__ENTITY_FRAMEFUNC_NUM__];
		//void (*singleCall[__ENTITY_SINGLEFUNC_NUM__])();
		//void (*frameCall[__ENTITY_FRAMEFUNC_NUM__])(int);
	};
}

