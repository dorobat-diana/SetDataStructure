#include "Set.h"
#include "SetITerator.h"

Set::Set() {
	//TODO - Implementation
    this->length= 0;
    this->head = -1;
    this->capacity= 10;
    this->firstFree = 0;
    this->next = new int[this->capacity];
    this->elems = new TElem[this->capacity];
    for(int i=0;i<this->capacity-1;i++)
        this->next[i]=i+1;
    this->next[this->capacity-1]=-1;

}

int Set::allocateP() {
    //TODO - Implementation
    if (this->firstFree == -1) {
        this->capacity *= 2;
        int *newNext = new int[this->capacity];
        TElem *newElems = new TElem[this->capacity];
        for(int i=0;i<this->capacity-1;i++)
            newNext[i]=i+1;
        newNext[this->capacity-1]=-1;
        for(int i=0;i<this->length;i++){
            newNext[i]=this->next[i];
            newElems[i]=this->elems[i];
        }
        delete[] this->next;
        delete[] this->elems;
        this->next = newNext;
        this->elems = newElems;
        this->firstFree = this->length;

    }
    int newFreePos=this->firstFree;
    this->firstFree=this->next[this->firstFree];
    return newFreePos;
}

void Set::freeP(int i) {
    //TODO - Implementation
    this->next[i]=this->firstFree;
    this->firstFree=i;
}

void Set::insertFirst(TElem elem) {
    //TODO - Implementation
    int i=allocateP();
    if (i!=-1){
        this->elems[i]=elem;
        this->next[i]=this->head;
        this->head = i;
        this->length++;
    }
}


bool Set::add(TElem elem) {
	//TODO - Implementation
    if(this->search(elem))
        return false;
    this->insertFirst(elem);
	return true;
}


bool Set::remove(TElem elem) {
	//TODO - Implementation
    int prev=-1;
    int nextrem=this->head;
    while(nextrem!=-1){
        if(this->elems[nextrem]==elem){
            if(prev==-1)
                this->head=this->next[nextrem];
            else
                this->next[prev]=this->next[nextrem];
            this->freeP(nextrem);
            this->length--;
            return true;
        }
        prev=nextrem;
        nextrem=this->next[nextrem];
    }
	return false;
}

bool Set::search(TElem elem) const {
	//TODO - Implementation
    int nextserch= this->head;
    while(nextserch!=-1){
        if(this->elems[nextserch]==elem)
            return true;
        nextserch=this->next[nextserch];
    }
	return false;
}


int Set::size() const {
	//TODO - Implementation
    return this->length;
}


bool Set::isEmpty() const {
	//TODO - Implementation
    if(this->length == 0)
        return true;
	return false;
}


Set::~Set() {
	//TODO - Implementation
    delete[] this->elems;
    delete[] this->next;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


