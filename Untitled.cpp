/*
L5.1: Height of a Binary Search Tree (BST)

Algorithm: Find Height of a Binary Search Tree

Input: Binary Search Tree
Output: Height of the tree

1. Starting from the root, recursively calculate the height of the left and right subtrees.
2. The height of the tree is the maximum of the left and right subtree heights plus one.

Time Complexity:
- O(n), where n is the number of nodes in the tree.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    
    cout << "Height of the BST: " << height(root) << endl;
    return 0;
}

/*
L5.2: Binary Search Tree Traversals

Algorithm: Create a BST and perform inorder, preorder, and postorder traversal.

1. Insert elements into the BST.
2. Perform inorder, preorder, and postorder traversals recursively.

Time Complexity:
- Insertion: O(log n) for balanced tree, O(n) in the worst case (unbalanced tree).
- Traversals: O(n) for each traversal, as all nodes are visited.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 2);
    root = insert(root, 7);
    
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
    
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
    
    return 0;
}

/*
L5.3: AVL Tree Implementation

Algorithm: Create AVL Tree and Insert an Element

1. Insert elements into the AVL tree and balance the tree after each insertion.
2. Calculate the balance factor (difference between heights of left and right subtrees).
3. If the tree becomes unbalanced, perform rotations (left, right, or double rotations) to restore balance.

Time Complexity:
- Insertion: O(log n) due to balancing after each insertion.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

int height(Node* root) {
    return root ? root->height : 0;
}

int balanceFactor(Node* root) {
    return height(root->left) - height(root->right);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    } else {
        return root; // No duplicates allowed
    }
    
    root->height = max(height(root->left), height(root->right)) + 1;
    
    int balance = balanceFactor(root);
    
    // Left Left Case
    if (balance > 1 && val < root->left->data) {
        return rightRotate(root);
    }
    
    // Right Right Case
    if (balance < -1 && val > root->right->data) {
        return leftRotate(root);
    }
    
    // Left Right Case
    if (balance > 1 && val > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    // Right Left Case
    if (balance < -1 && val < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 6); // Insert 6
    
    cout << "AVL Tree created and 6 inserted." << endl;
    return 0;
}

/*
L5.4: 2-3 Tree Implementation

Algorithm: Create a 2-3 Tree and Insert an Element

1. Insert elements into the 2-3 tree.
2. If a node has 3 children, split it, and insert the middle element into the parent node.

Time Complexity:
- Insertion: O(log n) due to tree balancing after each insertion.
*/

#include <iostream>
using namespace std;

struct Node {
    int* keys;
    Node** children;
    int numKeys;
    
    Node() {
        keys = new int[2]; // Two keys per node in a 2-3 tree
        children = new Node*[3]; // Three children per node
        numKeys = 0;
        for (int i = 0; i < 3; i++) {
            children[i] = nullptr;
        }
    }
};

void insert(Node*& root, int val) {
    if (!root) {
        root = new Node();
        root->keys[0] = val;
        root->numKeys = 1;
        return;
    }
    
    if (root->numKeys == 2) {
        // Split the node if it has 2 keys
        Node* newRoot = new Node();
        newRoot->children[0] = root;
        newRoot->numKeys = 1;
        newRoot->keys[0] = root->keys[1];
        
        Node* newChild = new Node();
        newRoot->children[1] = newChild;
        
        // Create a new node and insert the value
        if (val < root->keys[0]) {
            root->keys[0] = val;
        } else if (val < root->keys[1]) {
            newChild->keys[0] = val;
        } else {
            newChild->keys[1] = val;
            newChild->numKeys = 2;
        }
        
        root = newRoot;
    } else {
        // Insert in a non-full node
        if (val < root->keys[0]) {
            root->keys[0] = val;
        } else if (val < root->keys[1]) {
            root->keys[1] = val;
        }
        root->numKeys++;
    }
}

int main() {
    Node* root = nullptr;
    insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 6); // Insert 6
    
    cout << "2-3 Tree created and 6 inserted." << endl;
    return 0;
}




