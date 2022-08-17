#include <bits/stdc++.h>
using namespace std;
// node struct
struct Node
{
    int data;
    Node *next;
};
/// function to create a new node
Node *create_node(int val)
{
    Node *ptr = new Node;
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}

// function to add a new node at tail of a list
Node *add_node(Node *head, int val)
{
    Node *ptr = create_node(val);
    if (head == NULL)
    {
        head = ptr;
        return head;
    }
    while (head->next)
    {
        head = head->next;
    }
    head->next = ptr;
    return head;
}

// function to display all the element of a list
void display(Node *head)
{
    while (head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
/// function to find the length of a list
int len(Node *head)
{
    int cnt = 0;
    while (head)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}

// function to add a new node at a given position
Node *insert(Node *head, int val, int pos)
{
    int len1 = len(head);
    if (pos < 0 || pos > len1)
    {
        return NULL;
    }
    Node *ptr = create_node(val);
    if (pos == 0)
    {
        ptr->next = head;
        head = ptr;
        return head;
    }
    for (int i = 1; i < pos; i++)
    {
        head = head->next;
    }
    ptr->next = head->next;
    head->next = ptr;
}
// function to delete all the appearance of a given element from a list

Node *delete_val(Node *head, int val)
{
    while (head && head->data == val)
    {
        Node *p = head;
        head = head->next;
        delete p;
    }
    if (head == NULL)
    {

        return head;
    }
    Node *prev = head;
    Node *nxt = head->next;

    while (nxt)
    {

        if (nxt->data == val)
        {
            Node *p = nxt;
            prev->next = nxt->next;
            nxt = nxt->next;
            delete p;
        }
        else
        {
            prev = nxt;
            nxt = nxt->next;
        }
    }
    return head;
}
// check if a list is sorted or not
bool isSorted(Node *head)
{

    Node *nxt = head->next;
    while (nxt)
    {

        if (nxt->data < head->data)
        {
            return false;
        }
        head = nxt;
        nxt = nxt->next;
    }
    return true;
}

/// print all the elements of a link list in reverse order using Recursion.

void print_reverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }                          // base case when list is empty return
    print_reverse(head->next); // recursive call for the next node
    cout << head->data << " "; // while returning back print the element
}
/// finding sum of all the elements of a linked list using Recursion
int find_sum(Node *head)
{

    if (head->next == NULL)
    {
        return head->data;
    }
    return head->data + find_sum(head->next);
}

// delete duplicates element from a sorted linked list
// also a leedCode problem : https://leetcode.com/problems/remove-duplicates-from-sorted-list
Node *delete_duplicates(Node *head)
{
    // Node *ptr = head;
    if (head == NULL)
    {
        return head;
    }
    Node *nxt = head->next;
    while (nxt)
    {

        if (nxt->data != head->data)
        {
            head = nxt;
            nxt = nxt->next;
        }
        else
        {
            head->next = nxt->next;
            delete nxt;
            nxt = head->next;
        }
    }
    // return ptr;
}

// Reversing a linked list using Sliding pointer (Three Pointer)

Node *reverse_iterative(Node *head)
{
    Node *p = head, *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

// Reversing using Recursion and two pointers
// in this case we have to declare head as Global
// Node *reverse1(Node *p, Node *q)
// {
//     if (p)
//     {

//         reverse1(p->next, p);
//         p->next = q;
//     }
//     else
//     {
//         head = q;
//     }
// }
// Another way of Reversing in a recursive way but using only one pointer

Node *reverse2(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = reverse2(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void concat_two_linked_list(Node *head1, Node *head2)
{
    while (head1->next)
    {
        head1 = head1->next;
    }
    head1->next = head2;
}

Node *merge_two_sorted_linked_list(Node *h1, Node *h2)
{

    Node *t = NULL, *l = NULL; // t=third head,l = last/tail

    if (h1->data < h2->data)
    {
        t = h1;
        l = h1;
        h1 = h1->next;
        l->next = NULL;
    }
    else
    {
        t = h2;
        l = h2;
        h2 = h2->next;
        l->next = NULL;
    }
    while (h1 && h2)
    {

        if (h1->data < h2->data)
        {
            l->next = h1;
            l = h1;
            h1 = h1->next;
            l->next = NULL;
        }
        else
        {
            l->next = h2;
            l = h2;
            h2 = h2->next;
            l->next = NULL;
        }
    }
    // while (h1)
    // {
    //     l->next = h1;
    //     l = h1;
    //     h1 = h1->next;
    //     l->next = NULL;
    // }
    // while (h2)
    // {
    //     l->next = h2;
    //     l = h2;
    //     h2 = h2->next;
    //     l->next = NULL;
    // }
    // or
    if (h1)
    {
        l->next = h1;
    }
    else
    {
        l->next = h2;
    }
    return t;
}
// detect if a Linked list has a loop or not using slow and fast pointer
bool hasLoop(Node *head)
{

    Node *slow = head, *fast = head;
    while (fast)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
/// another way to detect loop in a linked list is by using extra Space
bool hasLoop1(Node *head)
{

    multiset<Node *> nodes;
    while (head)
    {
        if (nodes.count(head) > 0)
        {
            return true;
        }
        else
        {
            nodes.insert(head);
        }
        head = head->next;
    }
    nodes.clear();
    return false;
}

// How to find the intersecting point of two linked lists

// Method 1 : using two stacks

Node *intersecting_node(Node *h1, Node *h2)
{

    stack<Node *> nodes1;
    stack<Node *> nodes2;
    while (h1)
    {
        nodes1.push(h1);
        h1 = h1->next;
    }
    while (h2)
    {
        nodes2.push(h2);
        h2 = h2->next;
    }
    Node *tmp;
    while (nodes1.top() == nodes2.top())
    {

        tmp = nodes1.top();
        nodes1.pop();
        nodes2.pop();
    }
    return tmp;
}

// Method 2: without any extra space
// first find the len of both lists
// second determine the largest list between both of them
// third  find the diff between l1 and l2
// fourth  bring the start position of largest list at the same position like the other list
// now iterate throught both the lists and check if both of the nodes habe the same address then return true
// otherwise return false
Node *intersecting_node1(Node *h1, Node *h2)
{

    int l1 = len(h1);
    int l2 = len(h2);
    Node *ptr1, *ptr2;
    int d = 0;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = h1;
        ptr2 = h2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = h2;
        ptr2 = h1;
    }
    // d--;
    while (d)
    {
        d--;
        ptr1 = ptr1->next;
    }
    while (ptr1 && ptr2)
    {

        if (ptr1 == ptr2)
        {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}
int main()
{

    Node *h1 = NULL, *h2 = NULL;
    h1 = add_node(h1, 5);
    add_node(h1, 7);
    add_node(h1, 8);
    add_node(h1, 9);
    add_node(h1, 10);
    h2 = add_node(h2, 0);
    add_node(h2, 1);
    display(h1);
    display(h2);
    // making intersecting point between two lists

    h2->next->next = h1->next;
    display(h2);
    cout << intersecting_node1(h1, h2)->data << endl;
    // cout << intersecting_node(h1, h2)->data << endl;
    // Node *head1 = NULL;

    // head1 = add_node(head1, 1);
    // add_node(head1, 2);
    // add_node(head1, 0);
    // add_node(head1, 3);
    // cout << hasLoop1(head1) << endl;
    // head1->next->next->next = head1->next;
    // cout << hasLoop1(head1) << endl;

    return 0;
}