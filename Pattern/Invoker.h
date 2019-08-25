#ifndef __INVOKER_H__
#define __INVOKER_H__

#include "../Command/Command.h"

class Invoker {
	Command *command;
public:
	void setCommand(Command *);
	void action();
};

#endif
