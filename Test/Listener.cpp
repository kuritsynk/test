#pragma once
#ifndef _LISTENER_CPP_

#define _LISTENER_CPP_


#include <vector>

using namespace std;

template <class EventT>
class Listener {

public:

	virtual void execute(EventT event) = 0;

};

template <class EventT>
class Event {

	vector<Listener<EventT>*> listeners;

public:

	virtual void registerListener(Listener<EventT>* listener) {
		listeners.push_back(listener);
	}

	virtual void notifyAll(EventT event) {

		for (unsigned int i = 0; i < listeners.size(); i++)
		{
			listeners[i]->execute(event);
		}

	}

};


#endif // !_LISTENER_CPP_