/*
L6.1: Diameter of Binary Tree

Algorithm: Diameter of a Binary Tree

Input: Binary tree root
Output: Diameter (longest path between any two nodes)

1. Recursively compute height of left and right subtrees
2. Compute diameter at each node as left height + right height + 1
3. Update maximum diameter found

Time Complexity:
- Each node is visited once: O(n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int diameterUtil(Node* root, int& diameter) {
    if (!root) return 0;
    int left = diameterUtil(root->left, diameter);
    int right = diameterUtil(root->right, diameter);
    diameter = max(diameter, left + right + 1);
    return max(left, right) + 1;
}

int diameter(Node* root) {
    int d = 0;
    diameterUtil(root, d);
    return d;
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Diameter: " << diameter(root) << endl;
    return 0;
}

/*
L6.2: Total Number of Nodes in Binary Tree + Efficiency

Algorithm: Count Total Nodes in Binary Tree

Input: Binary tree root
Output: Number of nodes

1. Use recursion
2. If root is null, return 0
3. Otherwise return 1 + count(left) + count(right)

Time Complexity:
- Visits all nodes once: O(n)
*/

#include <iostream>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    clock_t start = clock();
    int count = countNodes(root);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
    cout << "Total nodes: " << count << endl;
    cout << "Time taken: " << duration << " milliseconds" << endl;
    return 0;
}

/*
L6.3: Find and Delete Element in Max Heap

Algorithm: Find and Delete Element in Max Heap

Input: Array representing heap, element to delete
Output: Heap after deletion

1. Find index of element
2. Replace it with last element, reduce size
3. Heapify from the found index

Time Complexity:
- Finding index: O(n)
- Heapify: O(log n)
*/

#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a; a = b; b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int deleteElement(int arr[], int& n, int val) {
    int i;
    for (i = 0; i < n; i++) if (arr[i] == val) break;
    if (i == n) return 0;
    swap(arr[i], arr[n - 1]);
    n--;
    heapify(arr, n, i);
    return 1;
}

int main() {
    int arr[100] = {50, 30, 20, 15, 10, 8, 16};
    int n = 7;
    int val;
    cout << "Enter element to delete: ";
    cin >> val;
    if (deleteElement(arr, n, val)) {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
    } else {
        cout << "Element not found";
    }
    cout << endl;
}

/*
L6.4: Heap Sort using Bottom-Up Max Heap Construction

Algorithm: Heap Sort using Bottom-Up Max Heap Construction

Input: Array A of size n
Output: Sorted array in ascending order

1. BuildMaxHeap(A, n)
   for i = n/2 - 1 downto 0:
       MaxHeapify(A, n, i)

2. MaxHeapify(A, n, i)
   largest = i
   left = 2*i + 1
   right = 2*i + 2
   if left < n and A[left] > A[largest], set largest = left
   if right < n and A[right] > A[largest], set largest = right
   if largest != i:
       swap A[i] and A[largest]
       MaxHeapify(A, n, largest)

3. HeapSort(A, n)
   BuildMaxHeap(A, n)
   for i = n-1 downto 1:
       swap A[0] and A[i]
       MaxHeapify(A, i, 0)

Time Complexity:
- Building Max Heap: O(n)
- Each deletion from heap takes O(log n), repeated n times: O(n log n)
- Overall worst-case time complexity: O(n log n)
*/

#include <iostream>
#include <ctime>
using namespace std;

void swap(int &a, int &b) {
    int temp = a; a = b; b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[10000];
    for (int i = 0; i < n; i++) arr[i] = n - i;
    clock_t start = clock();
    heapSort(arr, n);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
    cout << "Time taken: " << duration << " milliseconds" << endl;
    return 0;
}




