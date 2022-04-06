#include <iostream>
#include <ctime>
#include "array/main.cpp"
#include "array_sort/sorting.cpp"
#include "array_sort/array_work.cpp"
#include "data_struct/list/singly_linked_list.cpp"
#include "data_struct/list/twoside_linked_list.cpp"
#include "data_struct/list/double_linked_list.cpp"
#include "data_struct/tree/tree_bin.cpp"
#include "data_struct/tree/black_red_tree.cpp"
#include "data_struct/heap/heap.cpp"





using namespace std;


void array_work();
void array_sorting();
void list_work();
void heap_work();
void tree_work();
void BRtree_work();
void create_and_fill(int size);






int main(int argc, char* argv[])
{
    heap_work();
}




void BRtree_work(){
    RBtree tree;

    tree.insert(50);
    tree.insert(25);
    tree.insert(75);
    tree.insert(12);
    tree.insert(37);
    tree.insert(62);
    tree.insert(87);
    tree.insert(6);
    tree.insert(18);
    tree.insert(31);
    tree.insert(43);
    tree.insert(62);
    tree.insert(87);



}



void tree_work(){
    Tree_bin tree;

    tree.insert(80);
    tree.insert(52);
    tree.insert(48);
    tree.insert(71);
    tree.insert(63);
    tree.insert(67);
    tree.del(71);


}


void list_work(){
    List_double list1;
    List_twoside List2;
    int a;
    srand(time(0));
    for (int count = 0; count < 5; count++) {
        cin >> a;
        list1.add_note(a);
        List2.add_note(a);
    }
    list1.print_list();
    list1.delet(3);
    list1.print_list();
}


void array_work(){
    int size;
    int index;
    int elem;
    clock_t t;
    double seconds;


    printf("Enter array size\n");
    cin >> size;
    My_own_arr arr(size);
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

void heap_work(){
    int i;
    cin >> i;
    int* arr = new int[i];
    Heap Heap(i);

    srand(time(0));
    for (int count = 0; count < i; count++) {
        arr[count] = (rand() + 1) / float((rand() % 10 + 1));
        Heap.adelem((rand() + 1) / float((rand() % 10 + 1)));
    }

    Heap.out();

    Heap.getmax();
    Heap.out();



};
