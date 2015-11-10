#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue <int> a;
	
	a.push(1);
	a.push(7);
	a.push(4);
	a.push(5);
	a.push(6);
	a.push(12);
	a.push(0);
	
	cout << "Size = " << a.size() << endl;
	cout << "Front = " << a.front() << endl;
	cout << "Back = " << a.back() << endl;
	
	a.pop();
	
	cout << "Front = " << a.front() << endl;
	cout << "Back = " << a.back() << endl;
	
}
