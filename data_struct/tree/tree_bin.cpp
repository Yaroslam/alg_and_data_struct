#include <iostream>
using namespace std;

struct Node_bin{
    int data;
    Node_bin* left;
    Node_bin* right;
    Node_bin* parent;
};

class Tree_bin{
    private:
        Node_bin* root;


        Node_bin* find_successor(Node_bin* node){
            Node_bin* successor = node->right;
            while(true){
                if(successor->left == NULL){
                    break;
                }
                else{
                    successor = successor->left;
                }
            }
            return successor;
        }


        void delete_with_no_child(Node_bin* node){
            if(node == root){
                root = NULL;
            }

            if(node == node->parent->right){
                node->parent->right = NULL;
            }
            else{
                node->parent->left = NULL;
            }
        }


        void delete_with_one_child(Node_bin* node){
            if(node->right == NULL){
                if(node == root){
                    root = node->left;
                }
                else if(node->parent->left == node){
                    node->parent->left = node->left;
                }
                else{
                    node->parent->right = node->left;
                }
            }
            else{
                if(node == root){
                    root = node->right;
                }
                else if(node->parent->left == node){
                    node->parent->left = node->right;
                }
                else{
                    node->parent->right = node->right;
                }
            }
        }


        void  delete_with_two_childs(Node_bin* node){
            Node_bin* successor = find_successor(node);

            if(successor == node->right){
                Node_bin* left_suc_child = node->left;
                node->left->parent = successor;
                successor->left = left_suc_child;
                node->left = NULL;

                if(node->parent->left == node){
                    node->parent->left = successor;
                    node->parent = NULL;
                }
                else{
                    node->parent->right = successor;
                    node->parent = NULL;
                }
            }
            else{
                successor->parent->left = successor->right;
                successor->right = node->right;
                node->parent->right = find_successor(successor);




            }


        }


    public:
        void insert(int val){
            Node_bin *new_nd = nullptr;
            new_nd->data = val;
            new_nd->parent = NULL;
            new_nd->left = NULL;
            new_nd->right = NULL;

            if(root == NULL){
                root = new_nd;
            }
            else{
                Node_bin* cur = root;
                Node_bin* parent = nullptr;

                while (true){
                    parent = cur;
                    if(val < cur->data){
                        cur = cur->left;
                        if(cur == NULL){
                            parent->left = new_nd;
                            return;
                        }
                    }
                    else{
                        cur = cur->right;
                        if(cur == NULL){
                            parent->right = new_nd;
                            return;
                        }
                    }
                }
            }
        }

        Node_bin* find(int key){
            Node_bin* cur = root;

            while(key != cur->data){
                if(key > cur->data){
                    cur = cur->right;
                }
                else{
                    cur = cur->left;
                }

                if(cur == NULL){
                    break;
                }

            }
            return cur;
        }

        int count_child(Node_bin* node){
            int child = 0;
            if(node->left != NULL){
                child++;
            }

            if(node->right != NULL){
                child++;
            }
            return child;
        }



        void del(int key){
            Node_bin* node_to_del = find(key);
            int childs = count_child(node_to_del);
            switch (childs) {
                case 0:
                    delete_with_no_child(node_to_del);
                case 1:
                    delete_with_one_child(node_to_del);
                case 2:
                    delete_with_two_childs(node_to_del);
            }
        }

};
