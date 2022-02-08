#pragma once
#include "glad/gl.h"
#include "stb_image/stb_image.h"
#include <string>

namespace ChocoMilk {
	class Texture {
	public:
		Texture(const std::string& path);
		void bind();
	private:
		int width, height;
		int channel;
		unsigned char* data;
		unsigned int texID;
	};
}