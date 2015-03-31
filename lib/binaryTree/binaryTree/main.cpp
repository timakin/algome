//
//  main.cpp
//  binaryTree
//
//  Created by 高橋 誠二 on 2015/03/31.
//  Copyright (c) 2015年 高橋 誠二. All rights reserved.
//

#include <iostream>

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
    void disp();
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
    int direction = 0; // 親のどちら側に値が存在していたか。
    
    // 削除する対象を見つける
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
    // 見つかったら、searchNodeと同様にそのnode自体を値として持つ。
    if (node->left == NULL || node->right == NULL) {
        if (node->left == NULL) {
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
        TreeNode *leftBiggest = node->left;
        parent = node;
        direction = -1;
        while (leftBiggest->right != NULL) {
            parent = leftBiggest;
            leftBiggest
        }
    }
    return true;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
