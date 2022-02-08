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
//// �������ڸ� vao => �������� ����, ���ؽ� �Ӽ��� '���ε�'�Ǵ� ������ ����
//// vbo => ���ؽ��� �������� ������ ���������� ����Ǵ� �޸� ���� -> ���� ���ε� �Ǿ� �ִ� vbo�� ���缭 �׸��� OpenGL�� ������ �ϴ� ������ ����
//// ibo => ���� ��� �簢���� �׸� �� �ﰢ�� �� ���� �׸��µ�, ���ؽ����� �ߺ��Ǵ� �� ��������, �� �״�� '��'

//OpenGL�� ���� ���ε� ��Ų ���۳� VAO�� ���ؼ� �Ŀ� ȣ���ϴ� �Լ����� �����Ű�ų�, �ٷ� �� ����. �׷��� ���ε��� �ؾ߸� �ϴ� ��.
//Shader�� ��ü������ ���̴� �ҽ��ڵ带 ���� ������ �� ������ ���α׷��� attatch��Ų �� �� ���α׷��� ��ũ ���Ѽ� ����� �� ����
*/