/*w7
Algorithm: Heap Sort using Bottom-Up Max Heap Construction

Input: Array A of size n
Output: Sorted array in ascending order

1. BuildMaxHeap(A, n)
   for i = n/2 - 1 downto 0:
       MaxHeapify(A, n, i)

2. MaxHeapify(A, n, i)
   largest = i
   left = 2*i + 1
   right = 2*i + 2
   if left < n and A[left] > A[largest], set largest = left
   if right < n and A[right] > A[largest], set largest = right
   if largest != i:
       swap A[i] and A[largest]
       MaxHeapify(A, n, largest)

3. HeapSort(A, n)
   BuildMaxHeap(A, n)
   for i = n-1 downto 1:
       swap A[0] and A[i]
       MaxHeapify(A, i, 0)

Time Complexity:
- Building Max Heap: O(n)
- Each deletion from heap takes O(log n), repeated n times: O(n log n)
- Overall worst-case time complexity: O(n log n)
*/

#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[10000];
    for (int i = 0; i < n; i++) {
        arr[i] = (n - i); // Worst-case: reverse sorted input
    }

    clock_t start = clock();
    heapSort(arr, n);
    clock_t end = clock();

    double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
    cout << "Time taken: " << duration << " milliseconds" << endl;

    return 0;
}


/*
Algorithm: Comparison Counting Sort

Input: Array A of size n
Output: Sorted array in ascending order

1. Initialize a count array C of size n to 0
2. For each element A[i] in the array:
      For each element A[j] in the array:
          If A[j] < A[i], increment C[i]
          If A[j] == A[i] and j < i, increment C[i] (to handle duplicates)
3. Create an output array B of size n
4. For i from 0 to n-1:
      Set B[C[i]] = A[i]
5. Copy elements from B back to A

Time Complexity:
- Two nested loops over n elements: O(n^2)
- Additional linear time copying: O(n)
- Overall time complexity: O(n^2)
*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[1000], C[1000] = {0}, B[1000];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[j] < A[i] || (A[j] == A[i] && j < i))
                C[i]++;

    for (int i = 0; i < n; i++)
        B[C[i]] = A[i];

    for (int i = 0; i < n; i++)
        cout << B[i] << " ";

    cout << endl;
    return 0;
}

/*
Algorithm: Horspool’s String Matching

Input: Text T of length n, Pattern P of length m
Output: Index of pattern match or -1, and number of comparisons

1. Construct a shift table:
   For all characters c: shift[c] = m
   For i = 0 to m-2: shift[P[i]] = m - 1 - i

2. Initialize i = m - 1
3. While i < n:
   a. Set k = 0
   b. While k < m and P[m - 1 - k] == T[i - k], increment k
   c. If k == m, match found at i - m + 1
   d. Else, shift i by shift[T[i]]

Time Complexity:
- Preprocessing: O(m)
- Best case: O(n / m)
- Worst case: O(mn)
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    int n = text.length();
    int m = pattern.length();

    int shift[256];
    for (int i = 0; i < 256; i++)
        shift[i] = m;
    for (int i = 0; i < m - 1; i++)
        shift[(int)pattern[i]] = m - 1 - i;

    int i = m - 1, comparisons = 0, found = 0;

    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
            comparisons++;
        }
        if (k == m) {
            cout << "Pattern found at position " << i - m + 1 << endl;
            found = 1;
            break;
        } else {
            comparisons++;
            i += shift[(int)text[i]];
        }
    }

    if (!found)
        cout << "Pattern not found" << endl;

    cout << "Total comparisons: " << comparisons << endl;
    return 0;
}
/*Enter text: abracadabra
Enter pattern: dab
Pattern found at position 6
Total comparisons: 6
*/

