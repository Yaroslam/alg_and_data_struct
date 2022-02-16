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
    clock_t t;
    double seconds;


    printf("Enter array size\n");
    cin >> size;
    t = clock();
    arr.create_and_fill_arr(size);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n", (int)t, ((double)t)/CLOCKS_PER_SEC);
    arr.print_arr();


    printf("Enter index and num for paste\n");
    cin >> index >> elem;
    t = clock();
    arr.paste_to(index, elem);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n", (int)t, ((double)t)/CLOCKS_PER_SEC);
    arr.print_arr();


    printf("Enter index for delete\n");
    cin >> index;
    t = clock();
    arr.delete_from(index);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n", (int)t, ((double)t)/CLOCKS_PER_SEC);
    arr.print_arr();


    printf("Second pls, we are sorting array\n");
    t = clock();
    arr.shake_sort();
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n", (int)t, ((double)t)/CLOCKS_PER_SEC);
    arr.print_arr();


    printf("Enter num for paste\n");
    cin >> elem;
    t = clock();
    arr.paste_to_sort(elem);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n", (int)t, ((double)t)/CLOCKS_PER_SEC);
    arr.print_arr();


    printf("Enter num for delete\n");
    cin >> elem;
    t = clock();
    arr.delete_from_sort(elem);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n", (int)t, ((double)t)/CLOCKS_PER_SEC);
    arr.print_arr();

}


