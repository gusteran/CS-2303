/*
 * LinkedListCS2303.h
 *
 *  Created on: Sep 6, 2019
 *      Author: Therese
 */

#ifndef LINKEDLISTCS2303_H_
#define LINKEDLISTCS2303_H_
#include <iostream>

using namespace std;

typedef struct
{
	int first;
	int second;
}Payload;



struct LLNode
{
	Payload* payP;
	LLNode* next;
	LLNode* previous;
};



class LinkedListCS2303 {

private:
	LLNode* head; //list is null or node followed by list;

public:
	LinkedListCS2303();
	LLNode* makeSingletonList(Payload* pay);
	LLNode* growList(Payload* pay);
	LLNode* getNext();
	LLNode* getPrev();
	Payload* getPay();
	LLNode* getHead();
	void setNext(LLNode* n);
	void setPrev(LLNode* p);
	void setPay(Payload* p);
	void setHead(LLNode* h);
	virtual ~LinkedListCS2303();
};



#endif /* LINKEDLISTCS2303_H_ */
