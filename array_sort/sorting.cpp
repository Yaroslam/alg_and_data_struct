#include <iostream>
#include <ctime>
using namespace std;


inline void insertion_sort(int* arr, int len){
    int temp, prev_elem;
    for(int i = 1; i<len; i++){
        temp = arr[i];
        prev_elem = i-1;
        while(prev_elem >= 0 && arr[prev_elem] > temp){
            arr[prev_elem+1] = arr[prev_elem];
            arr[prev_elem] = temp;
            prev_elem--;
        }
    }
}

inline void choose_sort(int* arr, int len){
    for (int i = 0; i < len; i++)
    {
        int min_position = i;
        for (int j = i + 1; j < len; j++)
            if (arr[min_position] > arr[j])
                min_position = j;
        int temp = arr[min_position];
        arr[min_position] = arr[i];
        arr[i] = temp;
    }
}

inline void quick_sort(int* arr, int i, int j){
    int first = i;
    int last = j;
    int mid = arr[(i+j)/2];

    while(first<=last){
        while (arr[first] < mid) first++;
        while (arr[last] > mid) last--;

        if(first <= last){
            if (arr[first] > arr[last]){
                swap(arr[first], arr[last]);
            }
            first++;
            last--;
        }

        if(first < j){
            quick_sort(arr, first, j);
        }
        if(last > i){
            quick_sort(arr, i, last);
        }
    }
}


inline void merge(int* arr, int low, int high, int mid)
{
    int i, j, k, tmp_arr[255];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            tmp_arr[k] = arr[i];
            k++;
            i++;
        }
        else  {
            tmp_arr[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        tmp_arr[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        tmp_arr[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = tmp_arr[i];
    }
}


inline void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}