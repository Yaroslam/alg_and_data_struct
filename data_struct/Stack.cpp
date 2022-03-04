class Stack{
private:
    int len;
    int top = -1;
    char* arr;

public:
    Stack(int lenght){
        len = lenght;
        arr = new char[len];
    }

    void push(char a){
        arr[++top] = a;
    }

    char pop(){
        return arr[top--];
    }

    char get_top(){
        return  arr[top];
    }



};
