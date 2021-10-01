#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int l, int r)
{
    int p=a[l];
    int i=l,j=r+1;
    while(i<j)
    {
        do{i++;}while(i<=r&&a[i]<p);
        do{j--;}while(j>0&&a[j]>p);
        if(i<j)
        swap(&a[i],&a[j]);
    }
    swap(&a[j],&a[l]);
    return j;
}

void quicksort(int a[], int l, int r)// Best Case- O(nlogn) Worst Case- O(n^2)
{
    if(l<r)
    {
        int p=partition(a,l,r);
        quicksort(a,0,p-1);
        quicksort(a,p+1,r);
    }
}

void print(int a[],int n)
{
    printf("Array-\n");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
}

int main()
{
    int n,r=0;
   printf("Enter the size of the array--\n");
    scanf("%d",&n);  
    srand(time(0));
    int a[n];
   
    for(int i=0;i<n;i++)
     a[i]=rand()%20;
  // Printing the unsorted array
    print(a,n);
    quicksort(a,0,n-1);
  // Printing the sorted array
    print(a,n);
}
