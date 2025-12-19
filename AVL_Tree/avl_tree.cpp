#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node* n) {
    if(n == NULL) {
        return 0;
    }
    return n->height;
}

int getBalance(Node* n) {
    if(n == NULL) {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int value) {
    if(root == NULL) {
        return new Node(value);
    }
    if(value < root->data) {
        root->left = insert(root->left, value);
    } else if(value > root->data) {
        root->right = insert(root->right, value);
    } else {
        return root;
    }

    root->height = max(getHeight(root->left), getHeight(root->right))+1;
    int balance = getBalance(root);

    // 4 Cases
    // LL
    if(balance > 1 && value < root->left->data) {
        return rightRotate(root);
    }

    // RR
    if(balance < -1 && value > root->right->data) {
        return leftRotate(root);
    }

    // LR
    if(balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if(balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool search(Node* root, int key) {
    if(root == NULL) {
        return false;
    }
    if(root->data == key) {
        return true;
    }

    if(root->data > key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

Node* findMin(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root, int key) {
    if(root == NULL) {
        return NULL;
    }
    if(key < root->data) {
        root->left = delNode(root->left, key);
    } else if(key > root->data) {
        root->right = delNode(root->right, key);
    } else {
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delNode(root->right, temp->data);
        }
    }

    if(root == NULL) {
        return NULL;
    }

    root->height = max(getHeight(root->left), getHeight(root->right))+1;

    int balance = getBalance(root);

    // LL
    if(balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // LR
    if(balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if(balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    // RL
    if(balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {

    Node* root = NULL;

    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);

    cout << "Inorder Traversal after insertion: ";
    inorder(root);
    cout << endl;

    cout << "Search 3: ";
    cout << search(root, 3) << endl;

    root = delNode(root, 5);

    cout << "Inorder Traversal after delete 5: ";
    inorder(root);
    cout << endl;


    return 0;
}