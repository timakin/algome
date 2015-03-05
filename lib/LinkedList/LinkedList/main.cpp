//
//  main.cpp
//  LinkedList
//
//  Created by 高橋 誠二 on 2015/03/04.
//  Copyright (c) 2015年 高橋 誠二. All rights reserved.
//

#include <iostream>
using namespace std;

class Node {
    int data;
    Node *next;
  public:
    Node() {cout<<"Object Node created.\n";};
    void setData(int tmpData){ data = tmpData; };
    void setNext(Node *tmpNext){ next = tmpNext; };
    int Data() { return data; };
    Node* Next() { return next; };
};

class List {
    Node *head;
  public:
    List() { head = NULL; };
    void Print();
    void Append(int data);
    void Delete(int data);
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Node* testnode = new Node();
    testnode->next = 0;
    testnode->data = 100;
    
    return testnode;
}
