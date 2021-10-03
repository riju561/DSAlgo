/*

This is used to convert a binary to grey number.

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int greyConverter(int n)
{
    //Performing Right Shift on n, 1 time.
    int q = n >> 1;

    //returning the result of XOR opertaion of n and q
    //which gives gray code.
    return n ^ q;
}
int main()
{
    int n;
    cin >> n;
    greyConverter(n);
    return 0;
}