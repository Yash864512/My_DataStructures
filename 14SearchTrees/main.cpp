//======================> Creating 2-3-4 Tree
/*
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a 2-3-4 Tree Node
typedef struct BTreeNode {
    int n;                      // Current number of keys in the node
    int keys[3];                // Array to store keys (max 3 keys)
    struct BTreeNode *child[4]; // Array of child pointers (max 4 children)
    int leaf;                   // Boolean flag: 1 if leaf, 0 if internal node
} BTreeNode;

// Global root of the tree
BTreeNode *root = NULL;

// Forward declaration for the recursive delete function
void deleteKeyRecursive(BTreeNode *x, int k);

BTreeNode *createNode(int leaf) {
    BTreeNode *newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
    newNode->n = 0;
    newNode->leaf = leaf;
    for (int i = 0; i < 3; i++) {
        newNode->keys[i] = 0;
    }
    for (int i = 0; i < 4; i++) {
        newNode->child[i] = NULL;
    }
    return newNode;
}

void traverse(BTreeNode *x) {
    int i;
    for (i = 0; i < x->n; i++) {
        if (x->leaf == 0) {
            traverse(x->child[i]);
        }
        printf(" %d", x->keys[i]);
    }
    if (x->leaf == 0) {
        traverse(x->child[i]);
    }
}

BTreeNode *search(BTreeNode *x, int k) {
    int i = 0;
    while (i < x->n && k > x->keys[i]) {
        i++;
    }
    if (i < x->n && x->keys[i] == k) {
        return x;
    }
    if (x->leaf == 1) {
        return NULL;
    }
    return search(x->child[i], k);
}

void splitChild(BTreeNode *x, int i, BTreeNode *y) {
    BTreeNode *z = createNode(y->leaf);
    z->n = 1;
    z->keys[0] = y->keys[2];
    y->n = 1;

    if (y->leaf == 0) {
        z->child[0] = y->child[2];
        z->child[1] = y->child[3];
    }

    for (int j = x->n; j >= i + 1; j--) {
        x->child[j + 1] = x->child[j];
    }
    x->child[i + 1] = z;

    for (int j = x->n - 1; j >= i; j--) {
        x->keys[j + 1] = x->keys[j];
    }
    x->keys[i] = y->keys[1];
    x->n = x->n + 1;
}

void insertNonFull(BTreeNode *x, int k) {
    int i = x->n - 1;
    if (x->leaf == 1) {
        while (i >= 0 && x->keys[i] > k) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = k;
        x->n = x->n + 1;
    } else {
        while (i >= 0 && x->keys[i] > k) {
            i--;
        }
        i++;
        if (x->child[i]->n == 3) {
            splitChild(x, i, x->child[i]);
            if (x->keys[i] < k) {
                i++;
            }
        }
        insertNonFull(x->child[i], k);
    }
}

void insert(int k) {
    if (root == NULL) {
        root = createNode(1);
        root->keys[0] = k;
        root->n = 1;
        return;
    }

    if (root->n == 3) {
        BTreeNode *s = createNode(0);
        s->child[0] = root;
        splitChild(s, 0, root);
        int i = 0;
        if (s->keys[0] < k) {
            i++;
        }
        insertNonFull(s->child[i], k);
        root = s;
    } else {
        insertNonFull(root, k);
    }
}

int findKey(BTreeNode *x, int k) {
    int idx = 0;
    while (idx < x->n && x->keys[idx] < k) {
        ++idx;
    }
    return idx;
}

void removeFromLeaf(BTreeNode *x, int idx) {
    for (int i = idx + 1; i < x->n; ++i) {
        x->keys[i - 1] = x->keys[i];
    }
    x->n--;
}

int getPred(BTreeNode *x, int idx) {
    BTreeNode *cur = x->child[idx];
    while (!cur->leaf) {
        cur = cur->child[cur->n];
    }
    return cur->keys[cur->n - 1];
}

int getSucc(BTreeNode *x, int idx) {
    BTreeNode *cur = x->child[idx + 1];
    while (!cur->leaf) {
        cur = cur->child[0];
    }
    return cur->keys[0];
}

void borrowFromPrev(BTreeNode *x, int idx) {
    BTreeNode *child = x->child[idx];
    BTreeNode *sibling = x->child[idx - 1];

    for (int i = child->n - 1; i >= 0; --i) {
        child->keys[i + 1] = child->keys[i];
    }
    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i) {
            child->child[i + 1] = child->child[i];
        }
    }
    child->keys[0] = x->keys[idx - 1];
    if (!child->leaf) {
        child->child[0] = sibling->child[sibling->n];
    }
    x->keys[idx - 1] = sibling->keys[sibling->n - 1];
    child->n += 1;
    sibling->n -= 1;
}

void borrowFromNext(BTreeNode *x, int idx) {
    BTreeNode *child = x->child[idx];
    BTreeNode *sibling = x->child[idx + 1];
    child->keys[(child->n)] = x->keys[idx];
    if (!(child->leaf)) {
        child->child[(child->n) + 1] = sibling->child[0];
    }
    x->keys[idx] = sibling->keys[0];
    for (int i = 1; i < sibling->n; ++i) {
        sibling->keys[i - 1] = sibling->keys[i];
    }
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i) {
            sibling->child[i - 1] = sibling->child[i];
        }
    }
    child->n += 1;
    sibling->n -= 1;
}

void merge(BTreeNode *x, int idx) {
    BTreeNode *child = x->child[idx];
    BTreeNode *sibling = x->child[idx + 1];

    child->keys[1] = x->keys[idx];

    for (int i = 0; i < sibling->n; ++i) {
        child->keys[i + 2] = sibling->keys[i];
    }

    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i) {
            child->child[i + 2] = sibling->child[i];
        }
    }

    for (int i = idx + 1; i < x->n; ++i) {
        x->keys[i - 1] = x->keys[i];
    }
    for (int i = idx + 2; i <= x->n; ++i) {
        x->child[i - 1] = x->child[i];
    }

    child->n += sibling->n + 1;
    x->n--;
    free(sibling);
}

void fill(BTreeNode *x, int idx) {
    if (idx != 0 && x->child[idx - 1]->n >= 2) {
        borrowFromPrev(x, idx);
    } else if (idx != x->n && x->child[idx + 1]->n >= 2) {
        borrowFromNext(x, idx);
    } else {
        if (idx != x->n) {
            merge(x, idx);
        } else {
            merge(x, idx - 1);
        }
    }
}

void removeFromNonLeaf(BTreeNode *x, int idx) {
    int k = x->keys[idx];
    if (x->child[idx]->n >= 2) {
        int pred = getPred(x, idx);
        x->keys[idx] = pred;
        deleteKeyRecursive(x->child[idx], pred);
    } else if (x->child[idx + 1]->n >= 2) {
        int succ = getSucc(x, idx);
        x->keys[idx] = succ;
        deleteKeyRecursive(x->child[idx + 1], succ);
    } else {
        merge(x, idx);
        deleteKeyRecursive(x->child[idx], k);
    }
}

void deleteKeyRecursive(BTreeNode *x, int k) {
    int idx = findKey(x, k);

    if (idx < x->n && x->keys[idx] == k) {
        if (x->leaf) {
            removeFromLeaf(x, idx);
        } else {
            removeFromNonLeaf(x, idx);
        }
    } else {
        if (x->leaf) {
            return;
        }
        int flag = (idx == x->n);
        
        if (x->child[idx]->n < 2) {
            fill(x, idx);
        }
        
        if (flag && idx > x->n) {
            deleteKeyRecursive(x->child[idx - 1], k);
        } else {
            deleteKeyRecursive(x->child[idx], k);
        }
    }
}

void deleteKey(int k) {
    if (!root) {
        return;
    }
    deleteKeyRecursive(root, k);

    if (root->n == 0) {
        BTreeNode *tmp = root;
        if (root->leaf) {
            root = NULL;
        } else {
            root = root->child[0];
        }
        free(tmp);
    }
}

int main() {
    printf("Inserting values into the 2-3-4 tree...\n");
    int keys_to_insert[] = {10, 20, 5, 6, 12, 30, 7, 17, 15, 25, 35, 40, 50};
    int n_insert = sizeof(keys_to_insert) / sizeof(keys_to_insert[0]);

    for(int i = 0; i < n_insert; i++) {
        insert(keys_to_insert[i]);
    }

    printf("\nInitial tree state:");
    traverse(root);
    printf("\n\n--- Deletion Phase ---\n\n");
    
    int keys_to_delete[] = {6, 12, 30, 10, 50, 20};
    int n_delete = sizeof(keys_to_delete) / sizeof(keys_to_delete[0]);
    
    for(int i = 0; i < n_delete; i++) {
        printf("Deleting %d\n", keys_to_delete[i]);
        // Call the renamed function here
        deleteKey(keys_to_delete[i]);
        printf("Tree after deletion:");
        if (root) {
            traverse(root);
        } else {
            printf(" Tree is empty.");
        }
        printf("\n\n");
    }
    
    return 0;
}
*/

