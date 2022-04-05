#include <iostream>
using namespace std;

struct Node_two{
    int data;
    Node_two* next;
};

class List_twoside{
private:
    Node_two* head;
    Node_two* tail;
public:
    List_twoside(){
        head = NULL;
        tail = NULL;
    }

    void add_note(int d){
        Node_two* nd = new Node_two;

        nd->data = d;
        nd->next = NULL;
        tail = nd;

        if(head == NULL){
            head = nd;
        }
        else{
            Node_two* current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = nd;
        }
    }

    void print_list(){
        Node_two* current = head;
        cout << current->data << endl;
        while(current->next!=NULL){
            current = current->next;
            cout << current->data << endl;
        }
    }


    void delet(int a){
        Node_two* current = head;
        Node_two* prev = head;
        while(current->data != a){
            if(current->next == NULL){
                break;
            }
            else{
                prev = current;
                current = current->next;
            }
        }

        if(current == head){
            head = head->next;
        }
        if(current == tail){
            prev->next = NULL;
            tail = prev;
        }
        else{
            prev->next = current->next;
        }
    }

    void add_by_ind(int ind, int a){
        Node_two* current = head;
        Node_two* prev = head;
        Node_two* new_nd = new Node_two;

        new_nd->data = a;
        new_nd->next = current->next;

        int i = 0;

        while(i != ind){
            if(current->next == NULL){
                break;
            }
            else{
                prev = current;
                current = current->next;
            }
            i++;
        }
        if(i == 0){
            Node_two* temp = head;
            head = new_nd;
            new_nd->next = temp;
        }
        else if(current == tail){
            current->next = new_nd;
            new_nd->next = NULL;
            tail = new_nd;
        }
        else{
            prev->next = new_nd;
            new_nd->next = current;
        }
    }



    void swap_by_val(int a, int b){
        Node_two* node_a;
        Node_two* node_b;
        int temp;

        Node_two* current = head;

        while(current->data != a && current->data != b)
        {
            current = current->next;
        }

        if(current->data == a){
            node_a = current;
        }
        else{
            node_b = current;
        }

        current = current->next;

        while(current->data != a && current->data != b)
        {
            current = current->next;
        }

        if(current->data == a){
            node_a = current;
        }
        else{
            node_b = current;
        }

        temp = node_a->data;
        node_a->data = node_b->data;
        node_b->data = temp;

    }


    int find_by_val(int a){
        cout << "all";
        Node_two* current = head;
        while(current->data != a && current->next != NULL){
            current = current->next;
        }
        return current->data;
    }

    int find_by_ind(int ind){
        Node_two* current = head;
        int cur_ind = 0;
        while((cur_ind != ind) && (current->next != NULL)){
            current = current->next;
            cur_ind++;
        }
        return current->data;
    }


};

