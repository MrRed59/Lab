#pragma once
#include"List.h"
#include"TEvent.h"

class Dialog:public List
{
protected:
	int EndState;
public:
	Dialog();
	
	virtual ~Dialog();
	virtual void GetEvent(TEvent &);
	virtual int Execute();
	virtual void HandleEvent(TEvent&);
	virtual void ClearEvent(TEvent&);
	int Valid();
	void EndExec();
};

