#include "SetIterator.h"
#include "Set.h"
#include <exception>
using namespace std;

SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
    current=m.head;
}


void SetIterator::first() {
	//TODO - Implementation
    current=set.head;
}


void SetIterator::next() {
	//TODO - Implementation
    if (current==-1)
        throw std::exception();
    current=set.next[current];
}


TElem SetIterator::getCurrent()
{
	//TODO - Implementation
    if (current==-1)
        throw std::exception();
    return set.elems[current];

}

bool SetIterator::valid() const {
	//TODO - Implementation
	return current!=-1;
}



