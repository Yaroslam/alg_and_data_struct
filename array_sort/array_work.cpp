#include <iostream>
#include <ctime>
using namespace std;

inline int* create_and_fill_arr(int len){
    srand(time(0));
    int* arr = new int[len];
    for (int count = 0; count < len; count++)
        arr[count] = (rand() + 1) / float((rand() % 10 + 1));

    return arr;
}

inline int* copy_arr(int* old_arr, int len){
    int* new_arr = new int[len];
    for(int i = 0; i<len; i++){
        new_arr[i] = old_arr[i];
    }

    return new_arr;
}


inline void print_arr(int* arr, int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << endl;
    }
    cout << endl;
}