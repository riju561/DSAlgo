
#include<stdio.h>
int main(){
    int n,arr[100],temp,k = n;
    printf("Enter value of n: ");
    scanf("%d",&n);
    printf("Enter the values of elements in the array of size %d:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
       
        for(int j=1;j<n;j++){
            if(arr[j]<arr[j-1]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    
    }
    printf("The sorted array is: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
