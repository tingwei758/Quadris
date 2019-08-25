#ifndef __SUBJECT_H_
#define __SUBJECT_H_

#include "Observer.h"

class Subject {
	Observer *observer;

public:
	void attach(Observer *);
	void dettach();
	void notifyObservers();
};

#endif
