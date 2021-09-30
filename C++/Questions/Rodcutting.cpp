
#include<stdio.h>
#include<limits.h>

// max funtion
int max(int a, int b) { return (a > b)? a : b;}

// function to return optimal price of rod of length n
int cutRod(int price[], int n)
{
   int opt[n+1]; //new array to store all the optimal prices
   opt[0] = 0; //val[i] is the optimal price that can be obtained by selling rod of length i
   int i, j;

   //Filling up the val array using bottoms up approach
   for (i = 1; i<=n; i++)
   {
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
         max_val = max(max_val, price[j] + opt[i-j-1]);
       opt[i] = max_val;
   }

   return opt[n];
}

int main()
{
    int arr[] = {1, 5, 7, 9, 11, 17, 16, 18};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%d", cutRod(arr, size));
    return 0;
}
