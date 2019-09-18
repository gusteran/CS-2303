/*
 * StackTemplate.h
 *
 *  Created on: Sep 5, 2019
 *      Author: Therese
 */

#ifndef STACKTEMPLATE_H_
#define STACKTEMPLATE_H_

template< typename T >
class StackTemplate {
public:
	StackTemplate(int = 10);
	~StackTemplate()
	{
		delete [] stackPtr;
	}
	bool push( const T & );
	bool pop( T & );
	bool isEmpty() const
	{
		return top == -1;
	}
	bool isFull() const
	{
		return top == size -1;
	}

private:
	int size;
	int top;
	T* stackPtr;
};

template< typename T >
StackTemplate < T >::StackTemplate (int s)
: size(s > 0 ? s : 10),
  top (-1),
  stackPtr (new T[size])
  {

  }

template< typename T >
bool StackTemplate <T>::push( const T &pushValue)
{
	bool answer = false;
	if ( !isFull())
	{
		stackPtr[ ++top] = pushValue;
		answer = true;
	}
	return answer;
}
template< typename T >
bool StackTemplate <T>::pop( T &popValue)
{
	bool answer = false;
	if (!isEmpty())
	{
		popValue = stackPtr[top--];
		answer = true;
	}
	return answer;
}


#endif /* STACKTEMPLATE_H_ */
