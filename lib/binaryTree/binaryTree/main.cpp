//
//  main.cpp
//  binaryTree
//
//  Created by 高橋 誠二 on 2015/03/31.
//  Copyright (c) 2015年 高橋 誠二. All rights reserved.
//

#include <iostream>
using namespace std;

class TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(int num) {
        value = num;
        left = right = NULL;
    }
    void insertNode(TreeNode* parent, int num);
    TreeNode* searchNode(TreeNode* node, int val);
    bool deleteNode(int num);
    void disp(int depth, TreeNode* node);
};

TreeNode *treeRoot = NULL;

void TreeNode::insertNode(TreeNode* parent, int num) {
    if (parent == NULL) {
        treeRoot = new TreeNode(num);
        return;
    }
    if (num < parent->value) {
        if (parent->left != NULL) {
            insertNode(parent->left, num);
        } else {
            parent->left = new TreeNode(num);
        }
    } else {
        if (parent->right != NULL) {
            insertNode(parent->right, num);
        } else {
            parent->right = new TreeNode(num);
        }
    }
    return;
}

TreeNode* TreeNode::searchNode(TreeNode* node, int num) {
    if (num < node->value) {
        if (node->left == NULL) {
            return NULL;
        }
        return searchNode(node->left, num);
    }
    if (node->value < num) {
        if (node->right == NULL) {
            return NULL;
        }
        return searchNode(node->right, num);
    }
    // 左右どちらとも大小が決められないなら、その値自体が探しているnode。
    return node;
}

bool TreeNode::deleteNode(int num) {
    TreeNode *node = treeRoot;
    TreeNode *parent = NULL;
    int direction = 0; // 親のどちら側に値が存在していたか。左なら-1、右なら1。
    
    // 削除する対象を見つける(searchNodeと同じ)
    while (node != NULL && node->value != num) {
        if (num < node->value) {
            parent = node;
            node = node->left;
            direction = -1;
        } else {
            parent = node;
            node = node->right;
            direction = 1;
        }
    }
    if (node == NULL) {
        return false;
    }
    // node == numしか以下には進めない。
    // 見つかったら、searchNodeと同様にそのnode自体を値として持つ。
    if (node->left == NULL || node->right == NULL) {
        // 左か右のどちらかがNULL立った場合。両方NULLも含む。
        if (node->left == NULL) {
            // 親のポインタを変更する
            if (direction == -1) {
                parent->left = node->right;
            } else if (direction == 1) {
                parent->right = node->right;
            } else if (direction == 0) {
                treeRoot = node->right;
            }
        } else {
            if (direction == -1) {
                parent->left = node->left;
            } else if (direction == 1) {
                parent->right = node->left;
            } else if (direction == 0) {
                treeRoot = node->left;
            }
        }
    } else {
        // 両方ともnullじゃなかった場合。
        // つまりnodeの左右に子ノードがくっついてて、それらを考慮して
        // delete作業を行わなければならない場合。
        // この場合、左側の中で一番大きな値と入れ替えてから削除することで、
        // 左右の均衡を保ちつつ、適切に値が削除できる。
        TreeNode *leftBiggest = node->left;
        parent = node;
        direction = -1;
        while (leftBiggest->right != NULL) {
            parent = leftBiggest;
            leftBiggest = leftBiggest->right;
            direction = 1;
        }
        
        // leftBiggestの値をnodeに代入し、
        // leftBiggestは左側の枝を入れる。
        node->value = leftBiggest->value;
        if (direction == -1) {
            parent->left = leftBiggest->left;
        } else {
            parent->right = leftBiggest->left;
        }
    }
    return true;
}

void TreeNode::disp(int depth, TreeNode* node) {
    if (node == NULL) {
        cout << "node is empty" << endl;
    }
    disp(depth+1, node->left);
    for (int i = 0; i < depth; i++) {
        cout << "  " << endl;
    }
    cout << node->value << endl;
    disp(depth+1, node->right);
}



int main(int argc, const char * argv[]) {
}
