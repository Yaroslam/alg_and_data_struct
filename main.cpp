#include <iostream>
#include <ctime>
#include "array/main.cpp"
#include <iomanip>
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

    cin >> size;
    arr.create_and_fill_arr(size);
    arr.print_arr();

    cin >> index >> elem;
    arr.paste_to(index, elem);
    arr.print_arr();

    cin >> index;
    arr.delete_from(index);
    arr.print_arr();

    arr.shake_sort();
    arr.print_arr();

    cin >> elem;
    arr.paste_to_sort(elem);
    arr.print_arr();

    cin >> elem;
    arr.delete_from_sort(elem);
    arr.print_arr();
}


