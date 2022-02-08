#pragma once


namespace ChocoMilk {

	class Input {
	public:
		bool keyHolding(int keycode);
		bool keyPressed(int keycode);
		bool keyReleased(int keycode);

		bool mouseHolding(int mousecode);
		bool mousePressed(int mousecode);
		bool mouseReleased(int mousecode);
	public:
		static Input* INPUT;
	private:
	
	};

}
