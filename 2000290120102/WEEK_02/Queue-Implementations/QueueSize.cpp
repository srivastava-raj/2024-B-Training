#include <iostream>
#include <queue>
using namespace std;
 
int main()
{
    int sum = 0;
    queue<int> myqueue;
    myqueue.push(1);
    myqueue.push(8);
    myqueue.push(3);
    myqueue.push(6);
    myqueue.push(2);
 
    // Queue becomes 1, 8, 3, 6, 2
 
    cout << myqueue.size();
 
    return 0;
}