/*
Algorithm: Open Hashing using Separate Chaining

Input: Set of keys, hash table size
Output: Constructed hash table, number of comparisons for search

1. Initialize a hash table of size m, each slot is a linked list
2. Insert keys using: index = key % m
   Append the key to the list at that index
3. To search for a key:
   - Compute index = key % m
   - Traverse the list at that index, counting comparisons until key is found or list ends

Time Complexity:
- Insert: O(1) average, O(n) worst
- Search: O(1) average, O(n) worst
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

const int TABLE_SIZE = 10;
Node* hashTable[TABLE_SIZE] = {nullptr};

void insert(int key) {
    int index = key % TABLE_SIZE;
    Node* newNode = new Node{key, nullptr};
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(int key, int &comparisons) {
    int index = key % TABLE_SIZE;
    Node* temp = hashTable[index];
    comparisons = 0;
    while (temp) {
        comparisons++;
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n, key, comparisons;
    cout << "Enter number of keys to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        insert(k);
    }

    cout << "Enter key to search: ";
    cin >> key;
    if (search(key, comparisons))
        cout << "Key found with " << comparisons << " comparisons" << endl;
    else
        cout << "Key not found with " << comparisons << " comparisons" << endl;

    return 0;
}

/*
w8
Algorithm: Heap Sort using Top-Down Heap Construction

Input: Array A of size n
Output: Sorted array in ascending order

1. For i = 1 to n-1:
     Insert A[i] into the heap by moving it up to restore max-heap property
     (sift-up operation)

2. After building heap, sort:
     For i = n-1 downto 1:
         Swap A[0] and A[i]
         Heapify A[0...i-1] using sift-down to maintain max-heap

Time Complexity:
- Building heap (top-down insertions): O(n log n)
- Sorting (heapify each element): O(n log n)
- Overall worst-case time complexity: O(n log n)
*/

#include <iostream>
#include <ctime>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void siftUp(int arr[], int i) {
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void siftDown(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        siftDown(arr, n, largest);
    }
}

void topDownHeapSort(int arr[], int n) {
    for (int i = 1; i < n; i++)
        siftUp(arr, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        siftDown(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[10000];
    for (int i = 0; i < n; i++)
        arr[i] = n - i;

    clock_t start = clock();
    topDownHeapSort(arr, n);
    clock_t end = clock();

    double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
    cout << "Time taken: " << duration << " milliseconds" << endl;

    return 0;
}

/*
Algorithm: Closed Hash Table using Linear Probing

Input: Array of integers (keys)
Output: Hash table with keys inserted

1. Insert:
   For each key, compute h = key % table_size
   If occupied, linearly probe to next index until empty slot found

2. Search:
   Compute h = key % table_size
   Linearly probe until key is found or empty slot encountered

Time Complexity:
- Average case: O(1) for insert and search
- Worst case (with clustering): O(n)

Key Comparisons:
- Count number of probes (comparisons) during insertion and search
*/

#include <iostream>
using namespace std;

const int SIZE = 100;
const int EMPTY = -1;

int table[SIZE];

int insert(int key) {
    int h = key % SIZE;
    int comparisons = 1;
    while (table[h] != EMPTY) {
        h = (h + 1) % SIZE;
        comparisons++;
    }
    table[h] = key;
    return comparisons;
}

int search(int key, bool &found) {
    int h = key % SIZE;
    int comparisons = 1;
    while (table[h] != EMPTY && table[h] != key) {
        h = (h + 1) % SIZE;
        comparisons++;
    }
    if (table[h] == key) found = true;
    return comparisons;
}

int main() {
    for (int i = 0; i < SIZE; i++) table[i] = EMPTY;

    int n, x;
    cout << "Enter number of keys: ";
    cin >> n;

    int totalInsertComparisons = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        totalInsertComparisons += insert(x);
    }

    bool found;
    cout << "Enter key to search (successful case): ";
    cin >> x;
    int cmp1 = search(x, found);

    cout << "Enter key to search (unsuccessful case): ";
    cin >> x;
    int cmp2 = search(x, found);

    cout << "Total insert comparisons: " << totalInsertComparisons << endl;
    cout << "Search comparisons (successful): " << cmp1 << endl;
    cout << "Search comparisons (unsuccessful): " << cmp2 << endl;

    return 0;
}

/*
Algorithm: Boyer-Moore String Matching using Bad Character Heuristic

Input: Text T of length n and Pattern P of length m
Output: Index where pattern matches text or -1

1. Preprocess:
   Build bad character shift table from pattern

2. Search:
   Align pattern with text, compare right to left
   On mismatch, shift pattern using bad character table

Time Complexity:
- Best case: O(n / m)
- Worst case: O(n * m) (rare, but possible)
- Average case: sublinear due to skipping

Key Comparisons:
- Count total character comparisons for both successful and unsuccessful search
*/

#include <iostream>
#include <cstring>
using namespace std;

int badChar[256];

void buildBadCharTable(string pattern) {
    for (int i = 0; i < 256; i++) badChar[i] = -1;
    for (int i = 0; i < pattern.length(); i++)
        badChar[pattern[i]] = i;
}

int boyerMoore(string text, string pattern, int &comparisons) {
    int n = text.length();
    int m = pattern.length();
    buildBadCharTable(pattern);
    int s = 0;

    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) {
            comparisons++;
            j--;
        }
        if (j < 0)
            return s;
        else {
            comparisons++;
            s += max(1, j - badChar[text[s + j]]);
        }
    }
    return -1;
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    int comparisons = 0;
    int pos = boyerMoore(text, pattern, comparisons);

    if (pos != -1)
        cout << "Pattern found at position " << pos << endl;
    else
        cout << "Pattern not found" << endl;

    cout << "Total comparisons: " << comparisons << endl;

    return 0;
}

