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
}
