#include "class.h"

DL_List :: DL_List() : head{NULL} {}

void DL_List::addNode(int value)
{
  Node *new_node = new Node;
  new_node->data = value;
  new_node->next = NULL;
  new_node->previous = NULL;
  if(head == NULL)
  {
    head = new_node;
  }
  else
  {
    Node *current = head;
    while(current->next != NULL)
    {
        
        current = current->next;
    } 
    current->next = new_node;
    current->next->previous = current;
  }
}

void DL_List :: printList()
{
    Node *current = head;
    while(current != NULL)
    {
        std :: cout << current->data << " ";
        current = current->next;
    }
}

void DL_List :: revPrint()
{
    Node *current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    while(current != NULL)
    {
        std :: cout << current->data << " ";
        current = current->previous;
    }
}