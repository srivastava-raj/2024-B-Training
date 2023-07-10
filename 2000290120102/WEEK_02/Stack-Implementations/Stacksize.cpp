#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int> s; // creating a stack of integers
    cout << s.size()
         << endl; // Prints 0 since the stack is empty
    s.push(1); // This pushes 1 to the stack top
    s.push(2); // This pushes 2 to the stack top
    cout << s.size() << endl; // Prints 2 since the stack
                              // contains two elements
    s.push(3); // This pushes 3 to the stack top
    cout << s.size() << endl; // Prints 3 since the stack
                              // contains three elements
}