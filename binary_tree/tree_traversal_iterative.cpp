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
void pre_order_iterative(Node *ptr)
{
    stack<Node *> nodes;
    while (ptr != NULL || !nodes.empty())
    {

        if (ptr != NULL)
        {
            cout << ptr->data << " ";
            nodes.push(ptr);
            ptr = ptr->left;
        }
        else
        {
            ptr = nodes.top();
            nodes.pop();
            ptr = ptr->right;
        }
    }
}
void in_order_iterative(Node *ptr)
{

    stack<Node *> nodes;
    while (ptr != NULL || !nodes.empty())
    {

        if (ptr != NULL)
        {
            nodes.push(ptr);
            ptr = ptr->left;
        }
        else
        {
            ptr = nodes.top();
            nodes.pop();
            cout << ptr->data << " ";
            ptr = ptr->right;
        }
    }
}
void level_order(Node *root)
{

    queue<Node *> nodes;
    cout << root->data << " ";
    nodes.push(root);
    while (!nodes.empty())
    {

        root = nodes.front();
        nodes.pop();
        if (root->left)
        {
            cout << root->left->data << " ";
            nodes.push(root->left);
        }
        if (root->right)
        {
            cout << root->right->data << " ";
            nodes.push(root->right);
        }
    }
}
// void post_order_iterative(Node *root)
// {

//     stack<Node *> s1;
//     stack<Node *> s2;
//     s1.push(root);
//     while (!s1.empty())
//     {
//         root = s1.top();
//         s1.pop();
//         s2.push(root);
//         if (root->left != NULL)
//         {
//         }
//     }
// }
/// function to find number of nodes in a tree
int count(Node *root)
{

    if (root)
    {

        return count(root->left) + count(root->right) + root->data;
    }
    else
    {
        return 0;
    }
}
// function to find sum of all nodes
int find_sum_of_all_nodes(Node *root)
{

    if (root)
    {
        return find_sum_of_all_nodes(root->left) + find_sum_of_all_nodes(root->right) + root->data;
    }
    else
    {
        return 0;
    }
}
int main()
{
    create_tree();
    cout << count(root) << endl;
    return 0;
}