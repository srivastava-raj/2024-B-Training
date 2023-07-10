#include <bits/stdc++.h>
using namespace std;
int main(){
	stack<int> s; // creating a stack of integers
	s.push(1); // This pushes 1 to the stack top
	s.push(2); // This pushes 2 to the stack top
	s.push(3); // This pushes 3 to the stack top
	s.push(4); // This pushes 4 to the stack top
	s.push(5); // This pushes 5 to the stack top
	// printing the stack
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	// The above loop prints "5 4 3 2 1"
	// Now, let us remove elements from the stack using pop
	// function
    s.pop(); // removes 5 from the stack since 5 was present
			// at the top. Now, the new stack top
			// becomes 4.
	s.pop(); // removes 4 from the stack since 4 was present
			// at the top. Now, the new stack top
			// becomes 3.
	s.pop(); // removes 3 from the stack since 3 was present
			// at the top. Now, the new stack top
			// becomes 2.
	s.pop(); // removes 2 from the stack since 2 was present
			// at the top. Now, the new stack top
			// becomes 1.
	s.pop(); // removes 1 from the stack since 1 was present
			// at the top. Now, the stack becomes empty.
}
