//===============================> Binary tree using Recursion
/*
#include <iostream>
#include <stdio.h>

using namespace std;

class Node {
public:
    Node *lchild;
    int data;
    Node *rchild;

    Node() : lchild(nullptr), data(0), rchild(nullptr) {}
    Node(int val) : lchild(nullptr), data(val), rchild(nullptr) {}
};

class Queue {
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue() {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }

    Queue(int size) {
        front = rear = -1;
        this->size = size;
        Q = new Node *[this->size];
    }

    ~Queue() {
        delete[] Q;
    }

    void enqueue(Node *x) {
        if (rear == size - 1) {
            printf("Queue Full\n");
        } else {
            rear++;
            Q[rear] = x;
        }
    }

    Node *dequeue() {
        Node *x = nullptr;
        if (front == rear) {
            printf("Queue is Empty\n");
        } else {
            front++;
            x = Q[front];
        }
        return x;
    }

    int isEmpty() {
        return front == rear;
    }
};

class Tree {
private:
    Node *root;

public:
    Tree() {
        root = nullptr;
    }

    void CreateTree();

    void Preorder() { Preorder(root); }
    void Inorder() { Inorder(root); }
    void Postorder() { Postorder(root); }
    void Levelorder() { Levelorder(root); }
    int Height() { return Height(root); }

private:
    void Preorder(Node *p);
    void Inorder(Node *p);
    void Postorder(Node *p);
    void Levelorder(Node *p);
    int Height(Node *root);
};

void Tree::CreateTree() {
    Node *p, *t = nullptr;
    int x;
    Queue q(100);

    printf("Enter root value: ");
    scanf("%d", &x);

    root = new Node(x);
    q.enqueue(root);

    while (!q.isEmpty()) {
        p = q.dequeue();

        printf("Enter left child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = new Node(x);
            p->lchild = t;
            q.enqueue(t);
        }

        printf("Enter right child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = new Node(x);
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p) {
    if (p) {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void Tree::Levelorder(Node *p) {
    if (!p) return;

    Queue q(100);
    printf("%d ", p->data);
    q.enqueue(p);

    while (!q.isEmpty()) {
        p = q.dequeue();

        if (p->lchild) {
            printf("%d ", p->lchild->data);
            q.enqueue(p->lchild);
        }
        if (p->rchild) {
            printf("%d ", p->rchild->data);
            q.enqueue(p->rchild);
        }
    }
}

int Tree::Height(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    int x = Height(root->lchild);
    int y = Height(root->rchild);

    return (x > y ? x : y) + 1;
}

int main() {
    Tree t;

    printf("Let's create your binary tree!\n");
    t.CreateTree();

    cout << "--- Tree Traversals ---" << endl;

    cout << "Preorder: ";
    t.Preorder();
    cout << endl;

    cout << "Inorder: ";
    t.Inorder();
    cout << endl;

    cout << "Postorder: ";
    t.Postorder();
    cout << endl;

    cout << "Levelorder: ";
    t.Levelorder();
    cout << endl;

    cout << "Height of the tree: " << t.Height() << endl;

    return 0;
}
*/

