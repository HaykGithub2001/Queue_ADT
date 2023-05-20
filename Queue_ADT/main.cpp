#include <iostream>
#include "Queue.h"
int main()
{
	Queue <int> a;
	a.push(5);
	a.push(10);
	a.push(15678);
	a.pop();
	a.output();
	a.front()=8;
	a.output();
	std::cout << a.length();
	return 0;
}