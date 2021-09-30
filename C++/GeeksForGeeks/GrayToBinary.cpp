/*

This is used to convert a grey number to binary number.

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int grayToBinary(int n)
{
    int b = 0;
    //We use a loop and Right shift n everytime until it becomes 0.
    for (n = n; n > 0; n = n >> 1)
        //We use XOR operation which stores the result of conversion in b.
        b ^= n;

    //returning the Binary equivalent.
    return b;
}
int main()
{
    int n;
    cin >> n;
    grayToBinary(n);
    return 0;
}