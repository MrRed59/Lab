#pragma once
#include"TEvent.h"
class Object
{
public:
	Object();
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual ~Object(void);
	int Checking_For_Valid_Input();
	virtual void HandleEvent(const TEvent&) = 0;
};