//===========================> Creating Red-Black Tree

#include <stdio.h>
#include <stdlib.h>

// Enum for Red-Black Tree node colors
typedef enum { RED, BLACK } Color;

// Structure for a Red-Black Tree node
typedef struct Node {
    int data;            // The data stored in the node
    Color color;         // Color of the node (RED or BLACK)
    struct Node *parent; // Pointer to the parent node
    struct Node *left;   // Pointer to the left child
    struct Node *right;  // Pointer to the right child
} Node;

// A global pointer to the root of the tree
Node *root = NULL;

// Function prototypes for insertion fixup and rotations
void fixInsert(Node *z);
void leftRotate(Node *x);
void rightRotate(Node *y);

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    // New nodes are always inserted as RED
    newNode->color = RED;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

void leftRotate(Node *x) {
    // 'y' is the right child of 'x'
    Node *y = x->right;
    
    // Turn y's left subtree into x's right subtree
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    
    // Link x's parent to y
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y; // 'y' is now the root
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    
    // Put x on y's left
    y->left = x;
    x->parent = y;
}

void rightRotate(Node *y) {
    // 'x' is the left child of 'y'
    Node *x = y->left;
    
    // Turn x's right subtree into y's left subtree
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }
    
    // Link y's parent to x
    x->parent = y->parent;
    if (y->parent == NULL) {
        root = x; // 'x' is now the root
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    
    // Put y on x's right
    x->right = y;
    y->parent = x;
}

