#include "bintree.h"

Bin_tree ::Bin_tree()
{
    head = NULL;
}

void Bin_tree::addNode(int value)
{
    if (head != NULL)
    {
        addNode(value, head);
    }
    else
    {
        head = new Node_t;
        head->left = NULL;
        head->right = NULL;
        head->data = value;
    }
}

void Bin_tree ::addNode(int p_value, Node_t *node)
{
    if (p_value < node->data)
    {
        if (node->left == NULL)
        {
            node->left = new Node_t;
            node->left->data = p_value;
            node->left->left = NULL;
            node->left->right = NULL;
        }
        else
        {
            addNode(p_value, node->left);
        }
    }
    else
    {
        if (p_value >= node->data)
        {
            if (node->right == NULL)
            {
                node->right = new Node_t;
                node->right->data = p_value;
                node->right->right = NULL;
                node->right->left = NULL;
            }
            else
            {
                addNode(p_value, node->right);
            }
        }
    }
}

void Bin_tree::print(Node_t *node)
{
    if (node != NULL)
    {
        print(node->left);
        std ::cout << node->data << ",";
        print(node->right);
    }
}

bool Bin_tree::contains(Node_t *node, int value)
{
    if( node != NULL)
    {
        if(node->data == value)
        {
            return true;
        }
        else
        {
            if(value < node->data) return contains(node->left,value);
            else if(value >= node->data) return contains(node->right,value);
        }

    }
    return false;
}

void Bin_tree::print()
{
    print(head);
    std ::cout << '\n';
}

bool Bin_tree::isContains(int value)
{
    return contains(head,value);
}