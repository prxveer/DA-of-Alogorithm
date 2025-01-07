//          QUESTION 6(LAB 0)

#include <iostream>
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

class BST {
private:
    Node* root;  // Keep root private

public:
    BST() {
        root = NULL;
    }

    // Public method to access root safely
    Node* getRoot() {
        return root;
    }

    // Public method to insert a value
    void insert(int value) {
        root = insertRec(root, value);
    }

    Node* insertRec(Node* root, int value) {
        if (root == NULL) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = insertRec(root->left, value);
        } else {
            root->right = insertRec(root->right, value);
        }
        return root;
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    void inorderRec(Node* root) {
        if (root != NULL) {
            inorderRec(root->left);
            cout << root->data << " ";
            inorderRec(root->right);
        }
    }

    // Modify search method to return Node* instead of bool
    Node* search(int value) {
        return searchRec(root, value);
    }

    Node* searchRec(Node* root, int value) {
        if (root == NULL) return NULL; // Return NULL if node is not found
        if (root->data == value) return root; // Return node if found
        if (value < root->data) return searchRec(root->left, value); // Search left
        return searchRec(root->right, value); // Search right
    }

    Node* deleteNode(Node* root, int value) {
        if (root == NULL) return root;
        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.inorder();  // Print inorder traversal before deletion

    // Search for node and delete it
    Node* node = tree.search(30);
    if (node != NULL) {
        // Use the public method getRoot() to get the root of the tree and update it after deletion
        tree.deleteNode(tree.getRoot(), 30); // Delete node with value 30
    }

    tree.inorder();  // Print inorder traversal after deletion

    return 0;
}