void insert(int data) {
    Node *z = createNode(data);
    Node *y = NULL;
    Node *x = root;
    
    // Standard BST insert: find the parent 'y' for the new node 'z'
    while (x != NULL) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    
    // Link the new node 'z' with its parent 'y'
    z->parent = y;
    if (y == NULL) {
        root = z; // The tree was empty
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }
    
    // Fix any Red-Black Tree property violations
    fixInsert(z);
}

void fixInsert(Node *z) {
    // The loop continues as long as the parent of 'z' is RED.
    // This violates the property that RED nodes cannot have RED children.
    while (z != root && z->parent->color == RED) {
        // Case A: Parent is a LEFT child
        if (z->parent == z->parent->parent->left) {
            Node *uncle = z->parent->parent->right;
            // Case 1: The uncle is also RED
            if (uncle != NULL && uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent; // Move z up to grandparent
            } else {
                // Case 2: 'z' is a right child (triangle case)
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                // Case 3: 'z' is a left child (line case)
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } 
        // Case B: Parent is a RIGHT child (symmetric to Case A)
        else {
            Node *uncle = z->parent->parent->left;
            // Case 1: The uncle is also RED
            if (uncle != NULL && uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                // Case 2: 'z' is a left child (triangle case)
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                // Case 3: 'z' is a right child (line case)
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    // The root must always be BLACK to satisfy property 2.
    root->color = BLACK;
}

void inorderTraversal(Node *node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    printf("%d (%s) ", node->data, node->color == RED ? "RED" : "BLACK");
    inorderTraversal(node->right);
}

int main() {
    printf("Creating a Red-Black Tree...\n");
    int keys_to_insert[] = {10, 20, 30, 40, 50, 25, 5, 15};
    int n = sizeof(keys_to_insert) / sizeof(keys_to_insert[0]);

    for (int i = 0; i < n; i++) {
        printf("Inserting: %d\n", keys_to_insert[i]);
        insert(keys_to_insert[i]);
    }

    printf("\nIn-order traversal of the Red-Black Tree:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}