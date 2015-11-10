#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack <int> a;
	a.push(1);
	a.push(2);
	a.push(5);
	a.push(6);
	a.push(0);
	a.push(7);
	a.push(13);
	
	cout << "Size = " << a.size() << endl;
	cout << "Value at the top = " << a.top() << endl;
	
	a.pop();
	
	cout << "Value at the top after popping = " << a.top() << endl;
	
	
}
