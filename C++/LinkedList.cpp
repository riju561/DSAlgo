#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

class LinkedList
{
private:
    struct node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void addToLinkedListAtEnd(int data)
    {
        struct node *ptr = head;
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            return;
        }
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    void addToLinkedListAtFront(int data)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        if (head == NULL)
        {
            head = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }
    void printLinkedList()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
        }
        while (head != NULL)
        {
            cout << "data: " << head->data << endl;
            head = head->next;
        }
    }
};

int main()
{
    LinkedList ll;
    for (int i = 1; i <= 10; i++)
    {
        ll.addToLinkedListAtEnd(i);
    }
    for (int i = 0; i >-5; i--)
    {
        ll.addToLinkedListAtFront(i);
    }
    ll.printLinkedList();
    return 0;
}