//===============================> Binary tree using iterative approach
/*
#include <iostream>
#include <queue>
#include <stack>
#include <cstdint>

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;

    Node() : lchild(nullptr), data(0), rchild(nullptr) {}
    Node(int val) : lchild(nullptr), data(val), rchild(nullptr) {}
};

class Tree {
private:
    Node* root;

    void destroyTree(Node* node) {
        if (node) {
            destroyTree(node->lchild);
            destroyTree(node->rchild);
            delete node;
        }
    }

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        destroyTree(root);
    }

    void CreateTree();

    void Preorder(Node* p);
    void Preorder() { Preorder(root); }

    void Inorder(Node* p);
    void Inorder() { Inorder(root); }

    void Postorder(Node* p);
    void Postorder() { Postorder(root); }

    void iterativePreorder();
    void iterativeInorder();
    void iterativePostorder();
};

void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    std::queue<Node*> q;

    root = new Node();
    std::cout << "Enter root value: ";
    std::cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.push(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        std::cout << "Enter left child of " << p->data << " (-1 for no child): ";
        std::cin >> x;
        if (x != -1) {
            t = new Node(x);
            p->lchild = t;
            q.push(t);
        }

        std::cout << "Enter right child of " << p->data << " (-1 for no child): ";
        std::cin >> x;
        if (x != -1) {
            t = new Node(x);
            p->rchild = t;
            q.push(t);
        }
    }
}

void Tree::Preorder(Node *p) {
    if (p) {
        std::cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p) {
    if (p) {
        Inorder(p->lchild);
        std::cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        std::cout << p->data << " ";
    }
}

void Tree::iterativePreorder() {
    std::stack<Node*> stk;
    Node* p = root;

    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            std::cout << p->data << " ";
            stk.push(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    std::cout << std::endl;
}

void Tree::iterativeInorder() {
    std::stack<Node*> stk;
    Node* p = root;

    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            stk.push(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            std::cout << p->data << " ";
            p = p->rchild;
        }
    }
    std::cout << std::endl;
}

void Tree::iterativePostorder() {
    std::stack<intptr_t> stk;
    Node* p = root;
    intptr_t temp;

    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            stk.push(reinterpret_cast<intptr_t>(p));
            p = p->lchild;
        } else {
            temp = stk.top();
            stk.pop();
            if (temp > 0) {
                stk.push(-temp);
                p = reinterpret_cast<Node*>(temp)->rchild;
            } else {
                std::cout << reinterpret_cast<Node*>(-temp)->data << " ";
                p = nullptr;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    Tree t;

    t.CreateTree();

    std::cout << "Recursive Preorder: ";
    t.Preorder();
    std::cout << std::endl;

    std::cout << "Recursive Inorder: ";
    t.Inorder();
    std::cout << std::endl;

    std::cout << "Recursive Postorder: ";
    t.Postorder();
    std::cout << std::endl;

    std::cout << "Iterative Preorder: ";
    t.iterativePreorder();

    std::cout << "Iterative Inorder: ";
    t.iterativeInorder();

    std::cout << "Iterative Postorder: ";
    t.iterativePostorder();

    return 0;
}
*/

//===============================> Generating tree from traversal
/*
#include <iostream>
#include <queue>
#include <stack>
#include <cstdint> // For intptr_t

using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;

    Node() : lchild(nullptr), data(0), rchild(nullptr) {}
    Node(int data) : lchild(nullptr), data(data), rchild(nullptr) {}
};

class Tree {
private:
    void destroyTree(Node* node);

public:
    Node* root;
    Tree();
    ~Tree();
    void CreateTree();
    void Preorder(Node* p);
    void Preorder() { Preorder(root); }
    void Inorder(Node* p);
    void Inorder() { Inorder(root); }
    void Postorder(Node* p);
    void Postorder() { Postorder(root); }
    void Levelorder(Node* p);
    void Levelorder() { Levelorder(root); }
    int Height(Node* p);
    int Height() { return Height(root); }
    void iterativePreorder(Node* p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node* p);
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node* p);
    void iterativePostorder() { iterativePostorder(root); }
    Node* generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd, int& preIndex);
};

void Tree::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->lchild);
        destroyTree(node->rchild);
        delete node;
    }
}

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    destroyTree(root);
}

void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    root = new Node();
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            t = new Node(x);
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            t = new Node(x);
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}

void Tree::Preorder(Node *p) {
    if (p) {
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p) {
    if (p) {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void Tree::Levelorder(Node *p) {
    queue<Node*> q;
    if (!p) return;
    cout << p->data << ", " << flush;
    q.emplace(p);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        if (p->lchild) {
            cout << p->lchild->data << ", " << flush;
            q.emplace(p->lchild);
        }

        if (p->rchild) {
            cout << p->rchild->data << ", " << flush;
            q.emplace(p->rchild);
        }
    }
}

int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;
    if (p == nullptr) {
        return 0;
    }

    l = Height(p->lchild);
    r = Height(p->rchild);

    if (l > r) {
        return l + 1;
    } else {
        return r + 1;
    }
}

void Tree::iterativePreorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            cout << p->data << ", " << flush;
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativeInorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativePostorder(Node *p) {
    stack<intptr_t> stk;
    intptr_t temp;
    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            stk.emplace(reinterpret_cast<intptr_t>(p));
            p = p->lchild;
        } else {
            temp = stk.top();
            stk.pop();
            if (temp > 0) {
                stk.emplace(-temp);
                p = reinterpret_cast<Node*>(temp)->rchild;
            } else {
                cout << reinterpret_cast<Node*>(-temp)->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}

int searchInorder(int inArray[], int inStart, int inEnd, int data) {
    for (int i = inStart; i <= inEnd; i++) {
        if (inArray[i] == data) {
            return i;
        }
    }
    return -1;
}

Node* Tree::generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd) {
        return nullptr;
    }

    Node* node = new Node(preorder[preIndex++]);

    if (inStart == inEnd) {
        return node;
    }

    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex - 1, preIndex);
    node->rchild = generateFromTraversal(inorder, preorder, splitIndex + 1, inEnd, preIndex);

    return node;
}

int main() {
    Tree bt;

    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    int array_size = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;

    bt.root = bt.generateFromTraversal(inorder, preorder, 0, array_size - 1, preIndex);

    cout << "Preorder: " << flush;
    bt.Preorder();
    cout << endl;

    cout << "Inorder: " << flush;
    bt.Inorder();
    cout << endl;

    cout << "Postorder: " << flush;
    bt.Postorder();
    cout << endl;

    cout << "Levelorder: " << flush;
    bt.Levelorder();
    cout << endl;

    cout << "Height: " << bt.Height() << endl;

    cout << "Iterative Preorder: " << flush;
    bt.iterativePreorder();

    cout << "Iterative Inorder: " << flush;
    bt.iterativeInorder();

    cout << "Iterative Postorder: " << flush;
    bt.iterativePostorder();

    return 0;
}
*/

