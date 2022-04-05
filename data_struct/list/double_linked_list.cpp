#include <iostream>
using namespace std;

struct Node_two_linded{
    int data;
    Node_two_linded* next;
    Node_two_linded* prev;
};

class List_double{
private:
    Node_two_linded* head;
    Node_two_linded* tail;
public:
    List_double(){
        head = NULL;
        tail = NULL;
    }

    void add_note(int d){
        Node_two_linded* nd = new Node_two_linded;

        nd->data = d;
        nd->next = NULL;
        nd->prev = NULL;
        tail = nd;

        if(head == NULL){
            head = nd;
        }
        else{
            Node_two_linded* current = head;
            while(current->next != NULL){
                current = current->next;
            }
            nd->prev = current;
            current->next = nd;
        }
    }

    void print_list(){
        Node_two_linded* current = head;
        cout << current->data << endl;
        while(current->next!=NULL){
            current = current->next;
            cout << current->data << endl;
        }
    }

    void print__revrse_list(){
        Node_two_linded* current = tail;
        cout << current->data << endl;
        while(current->prev!=NULL){
            current = current->prev;
            cout << current->data << endl;
        }
    }


    void delet(int a){
        Node_two_linded* current = head;
        Node_two_linded* prev = head;
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
            head->prev = NULL;
        }
        if(current == tail){
            prev->next = NULL;
            tail = prev;
        }
        else{
            prev->next = current->next;
            prev->next->prev = prev;
        }
    }

    void add_by_ind(int ind, int a){
        Node_two_linded* current = head;
        Node_two_linded* prev = head;
        Node_two_linded* new_nd = new Node_two_linded;

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
            Node_two_linded* temp = head;
            head = new_nd;
            new_nd->next = temp;
            new_nd->next->prev = head;
        }
        else if(current == tail){
            current->next = new_nd;
            new_nd->next = NULL;
            new_nd->prev = current;
            tail = new_nd;
        }
        else{
            prev->next = new_nd;
            new_nd->next = current;
            new_nd->prev = prev;
            new_nd->next->prev = new_nd;
        }
    }



    void swap_by_val(int a, int b){
        cout << 1;
        Node_two_linded* node_a;
        Node_two_linded* node_b;
        int temp;

        Node_two_linded* current = head;

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
        Node_two_linded* current = head;
        while(current->data != a && current->next != NULL){
            current = current->next;
        }
        return current->data;
    }

    int find_by_ind(int ind){
        cout << "all double" << endl;
        Node_two_linded* current = head;
        int cur_ind = 0;
        while((cur_ind != ind) && (current->next != NULL)){
            current = current->next;
            cur_ind++;
        }
        return current->data;
    }
};

