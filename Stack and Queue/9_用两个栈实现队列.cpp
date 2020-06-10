// 用两个栈实现一个队列。
// 队列的声明如下，请实现它的 appendTail 和 deleteHead，分别完成在队列尾部插入节点和
// 在队列状况删除节点的功能。

#include <iostream>
#include <stack>
#include <exception>
using namespace std;

template <typename T>
class CQueue {
private:
	stack<T> stack1;
	stack<T> stack2;
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);  // add element
	T deleteHead();  // delete element
};

template <typename T> CQueue<T>::CQueue(void){ }

template <typename T> CQueue<T>::~CQueue(void){ }

template <typename T> void CQueue<T>::appendTail(const T& node){  // add element
	stack1.push(node);
}
// 方法一：
// template <typename T> T CQueue<T>::deleteHead(){  // delete element
// 	if(stack2.size() <= 0){  // 当 stack2 为空时
// 		while(stack1.size() > 0){
// 			T& data = stack1.top();
// 			stack1.pop();
// 			stack2.push(data);
// 		}
// 	}
// 	if(stack2.size() == 0){
// 		logic_error e("queue is empty");
// 		throw exception(e);
// 	}
//
// 	// 隐含条件：当 stack2 不为空时
// 	T head = stack2.top();
// 	stack2.pop();
//
// 	return head;
// }

// 方法二：
template <typename T> T CQueue<T>::deleteHead(){
	if(stack2.empty()){
		while(!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	if(!stack2.empty()){
		int head = stack2.top();
		stack2.pop();

		return head;
	}

	return -1;
}




int main()
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');
	cout << queue.deleteHead() << endl;

	queue.appendTail('d');
	queue.appendTail('e');
	cout << queue.deleteHead() << endl;




	return 0;
}
