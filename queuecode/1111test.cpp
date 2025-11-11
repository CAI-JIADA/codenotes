#include<iostream>
using namespace std;
template <class T>
class Queue {
public:
	Queue(int queueCapacity = 10);
	bool IsEmpty() const;
	T& Front() const;
	T& Rear() const;
	void Push(const T& item);
	void Pop();
private:
	T* queue;
	int front,
		rear,
		capacity;//®e¶q
};
template<class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity) {
	if (capacity < 1) throw "Queue capacity must be>0";
	queue = new T[capacity];
	front = rear = 0;
}
template <class T>
inline bool Queue<T>::IsEmpty() const {
	return front == rear;
}
template <class T>
inline T& Queue<T>::Front() const {
	if (IsEmpty()) throw "Queue is empty. No front element";
	return queue[(front + 1) % capacity];
}
template <class T>
inline T& Queue<T>::Rear() const {
	if (IsEmpty()) throw "Queue is empty. No rear element";
	return queue[rear];
}
template <class T>
void Queue<T>::Push(const T& x) {
	if ((rear + 1) % capacity == front) {
		T* newQueue = new T[2 * capacity];
		int start=(front + 1) % capacity;
		if (start < 2) {
			std::copy(queue + start, queue + start + capacity - 1, newQueue);
		}
		else {
			std::copy(queue + start, queue + capacity, newQueue);
			std::copy(queue, queue + rear + 1, newQueue + capacity-start);
		}
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] queue;
		queue=newQueue;
		
	}
	rear = (rear + 1) % capacity;
	queue[rear] = x;
}
template <class T>
void Queue<T>::Pop() {
	if (IsEmpty()) throw "Queue is empty.";
	front = (front + 1) % capacity;
	queue[front].~T();
}
int main() {
	Queue<int> A;
	A.Push(1);
	A.Push(2);
	A.Push(3);
	A.Push(4);
	cout << A.Front() << endl;
	A.Pop();
	cout << A.Front() << endl;
	A.Pop();
	cout << A.Rear() << endl;
	A.Pop();
	cout << A.Front() << endl;
	cout << A.IsEmpty() << endl;
	A.Pop();
	cout << A.IsEmpty() << endl;
	Queue<char> B;
	B.Push('a');
	B.Push('b');
	B.Push('c');
	B.Push('d');
	cout << B.Front() << endl;
	B.Pop();
	cout << B.Front() << endl;
	B.Pop();
	cout << B.Rear() << endl;
	B.Pop();
	cout << B.Front() << endl;
	cout << B.IsEmpty() << endl;
	B.Pop();
	cout << B.IsEmpty() << endl;
}
