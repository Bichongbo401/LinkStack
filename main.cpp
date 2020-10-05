#include <iostream>
#include "LinkStack.h"
using namespace std;
int main() {
	LinkStack<int> L1;
	L1.push(100);
	cout << L1.Length() << endl;
	int a;
	L1.Pop(a);
	cout << a << endl;
	return 0;
}