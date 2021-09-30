#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n/2;i++){
        int t=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=t;
    }
    printf("Reversed Array:\n");
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}