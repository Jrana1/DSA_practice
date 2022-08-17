#include <bits/stdc++.h>
using namespace std;
struct Node
{

    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;

Node *create_node(int val)
{

    Node *newNode = new Node;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void create_tree()
{

    cout << "Enter the value of Root>";
    int x;
    cin >> x;
    Node *newNode = create_node(x);
    queue<Node *> nodes;
    root = newNode;
    nodes.push(root);
    while (!nodes.empty())
    {
        Node *ptr = nodes.front();
        nodes.pop();
        cout << "Enter the left child of " << ptr->data << ">";
        cin >> x;
        if (x != -1)
        {
            Node *newNode = create_node(x);
            ptr->left = newNode;
            nodes.push(newNode);
        }
        cout << "Enter the right child of " << ptr->data << ">";
        cin >> x;
        if (x != -1)
        {
            Node *newNode = create_node(x);
            ptr->right = newNode;
            nodes.push(newNode);
        }
    }
}
// pre-order traversal
void pre_order(Node *ptr)
{
    if (ptr)
    {
        cout << ptr->data << " ";
        pre_order(ptr->left);
        pre_order(ptr->right);
    }
}
// in-order traversal
void in_order(Node *ptr)
{

    if (ptr)
    {
        in_order(ptr->left);
        cout << ptr->data << " ";
        in_order(ptr->right);
    }
}
// post-order traversal
void post_order(Node *ptr)
{

    if (ptr)
    {
        post_order(ptr->left);
        post_order(ptr->right);
        cout << ptr->data << " ";
    }
}
int main()
{
    create_tree();
    cout << "pre-order>";
    pre_order(root);
    cout << "\ninorder>";
    in_order(root);
    cout << "\npost-order>";
    post_order(root);
    return 0;
}