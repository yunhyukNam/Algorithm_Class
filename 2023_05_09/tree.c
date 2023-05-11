#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>

#define TRUE    1
#define FALSE   0

typedef int NodeData;

typedef struct _TREENODE_ {
    NodeData data;              // data(=key)
    struct _TREENODE_*left;     // 왼쪽 자식 노드
    struct _TREENODE_*right;    // 오른쪽 자식 노드
} TREENODE;

typedef struct _NODEMAP_ {
    int flag;
    NodeData data;
} NODEMAP;

int getMax(int _a, int _b);
void printGivenLevel(TREENODE* _root, int _level, NODEMAP* _map, int _pos);
void showTree(TREENODE* _node);

TREENODE* makeRootNode(NodeData _data, TREENODE* _leftNode, TREENODE* _rightNode);
NodeData getData(TREENODE* _node);
void setData(TREENODE* node, NodeData data);
void makeLeftSubTree(TREENODE* _root, TREENODE* _leftSub);
void makeRightSubTree(TREENODE* _root, TREENODE* _rightSub);
TREENODE* getLeftSubTree(TREENODE* _node);
TREENODE* getRightSubTree(TREENODE* _node);

void main() {
    TREENODE* bt1 = NULL;
    TREENODE* bt2 = NULL;
    TREENODE* bt3 = NULL;
    TREENODE* bt4 = NULL;
    TREENODE* bt5 = NULL;
    TREENODE* bt6 = NULL;
    TREENODE* bt7 = NULL;
    TREENODE* bt8 = NULL;
    TREENODE* bt9 = NULL;

    bt1 = makeRootNode(1, NULL, NULL);
    
    printf("Height of root node : %d\n", getHeight(bt1));

    bt2 = makeRootNode(2, NULL, NULL);
    bt3 = makeRootNode(3, NULL, NULL);
    bt4 = makeRootNode(4, NULL, NULL);
    bt5 = makeRootNode(5, NULL, NULL);
    bt6 = makeRootNode(6, NULL, NULL);
    bt7 = makeRootNode(7, NULL, NULL);
    bt8 = makeRootNode(8, NULL, NULL);
    bt9 = makeRootNode(9, NULL, NULL);


    // makeLeftSubTree(bt1, bt2);
    // makeRightSubTree(bt2, bt3);
    // makeLeftSubTree(bt3, bt4);
    // makeRightSubTree(bt4, bt5);

    makeLeftSubTree(bt1, bt2);
    makeRightSubTree(bt1, bt3);
    makeLeftSubTree(bt2, bt4);
    makeRightSubTree(bt2, bt5);
    makeLeftSubTree(bt3, bt6);
    makeRightSubTree(bt3, bt7);
    makeLeftSubTree(bt4, bt8);
    makeRightSubTree(bt4, bt9);

    printf("Height of root node : %d\n", getHeight(bt1));

    printf("bt1's leftSubTree Data : %d\n", getData(getLeftSubTree(bt1)));
    printf("bt1's left of leftSubTree Data : %d\n", getData(getLeftSubTree(getLeftSubTree(bt1))));

    showTree(bt1);
}

int getMax(int _a, int _b) {
    return ((_a > _b) ? _a:_b);
}
int getHeight(TREENODE* _node) {
    int lH = 0;
    int rH = 0;

    if (_node == NULL) {
        return 0;
    }

    lH = getHeight(_node->left);
    rH = getHeight(_node->right);

    return (1 + getMax(lH, rH));
}

void printGivenLevel(TREENODE* _root, int _level, NODEMAP* _map, int _pos) {
    
    if (_root == NULL) {
        return;
    }

    if (_level == 1) {
        _map[_pos].data = _root->data;
        _map[_pos].flag = TRUE;
    }

    else if (_level > 1) {
        printGivenLevel(_root->left, _level - 1, _map, _pos*2);
        printGivenLevel(_root->right, _level - 1, _map, _pos*2+1);
    }
}

void showTree(TREENODE* _node) {
    int height = 0;
    int numOfNodes = 0;

    NODEMAP* treeArray = NULL;

    char** square = NULL;
    static int pos = 0;
    int cnt_i;
    int cnt_j;
    int position;
    int start, term, index;

    height = getHeight(_node)+1;

    if (height != 0) {
        numOfNodes = (1 << height);
    }

    treeArray = (NODEMAP*)calloc(numOfNodes, sizeof(NODEMAP));
    assert(treeArray != NULL);

    square = (char**)calloc(height, sizeof(char*));

    for (cnt_i = 0; cnt_i < height; cnt_i++) {
        square[cnt_i] = (char*)calloc(numOfNodes, sizeof(char));
        memset(square[cnt_i], '.', numOfNodes);
    }

    // level order 순으로 treeArray에 노드의 데이터 삽입
    pos = 1;
    
    for (cnt_i = 1; cnt_i <= height; cnt_i++) {
        printGivenLevel(_node, cnt_i, treeArray, pos);
    }

    // 한칸씩 왼쪽으로 이동
    for (cnt_i = 1; cnt_i <= numOfNodes; cnt_i++) {
        treeArray[cnt_i - 1] = treeArray[cnt_i];
    }
    
    pos = 0;
    start = (1 << (height-1))-1;
    term = (1 << (height));
    index = (1 << (height - 2));
    
    for (cnt_i = 0; cnt_i < height; cnt_i++) {
        for (cnt_j = start; cnt_j < numOfNodes; cnt_j += term) {
            /*if (treeArray[pos].flag == TRUE) {
                square[cnt_i][cnt_j] = (treeArray[pos].data+'0');
            }
            else {
                square[cnt_i][cnt_j] = '.';
            }
            pos += 1;*/
            if (treeArray[pos].flag == TRUE) {
                if (treeArray[pos].data >= 0 && treeArray[pos].data <= 9) {
                    square[cnt_i][cnt_j] = (treeArray[pos].data + '0');
                }
                else {
                    square[cnt_i][cnt_j] = (treeArray[pos].data);
                }
            }
            else {
                square[cnt_i][cnt_j] = '.';
            }
            pos += 1;
        }
        term >>= 1;
        start -= index;
        index >>= 1;
    }
    printf("\n");
    
    for (cnt_i = 0; cnt_i < height; cnt_i++) {
        for (cnt_j = 0; cnt_j < numOfNodes; cnt_j++) {
            printf("%c", square[cnt_i][cnt_j]);
        }
    printf("\n");
    }

    if (treeArray != NULL) {
        free(treeArray);
    }
    if (square != NULL) {
        for (cnt_i = 0; cnt_i < height; cnt_i++) {
            if (square[cnt_i] != NULL) {
                free(square[cnt_i]);
            }
        }
        free(square);
    }
}

TREENODE* makeRootNode (NodeData _data, TREENODE* _leftNode, TREENODE* _rightNode) {
    TREENODE* root = NULL;

    root = (TREENODE*)calloc(1, sizeof(TREENODE));
    assert(root != NULL);

    root->data = _data;
    root->left = _leftNode;
    root->right = _rightNode;

    return root;
}

NodeData getData(TREENODE* _node) {
    return (_node->data);
}

void setData(TREENODE* _node, NodeData _data) {
    _node->data = _data;
}

void makeLeftSubTree(TREENODE* _root, TREENODE* _leftSub) {
    _root->left = _leftSub;
}

void makeRightSubTree(TREENODE* _root, TREENODE* _rightSub) {
    _root->right = _rightSub;
}

TREENODE* getLeftSubTree(TREENODE* _node) {
    return (_node->left);
}

TREENODE* getRightSubTree(TREENODE* _node) {
    return (_node->right);
}
