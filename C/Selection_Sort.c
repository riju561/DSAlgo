#include<stdio.h>
void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j])min=j;
        }
        if(i!=min)swap(&a[min],&a[i]);
    }
    printf("Sorted Array:\n");
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}