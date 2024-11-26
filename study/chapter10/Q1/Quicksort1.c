#include <stdio.h>

// GetPivot 함수는 피벗을 선택하기 위해 배열의 요소를 교환합니다.
void GetPivot(int arr[], int mid, int left){
    int temp;
    temp = arr[mid];
    arr[mid] = arr[left];
    arr[left] = temp;
}

// Swap 함수는 두 인덱스의 배열 요소를 교환합니다.
void Swap(int arr[], int idx1, int idx2){
    int temp;
    temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

// Partition 함수는 배열을 피벗을 기준으로 분할합니다.
int Partition(int arr[], int left, int mid, int right){
    // 피벗 선택 로직
    if(arr[left] == arr[mid] && arr[left] == arr[right]){
        GetPivot(arr, mid, left);
    }
    // 왼쪽 요소가 중간값인 경우
    else if((arr[left] >= arr[mid] && arr[left] <= arr[right]) || 
            (arr[left] >= arr[right] && arr[left] <= arr[mid])){
        // 변경 없음 - 이미 왼쪽 값이 중간값
    }
    // 중간 요소가 중간값인 경우
    else if((arr[mid] >= arr[left] && arr[mid] <= arr[right]) || 
            (arr[mid] >= arr[right] && arr[mid] <= arr[left])){
        GetPivot(arr, mid, left);  // 중간 값을 왼쪽으로 이동
    }
    // 오른쪽 요소가 중간값인 경우
    else {
        GetPivot(arr, right, left);  // 오른쪽 값을 왼쪽으로 이동
    }
    
    int pivot = arr[left];
    int low = left + 1; // 왼쪽 포인터
    int high = right; // 오른쪽 포인터

    printf("pivot: %d\n", pivot);

    // 배열을 피벗을 기준으로 분할
    while(low <= high){
        while(low <= high && pivot > arr[low]){
            low++;
        }
        while(low <= high && pivot < arr[high]){
            high--;
        }
        if(low <= high) {
            Swap(arr, low, high); // low와 high의 요소 교환
        }
    }
    Swap(arr, left, high); // 피벗을 올바른 위치로 이동
    return high; // 피벗의 최종 위치 반환
}

// QuickSort 함수는 배열을 재귀적으로 정렬합니다.
void QuickSort(int arr[], int left, int right){
    if(left < right) {
        int pivot = Partition(arr, left, right/2, right); // 배열을 분할하고 피벗 위치 반환
        QuickSort(arr, left, pivot - 1); // 피벗 왼쪽 부분 정렬
        QuickSort(arr, pivot + 1, right); // 피벗 오른쪽 부분 정렬
    }
}

// main 함수는 프로그램의 시작점입니다.
int main(void){
    int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // 정렬할 배열

    QuickSort(arr, 0, sizeof(arr)/sizeof(int) - 1); // QuickSort 호출

    // 정렬된 배열 출력
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    return 0; // 프로그램 종료
}