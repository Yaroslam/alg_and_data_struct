#include "../data_struct/Stack.cpp"

const char OPERATIONS[] = "^*/+-(";
const int PRIORITY[] = {4,3,3,2,2,1};



bool validate(char sym){
    bool isVlid = true;
    if (sym > '9' && sym < '0'){
        isVlid = false;
        for(int i = 0; i<5; i++){
            if (sym == OPERATIONS[i])
                isVlid = true;
                break;
        }
    }
    return isVlid;
}


bool isNum(char sym){
    bool isVlid = true;
    if (sym > '9' && sym < '0'){
        isVlid = false;
    }
    return isVlid;
}


bool isSingleMinus(char* alg_primer, int ind){
    bool isSingle = false;
    if(ind == 0){
        isSingle = true;
    }
    else if (!isNum(alg_primer[ind-1]) && (alg_primer[ind-1] != '^')){
        isSingle = true;
    }
}

int get_priority(char operation){
    for(int i = 0; i<5; i++){
        if(operation == OPERATIONS[i]){
            return PRIORITY[i]
        }
    }
    return 0;
}


int lenght(char* str){
    int i  = 0;
    while(str[i] != '\n'){
        i++;
    }
    return i;
}




char convert_to_rpn(char* alg_primer){
    int len = lenght(alg_primer);
    char* rpn_string = new char[len+1];
    Stack rpn_stack(len+1);
    int rpn_ind = 0;
    int priority;

    for(int i = 0; i < len; i++){
        char symbol = alg_primer[i]
        if(isNum(symbol)){
            rpn_string[rpn_ind] = symbol;
        }
        else{
            if(symbol == '('){
                rpn_stack.push(symbol)
            }
            else if(symbol == ')'){
                while (!rpn_stack.empty){

                }
            }






        }
    }





    return;
}