//================================> Height, count and sum of a tree
/*
#include <iostream>
#include <queue>
#include <stack> // For std::stack
#include <utility> // For std::pair

using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;

    Node() : lchild(nullptr), data(0), rchild(nullptr) {}
    Node(int data) : lchild(nullptr), data(data), rchild(nullptr) {}
};

class Tree {
private:
    void destroyTree(Node* node);

public:
    Node* root;
    Tree();
    ~Tree();
    void CreateTree();
    void Preorder(Node* p);
    void Preorder() { Preorder(root); }
    void Inorder(Node* p);
    void Inorder() { Inorder(root); }
    void Postorder(Node* p);
    void Postorder() { Postorder(root); }
    void Levelorder(Node* p);
    void Levelorder() { Levelorder(root); }
    void iterativePreorder(Node* p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node* p);
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node* p);
    void iterativePostorder() { iterativePostorder(root); }
    Node* generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd, int& preIndex);
    int Height(Node* p);
    int Height() { return Height(root); }
    int Count(Node* p);
    int Count() { return Count(root); }
    int Sum(Node* p);
    int Sum() { return Sum(root); }
    int deg2NodeCount(Node* p);
    int deg2NodeCount() { return deg2NodeCount(root); }
};

void Tree::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->lchild);
        destroyTree(node->rchild);
        delete node;
    }
}

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    destroyTree(root);
}

void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    root = new Node();
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        cout << "Enter left child of " << p->data << " (-1 for no child): ";
        cin >> x;
        if (x != -1) {
            t = new Node(x);
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter right child of " << p->data << " (-1 for no child): ";
        cin >> x;
        if (x != -1) {
            t = new Node(x);
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}

void Tree::Preorder(Node *p) {
    if (p) {
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p) {
    if (p) {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void Tree::Levelorder(Node *p) {
    queue<Node*> q;
    if (!p) return;
    cout << p->data << ", " << flush;
    q.emplace(p);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        if (p->lchild) {
            cout << p->lchild->data << ", " << flush;
            q.emplace(p->lchild);
        }

        if (p->rchild) {
            cout << p->rchild->data << ", " << flush;
            q.emplace(p->rchild);
        }
    }
}

void Tree::iterativePreorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            cout << p->data << ", " << flush;
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativeInorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativePostorder(Node *p) {
    stack<pair<Node*, bool>> stk; // Store node pointer and a flag (true if right child processed)
    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            stk.push({p, false}); // Push node, mark right as not processed
            p = p->lchild;
        } else {
            pair<Node*, bool>& top_pair = stk.top();
            if (top_pair.second == false) { // If right child not yet processed
                top_pair.second = true; // Mark right child as processed for this node
                p = top_pair.first->rchild; // Move to right child
            } else { // If right child has been processed or is null
                p = top_pair.first;
                stk.pop();
                cout << p->data << ", " << flush; // Process the node
                p = nullptr; // Set p to nullptr to force pop from stack on next iteration
            }
        }
    }
    cout << endl;
}


int searchInorder(int inArray[], int inStart, int inEnd, int data) {
    for (int i = inStart; i <= inEnd; i++) {
        if (inArray[i] == data) {
            return i;
        }
    }
    return -1;
}

Node* Tree::generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd) {
        return nullptr;
    }

    Node* node = new Node(preorder[preIndex++]);

    if (inStart == inEnd) {
        return node;
    }

    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex - 1, preIndex);
    node->rchild = generateFromTraversal(inorder, preorder, splitIndex + 1, inEnd, preIndex);

    return node;
}

int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;

    if (p != nullptr) {
        l = Height(p->lchild);
        r = Height(p->rchild);
        if (l > r) {
            return l + 1;
        } else {
            return r + 1;
        }
    }
    return 0;
}

int Tree::Count(Node *p) {
    int x;
    int y;
    if (p != nullptr) {
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int Tree::Sum(Node *p) {
    int x;
    int y;
    if (p != nullptr) {
        x = Sum(p->lchild);
        y = Sum(p->rchild);
        return x + y + p->data;
    }
    return 0;
}

int Tree::deg2NodeCount(Node *p) {
    int x;
    int y;
    if (p != nullptr) {
        x = deg2NodeCount(p->lchild);
        y = deg2NodeCount(p->rchild);
        if (p->lchild && p->rchild) {
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int main() {
    Tree bt;

    int preorder[] = {8, 3, 12, 4, 9, 7, 5, 10, 6, 2};
    int inorder[] = {12, 9, 4, 7, 3, 8, 10, 5, 2, 6};

    int size = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;

    bt.root = bt.generateFromTraversal(inorder, preorder, 0, size - 1, preIndex);

    cout << "Preorder: " << flush;
    bt.Preorder();
    cout << endl;

    cout << "Inorder: " << flush;
    bt.Inorder();
    cout << endl;

    cout << "Postorder: " << flush;
    bt.Postorder();
    cout << endl;

    cout << "Levelorder: " << flush;
    bt.Levelorder();
    cout << endl;

    cout << "Height: " << bt.Height() << endl;
    cout << "Count: " << bt.Count() << endl;
    cout << "Sum: " << bt.Sum() << endl;
    cout << "# of degree 2 nodes: " << bt.deg2NodeCount() << endl;
    
    // Demonstrate iterative traversals after creating the tree with generateFromTraversal
    cout << "Iterative Preorder: " << flush;
    bt.iterativePreorder();

    cout << "Iterative Inorder: " << flush;
    bt.iterativeInorder();

    cout << "Iterative Postorder: " << flush;
    bt.iterativePostorder();

    return 0;
}
*/

