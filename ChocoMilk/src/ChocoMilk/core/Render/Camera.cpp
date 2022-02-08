#include "Camera.h"

namespace ChocoMilk {
	Camera::Camera() {}
	Camera::Camera(float x, float y, float w, float h) {
		camX = x;
		camY = y;
		camWidth = w;
		camHeight = h;
	}
	void Camera::updateMatrix()
	{
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(100.0f), camWidth / camHeight, 0.1f, 100.0f);
		view = glm::translate(view, glm::vec3(camX, camY, camZ));
		Renderer::getCurrentShader()->setMat4("camMatrix", projection * view);
	}
}