#ifndef _MOUSE_CONTROLLER
#define _MOUSE_CONTROLLER
enum KeyState;
union SDL_Event;
class MouseController
{
public:
	MouseController();
	~MouseController();
	void UpdateInput();
	void PollEvents(const SDL_Event& e);

	bool CleanUp();


	int GetMouseX() const;
	int GetMouseY() const;
	int GetMouseZ() const;
	int GetMouseXMotion() const;
	int GetMouseYMotion() const;

	bool GetMouseButtonDown(int id) const;
	bool GetMouseButtonRepeat(int id) const;
	bool GetMouseButtonUp(int id) const;
private:
	KeyState* mouseKeys = nullptr;

	int mouseX = 0;
	int mouseY = 0;
	int mouseZ = 0;
	int mouseMotionX = 0;
	int mouseMotionY = 0;
};

#endif // _MOUSE_CONTROLLER


