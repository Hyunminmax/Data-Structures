#include <stdio.h>

void InsertSort(int arr[], int n){
    int temp;
    int j;
    for(int i=1; i<n; i++){
        temp = arr[i];
        for(j=i-1; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;  
            }
        }
        arr[j+1] = temp;
    }
}

int main(void){
    int arr[7] = {3, 2, 4, 1, 5, 6, 9};

    InsertSort(arr, sizeof(arr)/sizeof(int));

    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    return 0;
}