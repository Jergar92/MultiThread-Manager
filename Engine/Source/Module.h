#ifndef _MODULE
#define _MODULE
#include <string>
class Module
{
public:
	Module(bool startEnabled = true);
	virtual ~Module() = 0;

	virtual bool Awake();
	virtual bool Start();

	virtual bool CleanUp();

	bool IsActive()const;
	const char* GetName() const;
protected:
	bool _startEnabled = true;
	bool _isActive = false;
	std::string _name;
};

#endif //_MODULE
