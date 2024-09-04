#include <iostream>

struct Node_t
{
    int value;
    Node_t *left;
    Node_t *right;
};

class bin_tree
{
private:
    Node_t *head;
    void addNode(int, Node_t *);
    void print(Node_t *);
    bool contains(Node_t*,int);
    void deleteTree(Node_t *);

public:
    bin_tree();
    void addNode(int);
    void print();
    bool contains(int);
    ~bin_tree();
};

bin_tree ::bin_tree()
{
    head = NULL;
}

void bin_tree::addNode(int value)
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
        head->value = value;
    }
}

void bin_tree ::addNode(int p_value, Node_t *node)
{
    if (p_value < node->value)
    {
        if (node->left == NULL)
        {
            node->left = new Node_t;
            node->left->value = p_value;
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
        if (p_value >= node->value)
        {
            if (node->right == NULL)
            {
                node->right = new Node_t;
                node->right->value = p_value;
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

void bin_tree::print(Node_t *node)
{
    if (node != NULL)
    {
        print(node->left);
        std ::cout << node->value << ",";
        print(node->right);
    }
}

bool bin_tree::contains(Node_t *node, int value)
{
    if( node != NULL)
    {
        if(node->value == value)
        {
            return true;
        }
        else
        {
            if(value < node->value) return contains(node->left,value);
            else if(value >= node->value) return contains(node->right,value);
        }

    }
    return false;
}

void bin_tree::print()
{
    print(head);
    std ::cout << '\n';
}

void bin_tree :: deleteTree(Node_t* node)
{
    if(node != NULL)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

bin_tree :: ~bin_tree()
{
    deleteTree(head);
}

bool bin_tree::contains(int value)
{
    return contains(head,value);
}

int main()
{
    class bin_tree btree;
    for(int i = 0;i < 100;i++)
    {
        btree.addNode(i+1);
    }

    std :: cout << btree.contains(12) << '\n';

    btree.print();
    return 0;
}