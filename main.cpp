#include <iostream>
#include <ctime>
#include "array/main.cpp"
using namespace std;



void array_work();

int main(int argc, char* argv[])
{
    array_work();
    return 0;
}


void array_work(){
    My_own_arr arr;
    int size;
    int index;
    int elem;
    clock_t start, end;
    double seconds;


    start = clock();
    cin >> size;
    arr.create_and_fill_arr(size);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    arr.print_arr();


    start = clock();
    cin >> index >> elem;
    arr.paste_to(index, elem);
    arr.print_arr();


    start = clock();
    cin >> index;
    arr.delete_from(index);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    arr.print_arr();


    start = clock();
    arr.shake_sort();
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    arr.print_arr();


    start = clock();
    cin >> elem;
    arr.paste_to_sort(elem);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    arr.print_arr();


    start = clock();
    cin >> elem;
    arr.delete_from_sort(elem);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    arr.print_arr();

}


