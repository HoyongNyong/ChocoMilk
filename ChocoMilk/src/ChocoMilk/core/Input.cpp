#include "Input.h"

namespace ChocoMilk {

	Input* Input::INPUT = new Input();
	bool keyHolding(int keycode) { return true; }
	bool keyPressed(int keycode){ return true; }
	bool keyReleased(int keycode){ return true; }

	bool mouseHolding(int mousecode){ return true; }
	bool mousePressed(int mousecode){ return true; }
	bool mouseReleased(int mousecode){ return true; }

}
