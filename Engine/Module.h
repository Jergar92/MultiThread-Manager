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
	virtual bool Update();
	virtual bool LateUpdate();

protected:
	bool _startEnabled = true;
	std::string _name;
};

#endif //_MODULE
