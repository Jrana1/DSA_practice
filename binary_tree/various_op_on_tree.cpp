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

int count_nodes(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    else
    {

        return count_nodes(root->left) + count_nodes(root->right) + 1;
    }
}

int count_nodes_having_two_children(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    else
    {

        if (root->left && root->right)
        {

            return count_nodes_having_two_children(root->left) + count_nodes_having_two_children(root->right) + 1;
        }
        else
        {
            return count_nodes_having_two_children(root->left) + count_nodes_having_two_children(root->right);
        }
    }
}
int count_leaf_node(Node *root)
{

    if (root == NULL)
    {

        return 0;
    }
    else
    {

        if (!root->left && !root->right)
        {
            return count_leaf_node(root->left) + count_leaf_node(root->right) + 1;
        }
        else
        {
            return count_leaf_node(root->left) + count_leaf_node(root->right);
        }
    }
}
int count_node_degree_one(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    else
    {

        if ((root->left && !root->right) || (!root->left && root->right))
        {
            return count_node_degree_one(root->left) + count_node_degree_one(root->right) + 1;
        }
        else
        {
            return count_node_degree_one(root->left) + count_node_degree_one(root->right);
        }
    }
}

int fun(Node *root)
{
    int x, y;
    if (root)
    {

        x = fun(root->left);
        y = fun(root->right);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}
int main()
{

    create_tree();
    cout << count_nodes(root) << endl;
    cout << count_nodes_having_two_children(root) << endl;
    cout << count_node_degree_one(root) << endl;
    cout << count_leaf_node(root) << endl;
    cout << fun(root) << endl;

    return 0;
}