/*
 * Tests.cpp
 *
 *  Created on: Sep 5, 2019
 *      Author: Therese
 */

#include "Tests.h"
#include "Production.h"
#include "StackTemplate.h"
#include "LinkedListCS2303.h"
#include <iostream>
using namespace std;

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests(){
	bool answer = true;

	bool ok1 = testEmptyList();
	cout << "Back from test empty list" << endl; fflush(stdout);
	bool ok2 = testSingletonList();
	cout << "Back from test singleton list" << endl;fflush(stdout);
	bool ok3 = testAddNode();
	cout << "Back from test add to list" << endl;fflush(stdout);
	bool ok4 = testDeleteList();
	cout << "Back from test delete" << endl;fflush(stdout);

	int int1 = 4;
	int int2 = 6;
	int int3 = 5;

	std::cout << "The maximum integer value is: " << maximum (int1, int2, int3) << std::endl;

	double d1 = 5.4;
	double d2 = 3.7;
	double d3 = 0;

	cout << "The maximum double value is: " << maximum (d1, d2, d3) << endl;

	char c1 = 'X';
	char c2 = 'm';
	char c3 = 'z';

	cout << "The maximum character value is: " << maximum (c1, c2, c3) << endl;

	StackTemplate <double> doubleStack(5);
	d1 = 1.1;

	cout << "Pushing onto double stack."<<endl;

	while (doubleStack.push(d1))
	{
		cout << d1 << ' ';
		d1 += 1.1;
	}

	cout << "\nStack is full. Cannot push " << d1 << "\npopping\n";


	while(doubleStack.pop(d1))
	{
		cout << d1 << ' ';

	}

	cout << "\nStack is empty. Cannot pop\n";
	StackTemplate<int> intStack;
	int i1 = 1;

	cout << "Pushing onto int stack."<<endl;

	while (intStack.push (i1))
	{
		cout << i1++ << ' ';

	}

	cout << "\nStack is full. Cannot push " << i1 << "\npopping\n";


	while (intStack.pop (i1))
	{
		cout << i1 << ' ';

	}

	cout << "\nStack is empty. Cannot pop\n";

	answer = ok1 && ok2 && ok3 && ok4;

	return answer;
}

bool Tests::testEmptyList()
{
	bool ok = true;
	LinkedListCS2303* ll_P = new LinkedListCS2303();
	if(ll_P->getNext() !=(LLNode*)0)
	{
		ok = false;
	}
	if(ll_P->getPrev() != (LLNode*)0)
	{
		ok = false;
	}
	if(ll_P->getPay() != (Payload*)0)
	{
		ok = false;
	}
	return ok;
}
bool Tests::testSingletonList()
{
	bool ok = true;
	LinkedListCS2303* ll_P = new LinkedListCS2303();
	Payload* payP = (Payload*) malloc(sizeof(Payload));
	payP->first = 17;
	payP->second = -13;
	ll_P->makeSingletonList(payP);
	if(ll_P->getPay()->first != 17)
	{
		ok = false;
	}
	if(ll_P->getPay()->second != -13)
	{
		ok = false;
	}

	return ok;
}

bool Tests::testAddNode()
{
	bool ok = true;
	LinkedListCS2303* ll_P1 = new LinkedListCS2303();
	Payload* payP1 = (Payload*) malloc(sizeof(Payload));
	payP1->first = 17;
	payP1->second = -13;
	ll_P1->makeSingletonList(payP1);//first list item
	Payload* payP2 = (Payload*) malloc(sizeof(Payload));
	payP2->first = -8;
	payP2->second = 22;
	LLNode* retP = ll_P1->growList(payP2);//second list item, 0 traversals
	cout << "Back from growList with "<<retP << endl; fflush(stdout);
	cout << "Get next is " << ll_P1->getNext() <<endl; fflush(stdout);
	cout << ll_P1->getNext()->payP <<endl; fflush(stdout);

	if(ll_P1->getNext()->payP != payP2)
	{
		ok = false;
	}
	cout << "Back from adding payload" << endl; fflush(stdout);
	if(ll_P1->getNext()->payP->first != -8)
	{
		ok = false;
	}
	Payload* payP3 = (Payload*) malloc(sizeof(Payload));
	payP3->first = 32;
	payP3->second = 1;
	LLNode* ret2P = ll_P1->growList(payP3);//third list item 1 traversal
	if(ll_P1->getNext()->next->payP->first != 32)
	{
		ok = false;
	}
	Payload* payP4 = (Payload*) malloc(sizeof(Payload));
	payP4->first = -1;
	payP4->second = 12;
	LLNode* ret3P = ll_P1->growList(payP4);//fourth list item, 2 traversals
	if(ll_P1->getNext()->next->next->payP->first != -1)
	{
		ok = false;
	}

	return ok;
}

bool Tests::testDeleteList()
{
	bool ok = true;
	LinkedListCS2303* ll_P1 = new LinkedListCS2303();
	delete ll_P1;
	cout << "Back from first delete" << endl; fflush(stdout);
	ll_P1 = new LinkedListCS2303();
	Payload* payP1 = (Payload*) malloc(sizeof(Payload));
	payP1->first = 17;
	payP1->second = -13;
	ll_P1->makeSingletonList(payP1);
	Payload* payP2 = (Payload*) malloc(sizeof(Payload));
	payP2->first = -8;
	payP2->second = 22;
	LLNode* retP = ll_P1->growList(payP2);
	Payload* payP3 = (Payload*) malloc(sizeof(Payload));
	payP3->first = 32;
	payP3->second = 1;
	LLNode* ret2P = ll_P1->growList(payP3);
	Payload* payP4 = (Payload*) malloc(sizeof(Payload));
	payP4->first = -1;
	payP4->second = 12;
	LLNode* ret3P = ll_P1->growList(payP4);//fourth list item, 2 traversals
	delete ll_P1;
	cout << "Back from second delete" << endl; fflush(stdout);
	return ok;
}
