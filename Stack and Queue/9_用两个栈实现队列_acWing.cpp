// https://www.acwing.com/problem/content/description/36/


#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(st2.size() <= 0){
            while(st1.size() > 0){
                int& data = st1.top();
                st1.pop();
                st2.push(data);
            }
        }
        int head = st2.top();
        st2.pop();

        return head;
    }

    /** Get the front element. */
    int peek() {
        if(st2.size() <= 0){
            while(st1.size() > 0){
                int& data = st1.top();
                st1.pop();
                st2.push(data);
            }
        }

        return st2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        bool mark = true;
        if(st1.empty() && st2.empty())
            mark = false;

        return mark;
    }
};



int main()
{

	 // Your MyQueue object will be instantiated and called as such:
	 MyQueue obj = MyQueue();

	 obj.push(1);
	 obj.push(2);
	 cout << obj.peek() << endl;
	 cout << obj.pop() << endl;
	 cout << obj.pop() << endl;
	 cout << obj.empty() << endl;

	return 0;
}
