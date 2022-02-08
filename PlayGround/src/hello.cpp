#include<ChocoMilk.h>

class GAME : public ChocoMilk::Application {
public:
	GAME(const std::string& title, int w, int h) : Application(title, w, h){}

	void OnCreate() {

	}
	void OnRun() {

	}
	void OnOff() {}
private:
	unsigned int shaderProgram;
	unsigned int vertexShader;
	unsigned int fragmentShader;
};

int main() {
	auto App = GAME("HI", 1024, 768);
	App.Run();
	return 0;
}
