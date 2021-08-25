#include <iostream>
#include <forward_list>
#include <list>

using namespace std;

int main()
{
    forward_list<int> fl1;
    //Sets value in singly linked list
    fl1.assign({1, 2, 3, 4, 5});
    for (int &a : fl1)
    {
        cout << a << endl;
    }
    cout << endl;
    //inserts in front of linked list
    fl1.push_front(10);
    for (int &a : fl1)
    {
        cout << a << endl;
    }
    cout << endl;
    //Sets a value a specific number of times
    //arguments: number of times data to be inserted && data
    //erases previous data if previously initialized(property of assign function)
    fl1.assign(10, 50);
    for (int &a : fl1)
    {
        cout << a << endl;
    }
    cout << endl;
    cout << fl1.max_size() << endl;

    return 0;
}