/// Source : https://leetcode.com/problems/design-circular-queue/description/
/// Author : liuyubobobo
/// Time   : 2018-08-24

#include <iostream>
#include <vector>

using namespace std;


/// One more space implementation
/// Time Complexity: O(1)
/// Space Complexity: O(n)
class MyCircularQueue {

private:
    int front, tail;
    vector<int> data;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {

        front = tail = 0;
        data.clear();
        for(int i = 0; i <= k; i ++)
            data.push_back(-1);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
            return false;
        data[tail] = value;
        tail = (tail + 1) % data.size();
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;
        front = (front + 1) % data.size();
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
            return -1;
        return data[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
            return -1;
        int index = tail - 1;
        if(index < 0)
            index += data.size();
        return data[index];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == tail;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (tail + 1) % data.size() == front;
    }
};


int main() {

    return 0;
}