/*
Algorithm: Distribution Counting Sort

Input: Array A of n integers, all in range [0, k]
Output: Sorted array in ascending order

1. Count occurrences of each key in array C[0...k]
2. Compute prefix sum in C[] to get positions
3. Place elements into output array using C[]

Time Complexity:
- Counting: O(n)
- Prefix sum: O(k)
- Placement: O(n)
- Overall time complexity: O(n + k)
*/

#include <iostream>
using namespace std;

void distributionCountSort(int A[], int B[], int n, int k) {
    int C[100] = {0};

    for (int i = 0; i < n; i++)
        C[A[i]]++;

    for (int i = 1; i <= k; i++)
        C[i] += C[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[100], B[100];
    cout << "Enter elements (non-negative integers): ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    k = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > k) k = A[i];

    distributionCountSort(A, B, n, k);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << B[i] << " ";
    cout << endl;

    return 0;
}




//-----

/*
L9.1: Binomial Coefficient using Dynamic Programming

Algorithm: Binomial Coefficient (n choose k)

Input: n, k
Output: Binomial Coefficient C(n, k)

1. Initialize a 2D array dp of size (n+1) x (k+1)
2. Set dp[i][0] = 1 for all i (base case)
3. Set dp[i][i] = 1 for all i (base case)
4. For each i from 1 to n and each j from 1 to k, compute dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
5. Return dp[n][k]

Time Complexity:
- Filling the table: O(n*k)
*/

#include <iostream>
#include <vector>
using namespace std;

int binomialCoefficient(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    cout << "Binomial Coefficient C(" << n << ", " << k << ") = " << binomialCoefficient(n, k) << endl;
    return 0;
}

/*
L9.2: Transitive Closure using Warshall’s Algorithm

Algorithm: Transitive Closure using Warshall's Algorithm

Input: Adjacency matrix of a directed graph
Output: Transitive closure matrix

1. For each pair of vertices (i, j), if there is a path from i to j, set transitive[i][j] = 1
2. Iterate through all vertices k from 0 to n-1:
   - For each pair of vertices i, j, update transitive[i][j] = transitive[i][j] || (transitive[i][k] && transitive[k][j])

Time Complexity:
- Triple loop: O(n^3)
*/

#include <iostream>
#include <vector>
using namespace std;

void warshallAlgorithm(vector<vector<int>>& graph, int n) {
    vector<vector<int>> transitive = graph;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                transitive[i][j] = transitive[i][j] || (transitive[i][k] && transitive[k][j]);
            }
        }
    }
    // Print Transitive Closure Matrix
    cout << "Transitive Closure Matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << transitive[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    warshallAlgorithm(graph, n);
    return 0;
}

