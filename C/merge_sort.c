#include<stdio.h>

//function to merge two arrays
void merge(int book[],int l,int mid,int r){
    int n1= mid-l+1;
    int n2=r-mid;
    //create temp arrays
    int a[n1];
    int b[n2];
    //copying data to a[n1] and b[n2] from book[]
    for(int i=0;i<n1;i++){
        a[i]=book[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=book[mid+1+i];
    }

    int i=0,j=0,k=l;
    //merge the temp arrays back to book[]
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            book[k]=a[i];
            k++;
            i++;
        }
        else{
            book[k]=b[j];
            k++;
            j++;
        }
    }
    //copying  the remaining elements of a[], if there are any
    while(i<n1){
        book[k] =a[i];
        k++;
        i++;
    }
    //copying  the remaining elements of b[], if there are any
    while(j<n2){
        book[k]=b[j];
        k++;
        j++;
    }
}
void merge_sort(int book[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        merge_sort(book,l,mid); //sort the first half
        merge_sort(book,mid+1,r);//sort the second half
        merge(book,l,mid,r); // merge the the two sorted halves into sorted array
    }
    
}
int main(){
    int n;
    int a[n];
     printf("Enter the number of numbers-->");
     scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the Number %d --> ",i+1);
        scanf("%d",&a[i]);
    }
    merge_sort(a,0,n-1);
    printf("Sorted Order of Numbers is : \n");
    for(int i=0;i<n;i++){
      printf("Position %d- %d  \n",i+1,a[i]);
    }
}