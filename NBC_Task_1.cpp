#include <iostream>

using namespace std;

int N;
int *arr;

void Input(){
    cin >> N;
    arr = new int[N];

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

void sumAvg(int N, int *arr){
    float sum = 0;

    for(int i = 0; i < N; i++){
        sum += arr[i];
    }

    cout << "합 : " << sum << ", 평균 : " << sum / N << endl;
}

void Swap(int i, int j, int key){
    int temp;

    if(i > j){ // 현재 엇갈린 상태라면 키 값과 교체
        temp = arr[j];
        arr[j] = arr[key];
        arr[key] = temp;
    }
    else{ // 엇갈리지 않았다면 i와 j를 교체체
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quickSort(int *arr, int start, int end, bool greater){
    if(start >= end)
        return;

    int key = start;
    int i = start + 1, j = end, temp;

    if(greater){ // 내림차순순
        while(i <= j){
            while(i <= end && arr[i] >= arr[key]){ // 키 값보다 작은은 값을 만날 때 까지지
                i++;
            }
            while(j > start && arr[j] <= arr[key]){ // 키 값보다 큰 값을 만날 때 까지지
                j--;
            }
            Swap(i, j, key);
        }
    }
    else{ // 오름차순순
        while(i <= j){
            while(i <= end && arr[i] <= arr[key]){ // 키 값보다 큰 값을 만날 때까지
                i++;
            }
            while(j > start && arr[j] >= arr[key]){ // 키 값보다 작은 값을 만날 때까지지
                j--;
            }
            Swap(i, j, key);
        }
    }

    quickSort(arr, start, j - 1, greater);
    quickSort(arr, j + 1, end, greater);
}

void show(){
    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    
    Input();
    sumAvg(N, arr);
    quickSort(arr, 0, N - 1, true);
    show();
    quickSort(arr, 0, N - 1, false);
    show();

    delete[] arr;
    arr = nullptr;

    return 0;
}
