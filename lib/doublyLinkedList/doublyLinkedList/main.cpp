//
//  main.cpp
//  doublyLinkedList
//
//  Created by 高橋 誠二 on 2015/03/28.
//  Copyright (c) 2015年 高橋 誠二. All rights reserved.
//

#include <iostream>
using namespace std;


// [prevPointer | value | nextPointer]
struct Node {
    double value;
    Node *Next, *Prev;
    Node (double arg) {
        value = arg;
        Next = Prev = NULL;
    }
};

// [appendedFrontNode]->[front | ... | back]->[appendedBackNode]
class doublyLinkedList {
    Node *front;
    Node *back;
public:
    doublyLinkedList(){
        front = NULL;
        back  = NULL;
    }
    // クラスを破棄する際に全てのリストの値をリセットする
    ~doublyLinkedList(){
        destroyList();
    }
    void appendNodeFront(double x);
    void appendNodeBack(double x);
    void dispNodeForward(); // 前方から順に表示
    void dispNodeReverse(); // 後方から順に表示
    void destroyList();
};

void doublyLinkedList::appendNodeFront(double x) {
    Node *n = new Node(x);
    // 先頭だったとき
    if (front == NULL) {
        front = n;
        back = n;
    } else {
        front->Prev = n;
        n->Next = front;
        // リスト全体の最初の値を更新する
        front = n;
    }
}

void doublyLinkedList::appendNodeBack(double x) {
    Node *n = new Node(x);
    // 先頭だった時
    if (back == NULL) {
        front = n;
        back  = n;
    } else {
        back->Next = n;
        n->Prev = back;
        // リスト全体の最後の値を更新する
        back = n;
    }
}

void doublyLinkedList::dispNodeForward(){
    Node *temp = front;
    cout << "\n\nNodes in forward order:" << endl;
    while (temp != NULL) {
        cout << temp->value << "  ";
        temp = temp->Next;
    }
}

void doublyLinkedList::dispNodeReverse(){
    Node *temp = back;
    cout << "\n\nNodes in reverse order:" << endl;
    while (temp != NULL) {
        cout << temp->value << "  ";
        temp = temp->Prev;
    }
}

void doublyLinkedList::destroyList(){
    // 最後の方から消してく
    Node *T = back;
    while (T != NULL) {
        // 現在の値を消したら、次に消す予定の前方に移れるようにする
        Node *deleteTarget = T;
        T = T->Prev;
        delete deleteTarget;
    }
    front = NULL;
    back = NULL;
}

int main(int argc, const char * argv[]) {
    doublyLinkedList *list = new doublyLinkedList();
    //append nodes to front of the list
    for( int i = 1 ; i < 4 ; i++)
        list->appendNodeFront(i);

    list->dispNodeForward();
    list->dispNodeReverse();

    //append nodes to back of the list
    for( int i = 1 ; i < 4 ; i++)
        list->appendNodeBack(i);
    cout << endl << endl;
    list->dispNodeForward();
    list->dispNodeReverse();

    cout << endl << endl;
    delete list;

    for( int i = 1 ; i < 4 ; i++)
        list->appendNodeFront(i);
    list->dispNodeForward();
    return 0;

}