//=============================> Counting leaf nodes

#include <iostream>
#include <queue>
#include <stack>
#include <utility> // For std::pair

using namespace std;

class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;

    Node() : lchild(nullptr), data(0), rchild(nullptr) {}
    Node(int data) : lchild(nullptr), data(data), rchild(nullptr) {}
};

class Tree{
private:
    void destroyTreeRecursive(Node* node); // Helper for destructor

public:
    Node* root;
    Tree();
    ~Tree();
    void CreateTree();
    void Preorder(Node* p);
    void Preorder() { Preorder(root); }
    void Inorder(Node* p);
    void Inorder() { Inorder(root); }
    void Postorder(Node* p);
    void Postorder() { Postorder(root); }
    void Levelorder(Node* p);
    void Levelorder() { Levelorder(root); }
    void iterativePreorder(Node* p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node* p);
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node* p);
    void iterativePostorder() { iterativePostorder(root); }
    Node* generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd, int& preIndex);
    int Height(Node* p);
    int Height() { return Height(root); }
    int Count(Node* p);
    int Count() { return Count(root); }
    int Sum(Node* p);
    int Sum() { return Sum(root); }
    int deg2NodeCount(Node* p);
    int deg2NodeCount() { return deg2NodeCount(root); }
    int leafNodeCount(Node* p);
    int leafNodeCount() { return leafNodeCount(root); }
    int deg1ordeg2NodeCount(Node* p);
    int deg1ordeg2NodeCount() { return deg1ordeg2NodeCount(root); }
    int deg1NodeCount(Node* p);
    int deg1NodeCount() { return deg1NodeCount(root); }
};