/*
L9.3: Floyd's Algorithm for All-Pairs-Shortest-Paths

Algorithm: Floyd-Warshall Algorithm for All-Pairs-Shortest-Paths

Input: Graph represented as adjacency matrix
Output: Shortest paths between all pairs of vertices

1. Initialize the distance matrix as the adjacency matrix of the graph.
2. For each vertex k, update the distance between vertices i and j as the minimum of the current distance and distance through k: 
   distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])

Time Complexity:
- Triple loop: O(n^3)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>>& graph, int n) {
    vector<vector<int>> dist = graph;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    // Print shortest distance matrix
    cout << "Shortest Distance Matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix (use INF for no path):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) graph[i][j] = INT_MAX; // Represent no path as INF
        }
    }
    floydWarshall(graph, n);
    return 0;
}

/*
L9.4: 0/1 Knapsack Problem using Bottom-Up Dynamic Programming

Algorithm: 0/1 Knapsack Problem

Input: Weights and values of items, Knapsack capacity
Output: Maximum value that can be obtained

1. Initialize a 2D dp array where dp[i][w] represents the maximum value that can be achieved with the first i items and knapsack capacity w.
2. Iterate through all items and weights:
   - For each item, check if it fits in the knapsack; if it does, calculate the maximum of including or excluding the item.
3. Return dp[n][W] as the maximum value.

Time Complexity:
- Filling the table: O(n*W), where W is the knapsack capacity
*/

#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> W;
    vector<int> wt(n), val(n);
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> wt[i];
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> val[i];
    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;
    return 0;
}



/*
L4.1: Insertion Sort

Algorithm: Insertion Sort

Input: Array A of size n
Output: Sorted array in ascending order

1. Iterate through the array from index 1 to n-1
2. For each element, insert it into the sorted portion of the array by shifting elements larger than it to the right
3. Repeat until the array is fully sorted

Time Complexity:
- Best case: O(n)
- Worst case: O(n^2)
*/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
L4.2: Quick Sort

Algorithm: Quick Sort

Input: Array A of size n
Output: Sorted array in ascending order

1. Select a pivot element from the array (usually the last element)
2. Partition the array such that elements less than pivot come before it, and elements greater than pivot come after it
3. Recursively apply Quick Sort to the subarrays before and after the pivot

Time Complexity:
- Best case: O(n log n)
- Worst case: O(n^2)
*/

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
L4.3: Merge Sort

Algorithm: Merge Sort

Input: Array A of size n
Output: Sorted array in ascending order

1. Divide the array into two halves
2. Recursively sort each half
3. Merge the sorted halves to get the final sorted array

Time Complexity:
- Best case: O(n log n)
- Worst case: O(n log n)
*/

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
L4.4: Topological Sort using Depth-First and Source Removal Technique

i) Depth-First Search (DFS) Based Topological Sort:

Algorithm: Topological Sort using DFS

Input: Directed acyclic graph (DAG) represented by adjacency list
Output: Topologically sorted order of vertices

1. Initialize visited[] and result[] arrays
2. For each unvisited vertex, call DFS to explore its adjacent vertices
3. Push the vertex onto the result stack after visiting all its adjacent vertices

Time Complexity:
- O(V + E), where V is the number of vertices and E is the number of edges

ii) Source Removal Technique:

Algorithm: Topological Sort using Source Removal

Input: Directed acyclic graph (DAG) represented by adjacency list
Output: Topologically sorted order of vertices

1. Identify all nodes with no incoming edges (in-degree 0)
2. Remove those nodes and their outgoing edges
3. Repeat until all nodes are removed

Time Complexity:
- O(V + E), where V is the number of vertices and E is the number of edges
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void DFS(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& result) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            DFS(u, adj, visited, result);
        }
    }
    result.push(v);
}

void topologicalSortDFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> result;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, adj, visited, result);
        }
    }

    cout << "Topological Sort (DFS): ";
    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
    cout << endl;
}

