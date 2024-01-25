#include "Element.h"

#ifndef PRIORITYQUEUECOMPARATOR_H_
#define PRIORITYQUEUECOMPARATOR_H_

class ElementComparator {

public:

	bool operator()(const Element &arg1, const Element &arg2) const {
		return arg1.priority > arg2.priority;
	}
};



#endif /* PRIORITYQUEUECOMPARATOR_H_ */
