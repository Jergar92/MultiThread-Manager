#ifndef _MOUSE_CONTROLLER
#define _MOUSE_CONTROLLER
enum KeyState;

class MouseController
{
public:
	MouseController();
	~MouseController();
	void UpdateInput();
	bool CleanUp();
private:
	KeyState* mouseKeys = nullptr;

	int mouseX = 0;
	int mouseY = 0;
	int mouseZ = 0;
	int mouseMotionX = 0;
	int mouseMotionY = 0;
};

#endif // _MOUSE_CONTROLLER


