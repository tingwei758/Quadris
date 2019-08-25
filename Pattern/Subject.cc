#include "Subject.h"

void Subject::attach(Observer *ob){
	observer = ob;
}

void Subject::dettach(){
	observer = nullptr;
}

void Subject::notifyObservers(){
	if (observer) {
		observer->notify(this);
	}
}

