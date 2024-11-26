#include <stdio.h>
#include <stdlib.h>
void MergeTwoArea(int arr[], int left, int mid, int right){
    int lIdx = left;
    int rIdx = mid+1;
    int sortedIdx = left;
    int * sortArr = (int*)malloc(sizeof(int)*(right+1));

    while(lIdx <= mid && rIdx <= right){
        if(arr[rIdx] < arr[lIdx]){
            sortArr[sortedIdx] = arr[rIdx++];
        }
        else{
            sortArr[sortedIdx] = arr[lIdx++];
        }
        sortedIdx++;
    }
    if(lIdx > mid){
        for(int i=rIdx; i<=right; i++, sortedIdx++){
            sortArr[sortedIdx] = arr[i];
        }
    }else{
        for(int i=lIdx; i<=mid; i++, sortedIdx++){
            sortArr[sortedIdx] = arr[i];
        }
    }
    for(int i=left; i<=right; i++){
        arr[i] = sortArr[i];
    }
    free(sortArr);
}

void MergeSort(int arr[], int left, int right){
    int mid;
    
    if(left < right){
        mid = (left+right)/2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);

        MergeTwoArea(arr, left, mid, right);
    }

}

int main(void){
    int arr[7] = {3, 2, 4, 1, 5, 6, 9};
    MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);

    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }

    return 0;
}