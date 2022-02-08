#define STB_IMAGE_IMPLEMENTATION

#include "Application.h"
#include "Render/Sprite.h"
#include "Render/Camera.h"

namespace ChocoMilk {
	Application::Application(const std::string& title, int w, int h)
	{
		win = std::make_unique<WindowHandler>(title,w,h);
		renderer = std::make_unique<Renderer>();
		//compMgr = std::make_unique<ComponentMaster>();
		//game = std::make_unique<Game>();
	}

	void Application::Created() {

		Sprite::Init();

		shdResources["defalutVert"] = new ShaderResource(ShaderType::vertex, "res/shader/default2D.vert");
		shdResources["defalutFrag"] = new ShaderResource(ShaderType::fragment, "res/shader/default2D.frag");

		OnCreate();
	}

	void Application::Run(){
		Created();

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		Camera mainCam(0.0f, 0.0f, win->getWidth(),win->getHeight());

		ShaderHolder shader(shdResources["defalutVert"]->getID(), shdResources["defalutFrag"]->getID());
		shader.link();

		renderer->setDefaultShader(&shader);
		renderer->resetShader();

		Sprite Cat("res/image/popCat.png");

		while (is_running) {
			glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			mainCam.updateMatrix();
			Sprite::draw_ext(Cat,0.0f,0.0f,1.0f,1.0f,45.0f);

			win->update();
			OnRun();
			renderer->update();
		}

		shader.destroy();
	}

	void Application::Off()
	{
		OnOff();
		is_running = false;
	}
}

//memo
/*
//// 정리하자면 vao => 여러가지 버퍼, 버텍스 속성이 '바인딩'되는 공간적 개념
//// vbo => 버텍스의 여러가지 정보가 실질적으로 저장되는 메모리 공간 -> 현재 바인딩 되어 있는 vbo에 맞춰서 그림을 OpenGL은 렌더링 하는 것으로 보임
//// ibo => 예를 들어 사각형을 그릴 때 삼각형 두 개를 그리는데, 버텍스들이 중복되는 걸 방지해줌, 말 그대로 '변'

//OpenGL은 현재 바인딩 시킨 버퍼나 VAO에 대해서 후에 호출하는 함수들을 적용시키거나, 다룰 수 있음. 그래서 바인딩을 해야만 하는 것.
//Shader는 자체적으로 쉐이더 소스코드를 따로 컴파일 후 쉐이터 프로그램에 attatch시킨 후 본 프로그램에 링크 시켜서 사용할 수 있음
*/
