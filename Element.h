#ifndef ELEMENT_H_
#define ELEMENT_H_

class Element {

public:

	int item;
	int priority;

	Element(int item, int priority) {
		this->item = item;
		this->priority = priority;
	}
};

#endif /* ELEMENT_H_ */
