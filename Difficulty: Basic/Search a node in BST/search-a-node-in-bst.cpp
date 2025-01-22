//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

bool search(Node *root, int x);

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << search(root, s);
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends


// Function to search a node in BST.
int fl=0;
void f(Node* p ,int x)
{
    if(p==NULL)
    return ;
    if(p->data==x)
    {
        fl=1;
        return ;
    }
    if(p->data<x)
    f(p->right,x);
    else if(p->data>x)
    f(p->left,x);
}
bool search(Node* root, int x) {
    // Your code here
    fl=0;
    f(root,x);
    if(fl==1)
    return true;
    return false;
    
}
