#include <stdio.h>

int GetPivot(int left, int mid, int right){

}

void QuickSort(int arr[], int left, int right){
    int pivot = GetPivot(left, right/2, right);
    int pivot;

}

int main(void){
    int arr[10] = {9, 3, 2, 4, 1, 5, 6, 7, 8, 10};

    QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    return 0;
}