#include <iostream>

using namespace std;

//Structure to hold linked list data
struct llnode
{
    int data;
    struct llnode *next;
};

//Structure to hold doubly linked list
struct dllnode
{
    int data;
    struct dllnode *next;
    struct dllnode *prev;
};

//Class for linked list
class LinkedList
{
protected:
    struct llnode *head;
    int count;

    //Counter function(counts the number of elements in linked list)
    int counter()
    {
        struct llnode *ptr = head;
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
    //Initialize in the beginning
    LinkedList()
    {
        head = NULL;
        count = 0;
    }

    //Add to a linked list at the end
    virtual void addToLinkedListAtEnd(int data) = 0;

    //Add to a linked list in the front
    virtual void addToLinkedListAtFront(int data) = 0;

    //Add to linked list at an index
    void addToLinkedListAtIndex(int data, int index)
    {
        if (index >= count || index < 0)
        {
            cout << "Element out of index" << endl;
            return;
        }
        else if (index == 0)
        {
            addToLinkedListAtFront(data);
            return;
        }
        else if (index == count - 1)
        {
            addToLinkedListAtEnd(data);
            return;
        }
        else
        {
            struct llnode *ptr = head;
            int i = 0;
            while (ptr->next != NULL)
            {
                if (index == i + 1)
                {
                    struct llnode *temp = (struct llnode *)malloc(sizeof(struct llnode));
                    temp->data = data;
                    temp->next = ptr->next;
                    ptr->next = temp;
                    count += 1;
                    return;
                }
                ptr = ptr->next;
                i++;
            }
            return;
        }
    }

    //Searching for an element in Linked list
    int indexOfData(int data)
    {
        if (head == NULL)
        {
            return -1;
        }
        struct llnode *ptr = head;
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

    //Delete a node from Linked list
    void deleteFromLinkedList(int index)
    {
        if (head == NULL || index >= count)
        {
            cout << "Element out of index" << endl;
            return;
        }
        else if (index == 0)
        {
            head = head->next;
            count--;
            return;
        }
        else if (index == count - 1)
        {
            struct llnode *ptr = head;
            while (ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = NULL;
            count--;
            return;
        }
        else
        {
            struct llnode *ptr = head;
            int i = 0;
            while (ptr->next != NULL)
            {
                if (index == i + 1)
                {
                    ptr->next = ptr->next->next;
                    count--;
                    return;
                }
                ptr = ptr->next;
                i++;
            }
            return;
        }
    }

    //Reverse a linked list
    void reverseLinkedList()
    {
        struct llnode *prev = NULL, *curr = head, *next;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    //Sorting the linked list
    //Basic sorting algorithm
    //Time Complexity(best | worst): O(n^2)
    void sortLinkedList()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        struct llnode *ptr = head, *tempPtr;
        int temp;
        while (ptr->next != NULL)
        {
            tempPtr = head;
            while (tempPtr->next != NULL)
            {
                if (tempPtr->data > tempPtr->next->data)
                {
                    temp = tempPtr->data;
                    tempPtr->data = tempPtr->next->data;
                    tempPtr->next->data = temp;
                }
                tempPtr = tempPtr->next;
            }
            ptr = ptr->next;
        }
        return;
    }

    //Count of total number of elements in linked list
    int getCount()
    {
        return count == counter() ? count : counter() - count;
    }

    //Print the Linked list
    void printLinkedList()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
        }
        struct llnode *ptr = head;
        while (ptr->next != NULL)
        {
            cout << ptr->data << "-> ";
            ptr = ptr->next;
        }
        cout << ptr->data << "-> NULL" << endl;
    }

    //Checking if Linked list is empty
    bool isEmpty()
    {
        return head == NULL ? true : false;
    }
};

//Merging two linked lists
template <typename T>
T mergeTwoLinkedLists(T ll1, T ll2)
{
    T ll;
    struct llnode *ptr1 = ll1.head, *ptr2 = ll2.head;
    if (ll1.isEmpty())
    {
        while (ptr2 != NULL)
        {
            ll.addToLinkedListAtEnd(ptr2->data);
            ptr2 = ptr2->next;
        }
    }
    else if (ll2.isEmpty())
    {
        while (ptr1 != NULL)
        {
            ll.addToLinkedListAtEnd(ptr1->data);
            ptr1 = ptr1->next;
        }
    }
    else
    {
        while (ptr1 != NULL)
        {
            ll.addToLinkedListAtEnd(ptr1->data);
            ptr1 = ptr1->next;
        }
        while (ptr2 != NULL)
        {
            ll.addToLinkedListAtEnd(ptr2->data);
            ptr2 = ptr2->next;
        }
    }
    return ll;
}

class SinglyLinkedList : public LinkedList
{
public:
    SinglyLinkedList() : LinkedList() {}
    void addToLinkedListAtEnd(int data)
    {
        struct llnode *ptr = head;
        struct llnode *temp = (struct llnode *)malloc(sizeof(struct llnode));
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
        struct llnode *temp = (struct llnode *)malloc(sizeof(struct llnode));
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
    friend SinglyLinkedList mergeTwoLinkedLists(SinglyLinkedList ll1, SinglyLinkedList ll2);
};

class DoublyLinkedList : public LinkedList
{
protected:
    struct dllnode *head;
    struct dllnode *rear;

public:
    DoublyLinkedList()
    {
        head = NULL;
        rear = NULL;
        count = 0;
    }
    void addToLinkedListAtEnd(int data)
    {
        struct dllnode *ptr = head;
        struct dllnode *temp = (struct dllnode *)malloc(sizeof(struct dllnode));
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
        struct dllnode *temp = (struct dllnode *)malloc(sizeof(struct dllnode));
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
    friend DoublyLinkedList mergeTwoLinkedLists(DoublyLinkedList ll1, DoublyLinkedList ll2);
};
class CircularLinkedList : public LinkedList
{
protected:
    struct llnode *rear;

public:
    CircularLinkedList() : LinkedList()
    {
        rear = NULL;
    }
    void addToLinkedListAtEnd(int data)
    {
        struct llnode *ptr = head;
        struct llnode *temp = (struct llnode *)malloc(sizeof(struct llnode));
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
        struct llnode *temp = (struct llnode *)malloc(sizeof(struct llnode));
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
    friend CircularLinkedList mergeTwoLinkedLists(CircularLinkedList ll1, CircularLinkedList ll2);
};

int main()
{
    //Testing out the functions
    SinglyLinkedList ll;
    for (int i = 1; i <= 10; i++)
    {
        ll.addToLinkedListAtEnd(i);
    }
    for (int i = 0; i > -5; i--)
    {
        ll.addToLinkedListAtFront(i);
    }
    ll.printLinkedList();

    cout << "Count: " << ll.getCount() << endl;

    cout << "Index of 3: " << ll.indexOfData(3) << endl;

    ll.addToLinkedListAtIndex(11, 14);
    ll.addToLinkedListAtIndex(-5, 0);
    ll.addToLinkedListAtIndex(-15, 5);
    ll.printLinkedList();

    cout << "Count: " << ll.getCount() << endl;
    cout << "Index of 3: " << ll.indexOfData(3) << endl;

    SinglyLinkedList ll1, ll2, ll3, ll4, ll5, ll6, ll7, ll8, ll9;

    for (int i = 1; i <= 10; i++)
    {
        ll1.addToLinkedListAtEnd(i);
    }
    for (int i = 11; i <= 20; i++)
    {
        ll2.addToLinkedListAtEnd(i);
    }
    ll3 = mergeTwoLinkedLists(ll1, ll2);
    ll3.printLinkedList();

    for (int i = 1; i <= 10; i++)
    {
        ll4.addToLinkedListAtEnd(i);
    }
    ll6 = mergeTwoLinkedLists(ll4, ll5);
    ll6.printLinkedList();

    for (int i = 11; i <= 20; i++)
    {
        ll8.addToLinkedListAtEnd(i);
    }
    ll9 = mergeTwoLinkedLists(ll7, ll8);
    ll9.printLinkedList();

    SinglyLinkedList ll10;

    ll10.addToLinkedListAtEnd(19230);
    ll10.addToLinkedListAtEnd(19232123);
    ll10.addToLinkedListAtEnd(3248720);
    ll10.addToLinkedListAtEnd(9435);
    ll10.addToLinkedListAtEnd(-1239549);
    ll10.addToLinkedListAtEnd(293);
    ll10.addToLinkedListAtEnd(39034);
    ll10.addToLinkedListAtEnd(32);

    ll10.printLinkedList();
    ll10.sortLinkedList();
    ll10.printLinkedList();

    ll10.reverseLinkedList();
    ll10.printLinkedList();

    ll10.deleteFromLinkedList(0);
    ll10.printLinkedList();

    ll10.deleteFromLinkedList(6);
    ll10.printLinkedList();

    ll10.deleteFromLinkedList(3);
    ll10.printLinkedList();

    return 0;
}