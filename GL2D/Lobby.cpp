#include "Lobby.h"
#include "FWM.h"
#include "Title.h"
#include "Button.h"
#include <string>

void Lobby::SetController() {
	glutMotionFunc(MouseMotion);
	glutPassiveMotionFunc(MousePassiveMotion);
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutMouseWheelFunc(MouseWheel);
	glutMouseFunc(MouseButton);
	glutSpecialFunc(SpecialKeyDown);
	glutSpecialUpFunc(SpecialKeyUp);
}

std::string Lobby::LobbyMode() {
	fw.AddObject(new Title, "title", Layer::L2);
	fw.AddObject(new Button, "button", Layer::L2);

	return __func__;
}

void Lobby::ProcessKeyboard(unsigned char KEY, int S_KEY, bool KeyDown, bool SpecialKey) {
	// Normal Key Down
	if (KeyDown && !SpecialKey)
		switch (KEY) {
		case 27:
			glutDestroyWindow(1);
			break;
		}

	// Normal Key Up
	else if (!KeyDown && SpecialKey)
		switch (KEY) {

		}

	// Special Key Down
	if (KeyDown && SpecialKey)
		switch (S_KEY) {

		}

	// Special Key Up
	else if (!KeyDown && SpecialKey)
		switch (S_KEY) {

		}
}

void Lobby::MouseButton(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		switch (state) {
		case GLUT_DOWN:
			break;

		case GLUT_UP:
			break;
		}
		break;

	case GLUT_RIGHT_BUTTON:
		switch (state) {
		case GLUT_DOWN:
			break;

		case GLUT_UP:
			break;
		}
		break;
	}
}

void Lobby::MouseWheel(int button, int Wheel, int x, int y) {
	if (Wheel > 0) {
	}

	else if (Wheel < 0) {
	}
}


void Lobby::KeyDown(unsigned char KEY, int x, int y) {
	ProcessKeyboard(KEY, NULL, true, false);
}

void Lobby::KeyUp(unsigned char KEY, int x, int y) {
	ProcessKeyboard(KEY, NULL, false, false);
}

void Lobby::SpecialKeyUp(int KEY, int x, int y) {
	ProcessKeyboard(NULL, KEY, true, true);
}

void Lobby::SpecialKeyDown(int KEY, int x, int y) {
	ProcessKeyboard(NULL, KEY, false, true);
}

void Lobby::MouseMotion(int x, int y) {
	mouse.ConvertPosition(x, y);
}

void Lobby::MousePassiveMotion(int x, int y) {
	mouse.ConvertPosition(x, y);
}