#include <stdio.h>

void BubbleSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++){            
        for(int j=0; j<(n-i)-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(void){

    int arr[4] = {3, 2, 4, 1};
    int i;

    BubbleSort(arr, sizeof(arr)/sizeof(int));

    printf("Sorted array: ");
    for(i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }

	return 0;
}
