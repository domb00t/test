#include "linked_list.h"

List ::List()
{
    head = NULL;
}

void List ::addNode(int value)
{
    Node_t *new_node = new Node_t;
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node_t *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void List ::print()
{
    Node_t *current = head;
    while (current != NULL)
    {
        std ::cout << current->data << ' ';
        current = current->next;
    }
}

void List::eraseLastNode()
{
    Node_t *current = head;
    if (current != NULL)
    {
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        delete current->next->next;
        current->next = NULL;
    }
}

bool List ::isContains(int value)
{
    Node_t *current = head;
    bool fl = false;
    if (current != NULL)
    {
        while (current != NULL)
        {
            fl = fl || current->data == value;
            current = current->next;
        }
    }

    return fl;
}

void List ::deleteByValue(int value)
{
    Node_t *current = head;
    Node_t *previous = head;
    bool fl = true;
    if (current != NULL)
    {
        if (current->data == value)
        {
            head = current->next;
            delete current;
        }
        else
        {

            while (current != NULL && fl)
            {

                if (current->data == value)
                {
                    previous->next = current->next;
                    delete current;
                    fl = false;
                }
                else
                {
                    previous = current;
                    current = current->next;
                }
            }
        }
    }
}