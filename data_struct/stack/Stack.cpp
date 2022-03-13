#include <iostream>


class Stack{
public:
    int len;
    int top = -1;
    char* arr;

    explicit Stack(int lenght){
        len = lenght;
        arr = new char[len];
    }

    void push(char a){
        top++;
        arr[top] = a;
    }

    char pop(){
        top--;
        return arr[top];
    }

    char get_top(){
        return  arr[top];
    }

    bool empty(){
        return (top == -1);
    }

    void print_stack(){
        for(int i = 0; i < len; i++){
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }



};
