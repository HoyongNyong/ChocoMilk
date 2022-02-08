#pragma once

#include"../cmpch.h"
#include"WindowHandler.h"
#include"Component/ComponentMaster.h"

#include "Render/Renderer.h"

#include"Game.h"

#include"ChocoMilk/core/Render/Shader.h"

#include<map>

namespace ChocoMilk{

	class Application {
	public:
		Application(const std::string& title, int w, int h);
		WindowHandler& getWindow() { return *win; }

		void Created();
		void Run();
		void Off();

		virtual void OnCreate() = 0;
		virtual void OnRun() = 0;
		virtual void OnOff() = 0;
	private:
		owned<WindowHandler> win;
		owned<ComponentMaster> compMgr;
		owned<Renderer> renderer;
		std::map<std::string, ShaderResource*> shdResources;

		bool is_running = true;
	};
}
