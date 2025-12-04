#include <iostream>
using namespace std;

// create Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// insert function
Node* insert(Node* root, int value) { // W-TC = O(n), B-TC = O(logn)
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
    return root;
}

// preorder traversal
void preorder(Node* root) { // O(n)
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// inorder traversal
void inorder(Node* root) { // O(n)
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// postorder traversal
void postorder(Node* root) { // O(n)
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// search function
bool search(Node* root, int key) { // O(height)
    if(root == NULL) {
        return false;
    }
    if(root->data == key) {
        return true;
    }

    if(key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

Node* findMin(Node* root) {
    while(root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// delete node function
Node* delNode(Node* root, int key) { // O(n)
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
        } else { // 2 Children
            Node* temp = findMin(root->right);
            root->data = temp->data; 
            root->right = delNode(root->right, temp->data); 
        } 
    }
    return root;
}

int main() {

    Node* root = NULL;
    root = insert(root, 4);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 7);

    cout << "Preorder Traversal: "; preorder(root);
    cout << "\nInorder Traversal: "; inorder(root);
    cout << "\nPostorder Traversal: "; postorder(root);

    delNode(root, 1);

    cout << "\n\nAfter deleting 1: \n";
    cout << "Preorder Traversal: "; preorder(root);
    cout << "\nInorder Traversal: "; inorder(root);
    cout << "\nPostorder Traversal: "; postorder(root);

    return 0;
}