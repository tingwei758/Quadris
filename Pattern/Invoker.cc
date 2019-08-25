#include "Invoker.h"

void Invoker::setCommand(Command *command){
	this->command = command;
}

void Invoker::action(){
	command->execute();
}
