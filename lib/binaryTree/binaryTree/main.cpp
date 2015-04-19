//
//  main.cpp
//  binaryTree
//
//  Created by 高橋 誠二 on 2015/03/31.
//  Copyright (c) 2015年 高橋 誠二. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct _tag_tree_node {
    int value;
    struct _tag_tree_node *left;
    struct _tag_tree_node *right;
} tree_node;

tree_node *tree_root = NULL;

tree_node* create_new_node(int num) {
    tree_node *tree_new;
    tree_new = (tree_node *)malloc(sizeof(tree_node));
    if (tree_new == NULL) {
        exit(EXIT_FAILURE);
    }
    tree_new->left = NULL;
    tree_new->right = NULL;
    tree_new->value = num;
    
    return tree_new;
}

void insert_tree(int num, tree_node *node) {
    if (node == NULL) {
        tree_root = create_new_node(num);
        return;
    }
    
    if (node->value > num) {
        if (node->left != NULL) {
            insert_tree(num, node->left);
        } else {
            node->left = create_new_node(num);
        }
    } else {
        if (node->right != NULL) {
            insert_tree(num, node->right);
        } else {
            node->right = create_new_node(num);
        }
    }
    
    return;
}

int delete_tree(int val) {
    tree_node *node, *parent_node;
    tree_node *left_biggest;
    int direction;
    
    node = tree_root;
    parent_node = NULL;
    direction = 0;
    
    while (node != NULL && node->value != val) {
        if (node->value > val) {
            parent_node = node;
            node = node->left;
            direction = -1;
        } else {
            parent_node = node;
            node = node->right;
            direction = 1;
        }
    }
    
    if (node == NULL) {
        return 0;
    }
    
    if (node->left == NULL || node->right == NULL) {
        if (node->left == NULL) {
            if (direction == -1) {
                parent_node->left = node->right;
            }
            if (direction == 1) {
                parent_node->right = node->right;
            }
            if (direction == 0) {
                tree_root = node->right;
            }
        } else {
            if (direction == -1) {
                parent_node->left = node->left;
            }
            if (direction == 1) {
                parent_node->right = node->left;
            }
            if (direction == 0) {
                tree_root = node->left;
            }
        }
        free(node);
    } else {
        left_biggest = node->left;
        parent_node = node;
        direction = -1;
        while (left_biggest->right != NULL) {
            parent_node = left_biggest;
            left_biggest = left_biggest->right;
            direction = 1;
        }
        
        node->value = left_biggest->value;
        // ここのleft_biggest->leftはNULLが返ってくる。
        // parent_nodeがどこであれ、NULLが返る。
        if (direction == -1) {
            parent_node->left = left_biggest->left;
        } else {
            parent_node->right = left_biggest->left;
        }
        free(left_biggest);
    }
    
    return 1;
}

void print_tree(int depth, tree_node *node) {
    int i;
    if (node == NULL) {
        return;
    }
    print_tree(depth+1, node->left);
    for (i=0; i<depth; i++) {
        printf("  ");
    }
    printf("%d\n", node->value);
    print_tree(depth+1, node->right);
}

int main(void) {
    int i, delete_target = 0;
    for (i=0;i<10;i++) {
        int val = rand()%99;
        printf("%i|",val);
        insert_tree(val, tree_root);
        if(i == 7){
            delete_target = val;
        }
    }
    printf("\n");
    print_tree(0, tree_root);
    delete_tree(delete_target);
    printf("===============\n");
    printf("%i\n", delete_target);
    printf("===============\n");
    print_tree(0, tree_root);
}