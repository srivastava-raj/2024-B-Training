#include <bits/stdc++.h>
using namespace std;
bool isEmpty(stack<int>& s){
    bool isStackEmpty
        = s.empty(); // checking whether stack is empty or
                     // not and storing it into isStackEmpty
                     // variable
      return isStackEmpty; // returning bool value stored in
                         // isStackEmpty
}
int main(){
    stack<int> s;
    // The if - else conditional statements below prints
    // "Stack is empty."
    if (isEmpty(s)) {
        cout << "Stack is empty." << endl;
    }
    else {
        cout << "Stack is not empty." << endl;
    }
    s.push(1); //  Inserting value 1 to the stack top
    // The if - else conditional statements below prints
    // "Stack is not empty."
    if (isEmpty(s)) {
        cout << "Stack is empty." << endl;
    }
    else {
        cout << "Stack is not empty." << endl;
    }
}