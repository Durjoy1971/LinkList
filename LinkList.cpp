#include <bits/stdc++.h>

using namespace std;

class node
{
public:
  int data;
  node *next;

  node(int val)
  {
    data = val;
    next = NULL;
  }
};

void insertAtHead(node *&head, int val)
{
  node *n = new node(val);
  n->next = head;
  head = n;
}

void insertAtTail(node *&head, int val)
{

  node *n = new node(val);

  if (head == NULL)
  {
    head = n;
    return;
  }

  node *temp = head;

  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = n;
}

void display(node *head)
{
  node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " --> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

void deletion(node *&head, int val)
{

  if (head == NULL)
  {
    return;
  }

  if (head->next == NULL or head->data == val)
  {
    node *todelete = head;
    head = head->next;

    delete todelete;
    return;
  }

  node *temp = head;
  // 1 --> 2 --> 3
  while (temp->next != NULL and temp->next->data != val)
  {
    temp = temp->next;
  }

  if (temp->next == NULL)
    return;

  node *todelete = temp->next;
  temp->next = temp->next->next;

  delete todelete;
}

bool search(node *head, int key)
{
  node *temp = head;
  while (temp != NULL)
  {
    if (temp->data == key)
      return true;
    temp = temp->next;
  }
  return false;
}

int main()
{

  node *head = NULL;

  insertAtTail(head, 1);
  insertAtTail(head, 12);
  insertAtTail(head, 10);
  insertAtTail(head, 15);
  insertAtTail(head, 20);

  display(head);

  deletion(head, 20);

  display(head);

  return 0;
}