void topologicalSortSourceRemoval(int V, vector<vector<int>>& adj) {
    vector<int> in_degree(V, 0);
    for (int i = 0; i < V; i++) {
        for (int u : adj[i]) {
            in_degree[u]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    cout << "Topological Sort (Source Removal): ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int u : adj[v]) {
            in_degree[u]--;
            if (in_degree[u] == 0) {
                q.push(u);
            }
        }
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter the edges (u v) where u -> v: " << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    topologicalSortDFS(V, adj);
    topologicalSortSourceRemoval(V, adj);

    return 0;
}

/*
L3.1: Maximum Element in an Unsorted Array (Non-Recursive)

Algorithm:
1. Initialize max as the first element.
2. Traverse the array and update max whenever a larger element is found.

Time Complexity:
- O(n), where n is the number of elements in the array.
*/

#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

int main() {
    int arr[] = {3, 7, 1, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Element: " << findMax(arr, n) << endl;
    return 0;
}

/*
L3.2: Find Unique Element in Array (Non-Recursive)

Algorithm:
1. XOR all elements of the array.
2. Since a ^ a = 0 and a ^ 0 = a, the result will be the unique element.

Time Complexity:
- O(n)
*/

#include <iostream>
using namespace std;

int findUnique(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}

int main() {
    int arr[] = {2, 3, 5, 4, 5, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unique Element: " << findUnique(arr, n) << endl;
    return 0;
}

/*
L3.3: Matrix Multiplication (Non-Recursive)

Algorithm:
1. Use triple nested loops to multiply matrices A and B.
2. Store result in matrix C.

Time Complexity:
- O(n^3)
*/

#include <iostream>
using namespace std;

void multiply(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];

    multiply(A, B, C);

    cout << "Matrix Multiplication Result:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    return 0;
}

/*
L3.4: Count Binary Digits (Non-Recursive)

Algorithm:
1. Keep dividing the number by 2 until it becomes 0.
2. Count the number of divisions.

Time Complexity:
- O(log n)
*/

#include <iostream>
using namespace std;

int countBinaryDigits(int n) {
    int count = 0;
    while (n > 0) {
        n /= 2;
        count++;
    }
    return count;
}

int main() {
    int n = 19;
    cout << "Number of binary digits: " << countBinaryDigits(n) << endl;
    return 0;
}

/*
L3.5: Factorial (Recursive)

Algorithm:
1. If n == 0 return 1.
2. Else return n * factorial(n - 1).

Time Complexity:
- O(n)
*/

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n = 5;
    cout << "Factorial: " << factorial(n) << endl;
    return 0;
}

/*
L3.6: Tower of Hanoi (Recursive)

Algorithm:
1. Move n-1 disks from source to auxiliary.
2. Move nth disk from source to destination.
3. Move n-1 disks from auxiliary to destination.

Time Complexity:
- O(2^n)
*/

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char dest, char aux) {
    if (n == 0) return;
    towerOfHanoi(n - 1, src, aux, dest);
    cout << "Move disk " << n << " from " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, aux, dest, src);
}

int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

/*
L3.7: Count Binary Digits (Recursive)

Algorithm:
1. If n == 0, return 0.
2. Else return 1 + recursive call on n / 2.

Time Complexity:
- O(log n)
*/

#include <iostream>
using namespace std;

int countBinaryDigitsRecursive(int n) {
    if (n == 0)
        return 0;
    return 1 + countBinaryDigitsRecursive(n / 2);
}

int main() {
    int n = 19;
    cout << "Binary digits (recursive): " << countBinaryDigitsRecursive(n) << endl;
    return 0;
}


/*
L2.1: Knapsack Problem using Brute-Force

Algorithm: Generate all subsets and find the one with maximum value under the weight constraint.

Input:
- Weights and values of items
- Capacity of the knapsack

Output:
- Maximum value that can be carried in the knapsack

Time Complexity:
- O(2^n), where n is the number of items (since all subsets are explored).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int knapsackBruteForce(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    int maxVal = 0;

    for (int i = 0; i < (1 << n); i++) {
        int totalWeight = 0, totalValue = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                totalWeight += weights[j];
                totalValue += values[j];
            }
        }
        if (totalWeight <= capacity) {
            maxVal = max(maxVal, totalValue);
        }
    }
    return maxVal;
}

/*
L2.2: Assignment Problem using Brute-Force

Algorithm: Try all permutations of assignments and find the minimum cost.

Input: Cost matrix
Output: Minimum cost of assignment

Time Complexity:
- O(n!), where n is the number of tasks or workers.
*/

int assignmentBruteForce(vector<vector<int>>& cost) {
    int n = cost.size();
    vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;

    int minCost = INT_MAX;
    do {
        int totalCost = 0;
        for (int i = 0; i < n; i++) {
            totalCost += cost[i][perm[i]];
        }
        minCost = min(minCost, totalCost);
    } while (next_permutation(perm.begin(), perm.end()));
    return minCost;
}

