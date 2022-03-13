#include <iostream>
#include <ctime>
#include "array/main.cpp"
#include "array_sort/sorting.cpp"
#include "array_sort/array_work.cpp"
#include "data_struct/list/singly_linked_list.cpp"



//TODO
// 1) списки двусвязанный, двсторонний
//  2) свап по значению массив
//  3) Возможность создавать списки и массивы с одинаковыми входными данными.
//  4) Должна иметься возможность
//  5) Реализация сортированного списка методом вставки.
//
//
//
//




using namespace std;



void array_work();
void array_sorting();
void list_work();

int main(int argc, char* argv[])
{
    list_work();
}


void list_work(){
    List myList;
    myList.add_note(5) ;
    myList.add_note(11) ;
    myList.add_note(27);
    myList.add_note(35);
    myList.add_note(50)  ;
    myList.print_list();
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
    arr.print_array();


    printf("Enter index and num for paste\n");
    cin >> index >> elem;
    t = clock();
    arr.paste_to(index, elem);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n", (int)t, ((double)t)/CLOCKS_PER_SEC);
    arr.print_array();


    printf("Enter index for delete\n");
    cin >> index;
    t = clock();
    arr.delete_from(index);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n", (int)t, ((double)t)/CLOCKS_PER_SEC);
    arr.print_array();


    printf("Second pls, we are sorting array\n");
    t = clock();
    arr.shake_sort();
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n", (int)t, ((double)t)/CLOCKS_PER_SEC);
    arr.print_array();


    printf("Enter num for paste\n");
    cin >> elem;
    t = clock();
    arr.paste_to_sort(elem);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n", (int)t, ((double)t)/CLOCKS_PER_SEC);
    arr.print_array();


    printf("Enter num for delete\n");
    cin >> elem;
    t = clock();
    arr.delete_from_sort(elem);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n", (int)t, ((double)t)/CLOCKS_PER_SEC);
    arr.print_array();

}


void array_sorting(){
    int len;
    int* new_arr;
    int sort;
    int work_loop = 1;
    clock_t t;
    cin >> len;
    int* arr = create_and_fill_arr(len);

    while (work_loop){
        printf("Enter -1 to exit\n");
        printf("Enter 1 to insertion sort\n");
        printf("Enter 2 choose sort\n");
        printf("Enter 3 quick sort\n");
        printf("Enter 4 merge sort\n");
        cin >> sort;
        switch (sort) {
            case -1:
                work_loop = 0;
                break;
            case 1: {
                new_arr = copy_arr(arr, len);
                t = clock();
                insertion_sort(new_arr, len);
                t = clock() - t;
                printf("It took me %d clicks (%f seconds).\n", (int) t, ((double) t) / CLOCKS_PER_SEC);
                print_arr(new_arr, len);
                break;
            }
            case 2: {
                new_arr = copy_arr(arr, len);
                t = clock();
                choose_sort(new_arr, len);
                t = clock() - t;
                printf("It took me %d clicks (%f seconds).\n", (int) t, ((double) t) / CLOCKS_PER_SEC);
                print_arr(new_arr, len);
                break;
            }

            case 3: {
                new_arr = copy_arr(arr, len);
                t = clock();
                quick_sort(new_arr, 0, len);
                t = clock() - t;
                printf("It took me %d clicks (%f seconds).\n", (int) t, ((double) t) / CLOCKS_PER_SEC);
                print_arr(new_arr, len);
                break;
            }

            case 4: {
                new_arr = copy_arr(arr, len);
                t = clock();
                merge_sort(new_arr, 0, len-1);
                t = clock() - t;
                printf("It took me %d clicks (%f seconds).\n", (int) t, ((double) t) / CLOCKS_PER_SEC);
                print_arr(new_arr, len);
                break;
            }

        }
    }


}


