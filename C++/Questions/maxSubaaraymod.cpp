#include<bits/stdc++.h>
using namespace std;
 
// Return the maximum sum subarray mod m.
int maxSubarray(int arr[], int n, int m)
{
    int x, prefix = 0, maxim = 0;
 
    set<int> S;
    S.insert(0);   
 
    // Traversing the array.
    for (int i = 0; i < n; i++)
    {
        // Finding prefix sum.
        prefix = (prefix + arr[i])%m;
 
        // Finding maximum of prefix sum.
        maxim = max(maxim, prefix);
 
        auto it = S.lower_bound(prefix+1);
 
        if (it != S.end())
            maxim = max(maxim, prefix - (*it) + m );
 
        // Inserting prefix in the set.
        S.insert(prefix);
    }
 
    return maxim;
}

int main() {
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cout << maxSubarray(arr, n, m) << endl;
    return 0;
}