/*
L2.3: Depth-First Search (DFS) of a Graph

Algorithm: Use recursion to explore nodes as deep as possible before backtracking.

Input: Adjacency list
Output: Push and Pop order of vertices

Time Complexity:
- O(V + E)
*/

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& push, vector<int>& pop) {
    visited[node] = true;
    push.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, push, pop);
        }
    }
    pop.push_back(node);
}

/*
L2.4: Breadth-First Search (BFS) of a Graph

Algorithm: Use a queue to visit nodes level by level.

Input: Adjacency list
Output: Order of traversal

Time Complexity:
- O(V + E)
*/

void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

/*
L2.5a(i): Check Bipartite Graph using DFS

Algorithm: Color graph using 2 colors recursively. If any adjacent vertices have same color, not bipartite.

Time Complexity:
- O(V + E)
*/

bool isBipartiteDFS(int node, int color, vector<vector<int>>& adj, vector<int>& colors) {
    colors[node] = color;
    for (int neighbor : adj[node]) {
        if (colors[neighbor] == -1) {
            if (!isBipartiteDFS(neighbor, 1 - color, adj, colors)) return false;
        } else if (colors[neighbor] == color) {
            return false;
        }
    }
    return true;
}

/*
L2.5a(ii): Check Bipartite Graph using BFS

Algorithm: Color graph using 2 colors using a queue. If adjacent nodes have same color, not bipartite.

Time Complexity:
- O(V + E)
*/

bool isBipartiteBFS(vector<vector<int>>& adj, int V) {
    vector<int> colors(V, -1);

    for (int i = 0; i < V; i++) {
        if (colors[i] == -1) {
            queue<int> q;
            q.push(i);
            colors[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (colors[neighbor] == -1) {
                        colors[neighbor] = 1 - colors[node];
                        q.push(neighbor);
                    } else if (colors[neighbor] == colors[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

/*
Main Function to Demonstrate All Programs
*/

int main() {
    // L2.1: Knapsack Brute Force
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 5;
    cout << "\nL2.1 - Knapsack Max Value: " << knapsackBruteForce(weights, values, capacity) << endl;

    // L2.2: Assignment Brute Force
    vector<vector<int>> cost = {
        {9, 2, 7},
        {6, 4, 3},
        {5, 8, 1}
    };
    cout << "L2.2 - Assignment Min Cost: " << assignmentBruteForce(cost) << endl;

    // Graph used for L2.3, L2.4, L2.5
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {4};

    // L2.3: DFS Push & Pop
    vector<bool> visitedDFS(V, false);
    vector<int> pushOrder, popOrder;
    dfs(0, adj, visitedDFS, pushOrder, popOrder);
    cout << "L2.3 - DFS Push Order: ";
    for (int v : pushOrder) cout << v << " ";
    cout << "\nL2.3 - DFS Pop Order: ";
    for (int v : popOrder) cout << v << " ";
    cout << endl;

    // L2.4: BFS
    vector<bool> visitedBFS(V, false);
    cout << "L2.4 - BFS Traversal: ";
    bfs(0, adj, visitedBFS);
    cout << endl;

    // L2.5a(i): Bipartite DFS
    vector<vector<int>> bipartiteAdj = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };
    vector<int> colorsDFS(4, -1);
    bool bipartiteDFS = true;
    for (int i = 0; i < 4; i++) {
        if (colorsDFS[i] == -1) {
            if (!isBipartiteDFS(i, 0, bipartiteAdj, colorsDFS)) {
                bipartiteDFS = false;
                break;
            }
        }
    }
    cout << "L2.5a(i) - Bipartite (DFS): " << (bipartiteDFS ? "Yes" : "No") << endl;

    // L2.5a(ii): Bipartite BFS
    cout << "L2.5a(ii) - Bipartite (BFS): " << (isBipartiteBFS(bipartiteAdj, 4) ? "Yes" : "No") << endl;

    return 0;
}

