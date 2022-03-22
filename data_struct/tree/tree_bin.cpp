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
        Node_bin* root = NULL;


        static Node_bin* find_successor(Node_bin* node){
            Node_bin* successor = node->right;
            while(true){
                if(successor == NULL){
                    break;
                }
                else if(successor->left == NULL){
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
                    root->parent = NULL;
                }
                else if(node->parent->left == node){
                    node->parent->left = node->left;
                    node->left->parent = node->parent;
                }
                else{
                    node->parent->right = node->left;
                    node->left->parent = node->parent;
                }
            }
            else{
                if(node == root){
                    root = node->right;
                    root->parent = NULL;
                }
                else if(node->parent->left == node){
                    node->parent->left = node->right;
                    node->right->parent = node->parent;
                }
                else{
                    node->parent->right = node->right;
                    node->right->parent = node->parent;
                }
            }
        }


        static void  delete_with_two_childs(Node_bin* node){
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
                Node_bin* suc_right = successor->right;
                successor->left = node->left;
                successor->right = node->right;
                successor-> parent = node->parent;
                successor->right->left = suc_right;

                successor->right->parent = successor;
                successor->left->parent = successor;
                successor->right->left->parent = successor->right;


                if(node->parent->left == node){
                    node->parent->left = successor;
                    node->parent = NULL;
                }
                else{
                    node->parent->right = successor;
                    node->parent = NULL;
                }
            }
        }


    public:
        void insert(int val){
            Node_bin *new_nd = new Node_bin;
            new_nd->data = val;
            new_nd->parent = NULL;
            new_nd->left = NULL;
            new_nd->right = NULL;

            if(root == NULL){
                root = new_nd;
            }
            else{
                Node_bin* cur = root;
                Node_bin* parent = root;

                while (true){
                    parent = cur;
                    if(val < cur->data){
                        cur = cur->left;
                        if(cur == NULL){
                            parent->left = new_nd;
                            new_nd->parent = parent;
                            return;
                        }
                    }
                    else{
                        cur = cur->right;
                        if(cur == NULL){
                            parent->right = new_nd;
                            new_nd->parent = parent;
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

        static int count_child(Node_bin* node){
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
                    break;
                case 1:
                    delete_with_one_child(node_to_del);
                    break;
                case 2:
                    delete_with_two_childs(node_to_del);
                    break;
            }
        }
};
