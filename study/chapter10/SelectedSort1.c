#include <stdio.h>
void SelectedSort(int arr[], int n){
    int targetIdx;

    for(int i=0; i<n-1; i++){
        targetIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[targetIdx] > arr[j]){
                targetIdx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[targetIdx];
        arr[targetIdx] = temp;
    }

}

int main(void){

    int arr[4] = {3, 2, 4, 1};

    SelectedSort(arr, sizeof(arr)/sizeof(int));
    for(int i=0; i<4; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}