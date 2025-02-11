#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root, int &diameter) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);

    if (leftHeight + rightHeight > diameter) {
        diameter = leftHeight + rightHeight;
    }

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of the binary tree is: " << diameterOfBinaryTree(root) << endl;

    return 0;
}