void Tree::destroyTreeRecursive(Node* node) {
    if (node) {
        destroyTreeRecursive(node->lchild);
        destroyTreeRecursive(node->rchild);
        delete node;
    }
}

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    destroyTreeRecursive(root);
}

void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    root = new Node();
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);

    while (! q.empty()){
        p = q.front();
        q.pop();

        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node(x);
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node(x);
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}

void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void Tree::Levelorder(Node *p) {
    queue<Node*> q;
    if (!p) return;
    cout << p->data << ", " << flush;
    q.emplace(p);

    while (! q.empty()){
        p = q.front();
        q.pop();

        if (p->lchild){
            cout << p->lchild->data << ", " << flush;
            q.emplace(p->lchild);
        }

        if (p->rchild){
            cout << p->rchild->data << ", " << flush;
            q.emplace(p->rchild);
        }
    }
}

void Tree::iterativePreorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            cout << p->data << ", " << flush;
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativeInorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativePostorder(Node *p) {
    stack<pair<Node*, bool>> stk;
    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            stk.push({p, false});
            p = p->lchild;
        } else {
            pair<Node*, bool>& top_pair = stk.top();
            if (top_pair.second == false) {
                top_pair.second = true;
                p = top_pair.first->rchild;
            } else {
                p = top_pair.first;
                stk.pop();
                cout << p->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}

int searchInorder(int inArray[], int inStart, int inEnd, int data){
    for (int i=inStart; i<=inEnd; i++){
        if (inArray[i] == data){
            return i;
        }
    }
    return -1;
}

Node* Tree::generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd){
        return nullptr;
    }

    Node* node = new Node(preorder[preIndex++]);

    if (inStart == inEnd){
        return node;
    }

    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex-1, preIndex);
    node->rchild = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd, preIndex);

    return node;
}

int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;

    if (p != nullptr){
        l = Height(p->lchild);
        r = Height(p->rchild);
        if (l > r){
            return l + 1;
        } else {
            return r + 1;
        }
    }
    return 0;
}

int Tree::Count(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int Tree::Sum(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = Sum(p->lchild);
        y = Sum(p->rchild);
        return x + y + p->data;
    }
    return 0;
}

int Tree::deg2NodeCount(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = deg2NodeCount(p->lchild);
        y = deg2NodeCount(p->rchild);
        if (p->lchild && p->rchild){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int Tree::leafNodeCount(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = leafNodeCount(p->lchild);
        y = leafNodeCount(p->rchild);
        if (p->lchild == nullptr && p->rchild == nullptr){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int Tree::deg1ordeg2NodeCount(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = deg1ordeg2NodeCount(p->lchild);
        y = deg1ordeg2NodeCount(p->rchild);
        if (p->lchild != nullptr || p->rchild != nullptr){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int Tree::deg1NodeCount(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = deg1NodeCount(p->lchild);
        y = deg1NodeCount(p->rchild);
        if ((p->lchild != nullptr && p->rchild == nullptr) || (p->lchild == nullptr && p->rchild != nullptr)){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}


int main() {
    Tree bt;

    int preorder[] = {8, 3, 12, 4, 9, 7, 5, 10, 6, 2};
    int inorder[] = {12, 9, 4, 7, 3, 8, 10, 5, 2, 6};

    int size = sizeof(inorder)/sizeof(inorder[0]);
    int preIndex = 0;

    bt.root = bt.generateFromTraversal(inorder, preorder, 0, size-1, preIndex);

    cout << "Preorder: " << flush;
    bt.Preorder();
    cout << endl;

    cout << "Inorder: " << flush;
    bt.Inorder();
    cout << endl;

    cout << "Height: " << bt.Height() << endl;
    cout << "Count: " << bt.Count() << endl;
    cout << "Sum: " << bt.Sum() << endl;
    cout << "# of degree 2 nodes: " << bt.deg2NodeCount() << endl;
    cout << "# of leaf nodes: " << bt.leafNodeCount() << endl;
    cout << "# of degree 1 or degree 2 nodes: " << bt.deg1ordeg2NodeCount() << endl;
    cout << "# of degree 1 nodes: " << bt.deg1NodeCount() << endl;
    
    cout << "Iterative Preorder: " << flush;
    bt.iterativePreorder();

    cout << "Iterative Inorder: " << flush;
    bt.iterativeInorder();

    cout << "Iterative Postorder: " << flush;
    bt.iterativePostorder();

    return 0;
}