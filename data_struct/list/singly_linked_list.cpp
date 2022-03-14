#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class List{
private:
    Node* head;

    void insert(int a){
        Node* nd = new Node;
        nd->data = a;
        nd->next = NULL;

        Node* prev = head;
        Node* current = head;

        while(current != NULL && a < current->data){
            prev = current;
            current = current->next;
        }

        if(prev == head){
            head = nd;
        }
        else{
            prev->next = nd;
        }
        nd->next = current;
    }


public:
    List(){
        head = NULL;
    }

    void create_sort_list(int size, int* arr){
       for(int i = 0; i<size; i++){
           insert(arr[i]);
       }
    }



    void add_note(int d){
        Node* nd = new Node;

        nd->data = d;
        nd->next = NULL;

        if(head == NULL){
            head = nd;
        }
        else{
            Node* current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = nd;
        }
    }

    void print_list(){
        Node* current = head;
        cout << current->data << endl;
        while(current->next!=NULL){
            current = current->next;
            cout << current->data << endl;
        }
    }


    void delet(int a){
        Node* current = head;
        Node* prev = head;
        while(current->data != a){
            if(current->next == NULL){
                return;
            }
            else{
            prev = current;
            current = current->next;
            }
        }

        if(current == head){
            head = head->next;
        }
        else{
            prev->next = current->next;
        }
    }

    void add_by_ind(int ind, int a){
        Node* current = head;
        Node* prev = head;
        Node* new_nd = new Node;

        new_nd->data = a;
        new_nd->next = current->next;

        int i = 0;

        while(i != ind){
            if(current->next == NULL){
                return;
            }
            else{
                prev = current;
                current = current->next;
            }
            i++;
        }
        if(i == 0){
            Node* temp = head;
            head = new_nd;
            new_nd->next = temp;
        }
        else{
            prev->next = new_nd;
            new_nd->next = current;
        }
    }



    void swap_by_val(int a, int b){
        Node* node_a;
        Node* node_b;
        int temp;

        Node* current = head;

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
        Node* current = head;
        while(current->data != a && current->next != NULL){
            current = current->next;
        }
        return current->data;
    }

    int find_by_ind(int ind){
        Node* current = head;
        int cur_ind = 0;
        while((cur_ind != ind) && (current->next != NULL)){
            current = current->next;
            cur_ind++;
        }
        return current->data;
    }


};