#pragma once

#include"Renderer.h"
#include"glad/gl.h"
#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"

namespace ChocoMilk {

	class Camera {
	public:
		Camera();
		Camera(float x, float y, float w, float h);

		void updateMatrix();

		inline float getWidth()  { return camWidth ; }
		inline float getHeight() { return camHeight; }
		inline float getAngle()  { return camAngle ; }

		inline float setWidth (float cw) { camWidth  = cw; }
		inline float setHeight(float ch) { camHeight = ch; }
		inline float setAngle (float ca) { camAngle  = ca; }

	private:
		float camX = 0.0f;
		float camY = 0.0f;
		float camZ = -0.3f;

		float camAngle = 0.0f;
		float camWidth = 1600.0f;
		float camHeight = 900.0f;
	};

}
