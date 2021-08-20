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
    int count;
    int counter()
    {
        struct node *ptr = head;
        if (head == NULL)
        {
            return 0;
        }
        int i = 1;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        return i;
    }

public:
    LinkedList()
    {
        head = NULL;
        count = 0;
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
            count++;
            return;
        }
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        count++;
    }
    void addToLinkedListAtFront(int data)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        if (head == NULL)
        {
            head = temp;
            count++;
            return;
        }
        temp->next = head;
        head = temp;
        count++;
    }
    void addToLinkedListInMiddle(int data, int index)
    {
        return;
    }
    int indexOfData(int data)
    {
        if (head == NULL)
        {
            return -1;
        }
        struct node *ptr = head;
        int i = 0;
        while (ptr->next != NULL)
        {
            if (ptr->data == data)
            {
                return i;
            }
            ptr = ptr->next;
            i++;
        }
        return -1;
    }
    int getCount()
    {
        return count;
    }
    void printLinkedList()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
        }
        struct node *ptr = head;
        while (ptr != NULL)
        {
            cout << "data: " << ptr->data << endl;
            ptr = ptr->next;
        }
    }
};

int main()
{
    LinkedList ll;
    for (int i = 1; i <= 10; i++)
    {
        ll.addToLinkedListAtEnd(i);
        cout << "Count: " << ll.getCount() << endl;
    }
    for (int i = 0; i > -5; i--)
    {
        ll.addToLinkedListAtFront(i);
        cout << "Count: " << ll.getCount() << endl;
    }
    ll.printLinkedList();
    cout << "Index of 3: " << ll.indexOfData(3) << endl;
    return 0;
}