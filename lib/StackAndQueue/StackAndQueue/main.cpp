//
//  main.cpp
//  StackAndQueue
//
//  Created by 高橋 誠二 on 2015/03/29.
//  Copyright (c) 2015年 高橋 誠二. All rights reserved.
//

#include <iostream>
using namespace std;
#define STACK_MAX 5

class Stack {
    int top;
public:
    Stack() {
        top = 0;
    }
    void push(double val);
    void pop();
    void disp();
    int vals[STACK_MAX];
};

void Stack::push(double val) {
    if (STACK_MAX == top) {
        cout << "Stack overflow" << endl;
    } else {
        vals[top] = val;
        top++;
    }
}

void Stack::pop() {
    if (top == 0) {
        cout << "Stack underflow" << endl;
    } else {
        top--;
        cout << vals[top] << endl;
    }
}

void Stack::disp() {
    for(int i=0;i<top;i++)
        cout << vals[i] << endl;
}


#define QUEUE_MAX 5
// [back]- ..[values].. -[front]
class Queue {
    int queue_front;
    int queue_back;
public:
    Queue() {
        queue_front = 0;
        queue_back = 0;
    }
    void enqueue(int x);
    int dequeue();
    void disp();
    int vals[];
};

void Queue::enqueue(int x) {
    if ((queue_front + 1) % QUEUE_MAX == queue_back) {
        cout << "Queue is fulfilled." << endl;
    } else {
        vals[queue_front] = x;
        queue_front = (queue_front + 1) % QUEUE_MAX;
    }
}

int Queue::dequeue() {
    if (queue_back == queue_front) {
        cout << "Queue is already empty." << endl;
        return 0;
    } else {
        cout << vals[queue_back] << endl;
        int result = vals[queue_back];
        queue_back = (queue_back + 1) % QUEUE_MAX;
        return result;
    }
}

void Queue::disp() {
    if (queue_back == queue_front) {
        cout << "Queue is empty." << endl;
    } else {
        for(int i = queue_back; i < queue_front; i++)
            cout << vals[i] << endl;
    }
}

int main(int argc, const char * argv[]) {
    Stack *test = new Stack();
    test->pop();
    test->push(1);
    test->push(2);
    test->push(3);
    test->disp();
    cout << "~~~~~~~~~~~" << endl;
    test->push(1);
    test->push(2);
    test->disp();
    test->push(3);
    cout << "~~~~~~~~~~~" << endl;
    test->pop();
    test->pop();
    test->pop();
    test->pop();
    test->pop();
    test->pop();
    
    
    cout << "~~~~~~~~~~~" << endl;
    Queue *testqueue = new Queue();
    testqueue->enqueue(1);
    testqueue->enqueue(2);
    testqueue->enqueue(3);
    testqueue->enqueue(4);
    testqueue->enqueue(5);
    cout << "~~~~~~~~~~~" << endl;
    testqueue->dequeue();
    cout << "~~~~~~~~~~~" << endl;
    testqueue->disp();
    
}
