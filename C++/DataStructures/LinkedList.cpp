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
    virtual void addToLinkedListAtIndex(int data, int index) = 0;

    //Searching for an element in Linked list
    virtual int indexOfData(int data) = 0;

    //Delete a node from Linked list
    virtual void deleteFromLinkedList(int index) = 0;

    //Reverse a linked list
    virtual void reverseLinkedList() = 0;

    //Sorting the linked list
    //Basic sorting algorithm
    //Time Complexity(best | worst): O(n^2)
    virtual void sortLinkedList() = 0;

    //Count of total number of elements in linked list
    int getCount()
    {
        return count;
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
    friend SinglyLinkedList mergeTwoLinkedLists(SinglyLinkedList ll1, SinglyLinkedList ll2);
};

class DoublyLinkedList : public LinkedList
{
protected:
    struct dllnode *head;
    struct dllnode *rear;

public:
    DoublyLinkedList() : LinkedList()
    {
        head = NULL;
        rear = NULL;
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
            head->prev = NULL;
            rear = head;
            count++;
            return;
        }
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        rear = ptr->next;
        rear->prev = ptr;
        count++;
    }
    void addToLinkedListAtFront(int data)
    {
        struct dllnode *temp = (struct dllnode *)malloc(sizeof(struct dllnode));
        temp->data = data;
        temp->prev = NULL;
        if (head == NULL)
        {
            head = temp;
            head->next = NULL;
            rear = head;
            count++;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
        count++;
    }
    void printLinkedList()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
        }
        struct dllnode *ptr = head;
        while (ptr->next != NULL)
        {
            cout << ptr->data << " <-> ";
            ptr = ptr->next;
        }
        cout << ptr->data << "-> NULL" << endl;
    }
    void printLinkedListReverse()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
        }
        struct dllnode *ptr = rear;
        while (ptr->prev != NULL)
        {
            cout << ptr->data << " <-> ";
            ptr = ptr->prev;
        }
        cout << ptr->data << "-> NULL" << endl;
    }
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
            struct dllnode *ptr = head;
            int i = 0;
            while (ptr->next != NULL)
            {
                if (index == i + 1)
                {
                    struct dllnode *temp = (struct dllnode *)malloc(sizeof(struct dllnode));
                    temp->data = data;
                    temp->next = ptr->next;
                    ptr->next->prev = temp;
                    temp->prev = ptr;
                    ptr->next = temp;
                    count++;
                    return;
                }
                ptr = ptr->next;
                i++;
            }
            return;
        }
    }
    int indexOfData(int data)
    {
        if (head == NULL)
        {
            return -1;
        }
        struct dllnode *ptr = head;
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
            head->prev = NULL;
            count--;
            return;
        }
        else if (index == count - 1)
        {
            struct dllnode *ptr = head;
            while (ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = NULL;
            rear = ptr;
            count--;
            return;
        }
        else
        {
            struct dllnode *ptr = head;
            int i = 0;
            while (ptr->next != NULL)
            {
                if (index == i + 1)
                {
                    ptr->next = ptr->next->next;
                    ptr->next->prev = ptr;
                    count--;
                    return;
                }
                ptr = ptr->next;
                i++;
            }
            return;
        }
    }
    void reverseLinkedList()
    {
        struct dllnode *prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = curr->prev;
            curr->prev = next;
            curr = next;
        }
        next = head;
        head = rear;
        rear = next;
    }
    void sortLinkedList()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        struct dllnode *ptr = head, *tempPtr;
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
        temp->next = head;
        if (head == NULL)
        {
            head = temp;
            rear = head;
            count++;
            return;
        }
        rear->next = temp;
        rear = temp;
        count++;
    }
    void addToLinkedListAtFront(int data)
    {
        struct llnode *temp = (struct llnode *)malloc(sizeof(struct llnode));
        temp->data = data;
        if (head == NULL)
        {
            head = temp;
            rear = head;
            count++;
            return;
        }
        temp->next = head;
        head = temp;
        rear->next = head;
        count++;
    }
    void printLinkedList()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
        }
        struct llnode *ptr = head;
        int i = 0;
        while (true)
        {
            if (i > 0 && ptr == head)
            {
                break;
            }
            cout << ptr->data << "-> ";
            ptr = ptr->next;
            i++;
        }
        cout << ptr->data << endl;
    }
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
    int indexOfData(int data)
    {
        if (head == NULL)
        {
            return -1;
        }
        struct llnode *ptr = head;
        int i = 0;
        while (true)
        {
            if (i > 0 && ptr == head)
            {
                break;
            }
            if (ptr->data == data)
            {
                return i;
            }
            ptr = ptr->next;
            i++;
        }
        return -1;
    }
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
            rear->next = head;
            count--;
            return;
        }
        else if (index == count - 1)
        {
            struct llnode *ptr = head;
            while (ptr->next->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = head;
            rear = ptr;
            count--;
            return;
        }
        else
        {
            struct llnode *ptr = head;
            int i = 0;
            while (ptr->next != head)
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
    void reverseLinkedList()
    {
        struct llnode *prev = NULL, *curr = head, *next;
        int i = 0;
        rear = head;
        while (true)
        {
            if (i > 0 && curr == head)
            {
                break;
            }
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        head = prev;
        rear->next = head;
    }
    void sortLinkedList()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        struct llnode *ptr = head, *tempPtr;
        int temp;
        int i = 0, j = 0;
        while (true)
        {
            if (i > 0 && ptr->next == head)
            {
                break;
            }
            tempPtr = head;
            j = 0;
            while (true)
            {
                if (j > 0 && tempPtr->next == head)
                {
                    break;
                }
                if (tempPtr->data > tempPtr->next->data)
                {
                    temp = tempPtr->data;
                    tempPtr->data = tempPtr->next->data;
                    tempPtr->next->data = temp;
                }
                tempPtr = tempPtr->next;
                j++;
            }
            ptr = ptr->next;
            i++;
        }
        return;
    }
    friend CircularLinkedList mergeTwoLinkedLists(CircularLinkedList ll1, CircularLinkedList ll2);
};

//Merging two linked lists
SinglyLinkedList mergeTwoLinkedLists(SinglyLinkedList ll1, SinglyLinkedList ll2)
{
    SinglyLinkedList ll;
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

DoublyLinkedList mergeTwoLinkedLists(DoublyLinkedList ll1, DoublyLinkedList ll2)
{
    DoublyLinkedList ll;
    struct dllnode *ptr1 = ll1.head, *ptr2 = ll2.head;
    if (ll1.head == ll1.rear)
    {
        while (ptr2 != NULL)
        {
            ll.addToLinkedListAtEnd(ptr2->data);
            ptr2 = ptr2->next;
        }
    }
    else if (ll2.head == ll2.rear)
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

CircularLinkedList mergeTwoLinkedLists(CircularLinkedList ll1, CircularLinkedList ll2)
{
    CircularLinkedList ll;
    struct llnode *ptr1 = ll1.head, *ptr2 = ll2.head;
    int i = 0;
    if (ll1.isEmpty())
    {
        while (true)
        {
            if (i > 0 && ptr2 == ll2.head)
            {
                break;
            }
            ll.addToLinkedListAtEnd(ptr2->data);
            ptr2 = ptr2->next;
            i++;
        }
    }
    else if (ll2.isEmpty())
    {
        while (true)
        {
            if (i > 0 && ptr1 == ll2.head)
            {
                break;
            }
            ll.addToLinkedListAtEnd(ptr1->data);
            ptr1 = ptr1->next;
            i++;
        }
    }
    else
    {
        while (true)
        {
            if (i > 0 && ptr1 == ll1.head)
            {
                break;
            }
            ll.addToLinkedListAtEnd(ptr1->data);
            ptr1 = ptr1->next;
            i++;
        }
        i = 0;
        while (true)
        {
            if (i > 0 && ptr2 == ll2.head)
            {
                break;
            }
            ll.addToLinkedListAtEnd(ptr2->data);
            ptr2 = ptr2->next;
            i++;
        }
    }
    return ll;
}

int main()
{
    //Testing out the functions
    SinglyLinkedList ll;
    cout << "Adding in the end of singly linked list" << endl;
    for (int i = 1; i <= 10; i++)
    {
        ll.addToLinkedListAtEnd(i);
    }
    cout << "Adding at front of singly linked list" << endl;
    for (int i = 0; i > -5; i--)
    {
        ll.addToLinkedListAtFront(i);
    }
    ll.printLinkedList();

    cout << "Getting count of elements in singly linked list" << endl;
    cout << "Count: " << ll.getCount() << endl;

    cout << "Finding index of element in singly linked list" << endl;
    cout << "Index of 3: " << ll.indexOfData(3) << endl;

    cout << "Adding at index in singly linked list" << endl;
    ll.addToLinkedListAtIndex(11, 14);
    ll.addToLinkedListAtIndex(-5, 0);
    ll.addToLinkedListAtIndex(-15, 5);
    ll.printLinkedList();

    cout << "Getting count of elements in singly linked list" << endl;
    cout << "Count: " << ll.getCount() << endl;

    cout << "Finding index of element in singly linked list" << endl;
    cout << "Index of 3: " << ll.indexOfData(3) << endl;

    SinglyLinkedList ll1, ll2, ll3, ll4, ll5, ll6, ll7, ll8, ll9;

    for (int i = 1; i <= 10; i++)
    {
        ll1.addToLinkedListAtEnd(i);
    }

    cout << "Merging two singly linked list" << endl;
    for (int i = 11; i <= 20; i++)
    {
        ll2.addToLinkedListAtEnd(i);
    }
    ll3 = mergeTwoLinkedLists(ll1, ll2);
    ll3.printLinkedList();

    cout << "Merging two singly linked list" << endl;
    for (int i = 1; i <= 10; i++)
    {
        ll4.addToLinkedListAtEnd(i);
    }
    ll6 = mergeTwoLinkedLists(ll4, ll5);
    ll6.printLinkedList();

    cout << "Merging two singly linked list" << endl;
    for (int i = 11; i <= 20; i++)
    {
        ll8.addToLinkedListAtEnd(i);
    }
    ll9 = mergeTwoLinkedLists(ll7, ll8);
    ll9.printLinkedList();

    SinglyLinkedList ll10;

    cout << "Adding in the end of singly linked list" << endl;
    ll10.addToLinkedListAtEnd(19230);
    ll10.addToLinkedListAtEnd(19232123);
    ll10.addToLinkedListAtEnd(3248720);
    ll10.addToLinkedListAtEnd(9435);
    ll10.addToLinkedListAtEnd(-1239549);
    ll10.addToLinkedListAtEnd(293);
    ll10.addToLinkedListAtEnd(39034);
    ll10.addToLinkedListAtEnd(32);
    ll10.printLinkedList();

    cout << "Sorting singly linked list" << endl;
    ll10.sortLinkedList();
    ll10.printLinkedList();

    cout << "Reversing singly linked list" << endl;
    ll10.reverseLinkedList();
    ll10.printLinkedList();

    cout << "Deleting the start of singly linked list" << endl;
    ll10.deleteFromLinkedList(0);
    ll10.printLinkedList();

    cout << "Deleting last index of singly linked list" << endl;
    ll10.deleteFromLinkedList(6);
    ll10.printLinkedList();

    cout << "Deleting random index of singly linked list" << endl;
    ll10.deleteFromLinkedList(3);
    ll10.printLinkedList();

    CircularLinkedList cll1, cll2, cll3;
    cout << "Adding in the end of circular linked list" << endl;
    cll1.addToLinkedListAtEnd(1);
    cll1.addToLinkedListAtEnd(2);
    cll1.addToLinkedListAtEnd(3);
    cll1.addToLinkedListAtEnd(4);
    cll1.addToLinkedListAtEnd(5);
    cll1.addToLinkedListAtEnd(6);
    cll1.printLinkedList();

    cout << "Adding at front of circular linked list" << endl;
    cll1.addToLinkedListAtFront(0);
    cll1.addToLinkedListAtFront(-1);
    cll1.addToLinkedListAtFront(-2);
    cll1.addToLinkedListAtFront(-3);
    cll1.printLinkedList();

    cll2.addToLinkedListAtEnd(1);
    cll2.addToLinkedListAtEnd(2);
    cll2.addToLinkedListAtEnd(3);
    cll2.addToLinkedListAtEnd(4);
    cll2.addToLinkedListAtEnd(5);
    cll2.addToLinkedListAtEnd(6);

    cout << "Merging two circular linked list" << endl;
    cll3 = mergeTwoLinkedLists(cll1, cll2);

    cout << "Adding at index in circular linked list" << endl;
    cll3.addToLinkedListAtIndex(10, 3);
    cll3.printLinkedList();

    cout << "Getting count of elements in circular linked list" << endl;
    cout << "Count : " << cll3.getCount() << endl;

    cout << "Deleting the start of circular linked list" << endl;
    cll3.deleteFromLinkedList(0);
    cll3.printLinkedList();

    cout << "Deleting random index of circular linked list" << endl;
    cll3.deleteFromLinkedList(10);
    cll3.printLinkedList();

    cout << "Deleting last index of circular linked list" << endl;
    cll3.deleteFromLinkedList(14);
    cll3.printLinkedList();

    cout << "Finding index of element in circular linked list" << endl;
    cout << "Index of 3: " << cll3.indexOfData(3) << endl;

    cout << "Reversing circular linked list" << endl;
    cll3.reverseLinkedList();
    cll3.printLinkedList();

    cout << "Sorting circular linked list" << endl;
    cll3.sortLinkedList();
    cll3.printLinkedList();

    DoublyLinkedList dll1, dll2, dll3;

    cout << "Adding in the end of doubly linked list" << endl;
    for (int i = 1; i <= 10; i++)
    {
        dll1.addToLinkedListAtEnd(i);
    }
    dll1.printLinkedList();
    dll1.printLinkedListReverse();

    cout << "Adding at front of doubly linked list" << endl;
    for (int i = 0; i > -10; i--)
    {
        dll1.addToLinkedListAtFront(i);
    }
    dll1.printLinkedList();
    dll1.printLinkedListReverse();

    for (int i = 10; i <= 15; i++)
    {
        dll2.addToLinkedListAtEnd(i);
    }

    cout << "Merging two doubly linked list" << endl;
    dll3 = mergeTwoLinkedLists(dll1, dll2);
    dll3.printLinkedList();
    dll3.printLinkedListReverse();

    cout << "Adding at index in doubly linked list" << endl;
    dll3.addToLinkedListAtIndex(100, 5);
    dll3.printLinkedList();
    dll3.printLinkedListReverse();

    cout << "Finding index of element in doubly linked list" << endl;
    cout << "Index of 10: " << dll3.indexOfData(10) << endl;

    cout << "Deleting the start of doubly linked list" << endl;
    dll3.deleteFromLinkedList(0);
    dll3.printLinkedList();
    dll3.printLinkedListReverse();

    cout << "Deleting random index of doubly linked list" << endl;
    dll3.deleteFromLinkedList(10);
    dll3.printLinkedList();
    dll3.printLinkedListReverse();

    cout << "Deleting last index of doubly linked list" << endl;
    int c = dll3.getCount();
    dll3.deleteFromLinkedList(c - 1);
    dll3.printLinkedList();
    dll3.printLinkedListReverse();

    cout << "Sorting doubly linked list" << endl;
    dll3.sortLinkedList();
    dll3.printLinkedList();
    dll3.printLinkedListReverse();

    cout << "Reversing doubly linked list" << endl;
    dll3.reverseLinkedList();
    dll3.printLinkedList();
    dll3.printLinkedListReverse();

    return 0;
}