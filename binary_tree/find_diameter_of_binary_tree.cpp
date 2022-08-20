#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
} *root = NULL;
Node *create_node(int val)
{

    Node *newNode = new Node();
    newNode->left = newNode->right = NULL;
    newNode->data = val;
    return newNode;
}

Node *insert(Node *root, int val)
{

    if (root == NULL)
    {

        return create_node(val);
    }
    if (val < root->data)
    {

        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node *root)
{

    if (root)
    {

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void preorder(Node *root)
{

    if (root)
    {

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int height(Node *root)
{

    if (root == NULL)
        return 0;

    int x, y;
    x = height(root->left);
    y = height(root->right);
    return max(x, y) + 1;
}

int diameter(Node *root)
{

    if (root == NULL)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight + rheight + 1, max(diameter(root->left), diameter(root->right)));
}

void make_tree()
{

    cout << "Enter the value of root>";
    int n;
    cin >> n;
    root = create_node(n);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {

        root = q.front();
        q.pop();
        cout << "Enter the left child of " << root->data << ">";
        cin >> n;
        if (n != -1)
        {
            root->left = create_node(n);
            q.push(root->left);
        }
        cout << "Enter the right child of " << root->data << ">";
        cin >> n;
        if (n != -1)
        {
            root->right = create_node(n);
            q.push(root->right);
        }
    }
}
int main()
{

    // int A[] = {9, 3, 7, 8, 10, 12, 91, 11};
    // root = insert(root, 5);
    // for (auto x : A)
    // {
    //     insert(root, x);
    // }
    // cout << "inorder>";
    // inorder(root);
    // cout << "\npreorder>";
    // preorder(root);
    // cout << endl;
    // cout << height(root) << endl;
    // cout << diameter(root) << endl;
    make_tree();
    inorder(root);

    return 0;
}