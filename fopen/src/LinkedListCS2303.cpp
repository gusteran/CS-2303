/*
 * LinkedListCS2303.cpp
 *
 *  Created on: Sep 6, 2019
 *      Author: Therese
 */

#include "LinkedListCS2303.h"

LinkedListCS2303::LinkedListCS2303() {
	//constructing a list is making an empty list
	//therefore payP and next and previous should be nullptr
	head=(LLNode*) malloc (sizeof(LLNode));
	head->payP = (Payload*)0;
	head->next = (LLNode*)0;
	head->previous = (LLNode*)0;

}
#include <stdlib.h> //for malloc



LLNode* LinkedListCS2303::makeSingletonList(Payload* pay)
{
	head->payP = pay;
	return head;
}

LLNode* LinkedListCS2303::growList(Payload* pay)
{
	LinkedListCS2303* item_P = new LinkedListCS2303();//make new empty list
	LLNode* bead_P = item_P->makeSingletonList(pay);//make a singleton list
	LLNode* h = head;
	while(h->next)
	{
		h=h->next;
		cout << "traversed once" << endl; fflush(stdout);
	}
	//now h is the last node
	h->next = bead_P;
	bead_P->previous = h;
	return bead_P;
}

LLNode* LinkedListCS2303::getHead()
{
	return head;
}
LLNode* LinkedListCS2303::getNext()
{
	return head->next;
}

LLNode* LinkedListCS2303::getPrev()
{
	return head->previous;
}

Payload* LinkedListCS2303::getPay()
{
	return head->payP;
}
void LinkedListCS2303::setNext(LLNode* n)
{
	head->next=n;
}
void LinkedListCS2303::setPrev(LLNode* p)
{
	head->previous = p;
}

void LinkedListCS2303::setPay(Payload* p)
{
	head->payP = p;
}
void LinkedListCS2303::setHead(LLNode* h)
{
	head = h;
}

LinkedListCS2303::~LinkedListCS2303() {
	//to delete whole LL,
	//while any in list,
	// go to end, delete its payload, delete it
	//rinse and repeat
	bool done = !(head->next);
	while(!done)
	{
		LLNode* temp = head;
		LLNode* tempPrev = (LLNode*)0;
		while(temp->next)//while there is a next, go there
		{
			tempPrev = temp;
			temp=temp->next;
		}
		//now temp is the last list item
		tempPrev->next = (LLNode*)0;
		if(tempPrev==head)
		{
			done =true;
		}
		cout << "Deleting nodes " << tempPrev->payP << " and " <<tempPrev<<endl; fflush(stdout);
		if(temp)
		{
			delete temp->payP;
			delete temp;
		}
	}
	free(head);

}

