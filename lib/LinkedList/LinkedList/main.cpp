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
    Node* next;
  public:
    Node() {};
    void setData(int tmpData){ data = tmpData; };
    void setNext(Node* tmpNext){ next = tmpNext; };
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

void List::Print() {
    Node *tmp = head;
    // 要素がない場合。
    if (tmp == NULL) {
        cout << "EMPTY" << endl;
        return;
    }
    
    // 一個しかない場合。
    if (tmp->Next() == NULL) {
        cout << tmp->Data();
        cout << "-->";
        cout << "NULL" << endl;
    } else {
        // 複数ある場合。
        do {
            cout << tmp->Data();
            cout << "-->";
            tmp = tmp->Next();
        } while (tmp != NULL);
        cout << "NULL" << endl;
    }
};

void List::Append(int data) {
    // 次のノード
    Node* newNode = new Node();
    newNode->setData(data);
    newNode->setNext(NULL);
    
    // 一時的にノードのアドレスをつくる。
    // 初期状態はnull
    Node *tmp = head;
    if (tmp != NULL) {
        // ノードがすでに存在していたら、
        // 最後のノードにたどり着くまで移動
        while(tmp->Next() != NULL) {
            tmp = tmp->Next();
        }
        tmp->setNext(newNode);
    } else {
        // 上記のようなheadがnullの状態、つまり空の状態では、
        // そのままheadにnewNodeを入れる。
        head = newNode;
    }
};

void List::Delete(int data) {
    Node *tmp = head;
    
    // 初期状態の場合。何も消せないのでreturn
    if (tmp == NULL) {
        return;
    }
    
    // １個しか値がない場合。
    if (tmp->Next() == NULL) {
        delete tmp;
        head = NULL;
    // 複数入ってる場合。
    } else {
        // データを
        Node *prev;
        do {
            // 目標のデータがあったらよし
            if (tmp->Data() == data) break;
            prev = tmp;
            tmp = tmp->Next();
        } while (tmp!=NULL);
        // 消したデータの次の値を、前の値につなぐ
        prev->setNext(tmp->Next());
        delete tmp;
    }
};

int main()
{
    // New list
    List list;
    
    // Append nodes to the list
    list.Append(100);
    list.Print();
    list.Append(200);
    list.Print();
    list.Append(300);
    list.Print();
    list.Append(400);
    list.Print();
    list.Append(500);
    list.Print();
    
    // Delete nodes from the list
    list.Delete(400);
    list.Print();
    list.Delete(300);
    list.Print();
    list.Delete(200);
    list.Print();
    list.Delete(500);
    list.Print();
    list.Delete(100);
    list.Print();
}