#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#define TRUE    1
#define FALSE   0

typedef char element;
typedef int NodeData;

typedef struct _TREENODE_ {
    element key;
    struct _TREENODE_* left;
    struct _TREENODE_* right;
} TREENODE;

typedef struct _NODEMAP_ {
    int flag;
    NodeData data;
} NODEMAP;

TREENODE* searchNode(TREENODE* _root, char _x);
TREENODE* searchNode_recur(TREENODE* _root, char _x);

void insertNode(TREENODE** _p, char _x);
TREENODE* insertNode_recur(TREENODE* _p, char _x);

void deleteNode(TREENODE** _p, char _x);
TREENODE* deleteNode_recur(TREENODE* _root, int _key);

TREENODE* min_value_node(TREENODE* _node) {
    TREENODE* current = _node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

TREENODE* searchNode(TREENODE* _root, char _x) {
    TREENODE* p = NULL;
    p = _root;

    while (p != NULL) {
        if (_x < p->key) {
            p = p->left;
        }
        else if (_x == p->key) {
            return p;
        }
        else {
            p = p->right;
        }
    }
    printf("\n Your Key Not Found\n");

    return p;
}

TREENODE* searchNode_recur(TREENODE* _root, char _x) {
    TREENODE* p = NULL;
    p = _root;

    while (p != NULL) {
        if (_x < p->key) {
            return searchNode_recur(p->left, _x);
        }
        else if (_x == p->key) {
            return p;
        }
        else {
            return searchNode_recur(p->right, _x);
        }
    }

    return p;
}

void insertNode(TREENODE** p, char _x) {
    TREENODE* newNode = NULL;
    TREENODE* cur = *p;
    TREENODE* q = NULL;

    while (cur != NULL) {
        if (cur->key == _x) {
            printf("Same Key is Already Here\n");
            return;
        }
        q = cur;

        if (_x < cur->key) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }

        newNode = (TREENODE*)calloc(1, sizeof(TREENODE));
        newNode->key = _x;
        newNode->left = NULL;
        newNode->right = NULL;

        if (q != NULL) {
            if (_x < q->key) {
                q->left = newNode;
            }
            else {
                q->right = newNode;
            }
        }
        else {
            *p = newNode;
        }
    }
}

TREENODE* insertNode_recur(TREENODE* p, char _x) {
    TREENODE* newNode = NULL;

    if (p == NULL) {
        newNode = (TREENODE*)calloc(1, sizeof(TREENODE));
        newNode->key = _x;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    else if (_x < p->key) {
        p->left = insertNode_recur(p->left, _x);
    }
    else if (_x > p->key) {
        p->right = insertNode_recur(p->right, _x);
    }
    else {
        printf("Same Key is Already Here\n");
    }
    return p;
}

