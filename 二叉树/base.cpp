/*
 * @Author: Nie Chun
 * @Date: 2023-01-31 18:00:31
 * @LastEditors: niemike niemike@outlook.com
 * @LastEditTime: 2023-02-01 11:48:08
 * @FilePath: \CPP\二叉树\base.cpp
 */
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node* p_left;
    Node* p_right;
}Node;

void search1(Node* root)
{
    if(root == NULL)
    {
        cout << "NULL\n"; 
        return;
    }
    search1(root->p_left);
    search1(root->p_right);
    cout << root->data << endl;
}

void tree_insert(Node* & root, int data)
{
    if(root == NULL)
    {
        cout << "root is NULL" << endl;
        cout << "create new node" << endl; 
        root = new Node; 
        root->data = data;
        root->p_left = NULL;
        root->p_right = NULL;
        return;
    }

    if(root->data > data)
    {   
        if(root->p_left == NULL)
        {
            root->p_left = new Node;
            root->p_left->data = data;
            root->p_left->p_left = NULL;
            root->p_left->p_right = NULL;
        }
        tree_insert(root->p_left, data);
    }
    else if(root->data < data)
    {
        if(root->p_right == NULL)
        {
            root->p_right= new Node;
            root->p_right->data = data;
            root->p_right->p_left = NULL;
            root->p_right->p_right = NULL;
        }
        tree_insert(root->p_right, data);
    }
}

void test()
{
    Node* root_node = NULL;
    
    tree_insert(root_node, 5);
    for(int i = 0; i<10; ++i)
    {
        tree_insert(root_node, i);
    }
    search1(root_node);
}

int main()
{
    test();

    return 0;  
}