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

void deleteNode(TREENODE** root, element key) {
    TREENODE *parent = NULL, *p = NULL, *succ = NULL, *succ_parent = NULL;
    TREENODE *child = NULL;

    p = *root;

    while ((p != NULL) && (p->key != key)) {
        parent = p;

        if (key < p->key) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }

    if (p == NULL) {
        printf("\n Your Key is Not Found!\n");
    }

    if ((p->left == NULL) && (p->right == NULL)) {
        if (parent != NULL) {
            if (parent->left == p) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
        }
        else {
            *root = NULL;
        }
    }
    else if ((p->left == NULL) || (p->right == NULL)) {
        if (p->right != NULL) {
            child = p->left;
        }
        else {
            child = p->right;
        }

        if (parent != NULL) {
            if (parent->left == p) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
    }
    else {
        succ_parent = p;

        succ = p->left;

        while (succ->right != NULL) {
            succ_parent = succ;
            succ = succ->right;
        }

        if (succ_parent->left == succ) {
            succ_parent->left = succ->left;
        }
        else {
            succ_parent->right = succ->right;
        }        
        p->key = succ->key;
        p = succ;
    }
    free(p);
}

TREENODE* deleteNode_recur (TREENODE* root, int key) {
    TREENODE* temp;

    if (root == NULL) {
        return root;
    }

    if (key < root -> key) {
        root->left = deleteNode_recur(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode_recur(root->right, key);
    }
    else {
        if (root->left == NULL) {
            temp = root->right;
            free(root);

            return temp;
        }
        else if (root->right == NULL) {
            temp = root->left;

            return temp;
        }

        temp = min_value_node(root->right);

        root->key = temp->key;
        root->right = deleteNode_recur(root->right, temp->key);
    }
    return root;
}

int main(void) {
    TREENODE* root = NULL;
    TREENODE* foundedNode = NULL;

    char choice, key;
    int cnt_i;

    root = insertNode(root, 'h');
    root = insertNode(root, 'h');
    root = insertNode(root, 'h');
    root = insertNode(root, 'h');
    root = insertNode(root, 'h');
    root = insertNode(root, 'h');
    root = insertNode(root, 'h');
    root = insertNode(root, 'h');

    while (1) {
        menu();
        scanf(" %c", &choice);

        switch (choice - '0') {
        case 1:
            displayInorder(root), printf("\n");
            showTree(root);

            break;
        
        case 2:
            insertNode(&root, key);
            insertNode_recur(root, key);

            break;

        case 3:
            scanf(" %c, &key");
            deleteNode(&root, key);

        case 4:
            scanf(" %c", &key);

        default:
            break;
        }
    }
}