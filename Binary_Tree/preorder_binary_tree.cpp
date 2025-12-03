#include <iostream>
#include <queue>
using namespace std;

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

static int idx = -1;
Node* buildTree(int arr[]) {
    idx++;
    if(arr[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(arr[idx]);
    root->left = buildTree(arr);
    root->right = buildTree(arr);

    return root;
}

// Preorder Traversal
void preorder(Node* root) { // O(n)
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal
void inorder(Node* root) { // O(n)
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal
void postorder(Node* root) { // O(n)
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Level Order Traversal
void leverorder(Node* root) {
    queue<Node*> q;
    
    q.push(root);

    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

void leverorder2(Node* root) {
    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);

    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();
        if(curr == NULL) {
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }
        cout << curr->data << " ";

        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

int main() {

    int arr[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(arr);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    leverorder(root);
    leverorder2(root);

    return 0;
}