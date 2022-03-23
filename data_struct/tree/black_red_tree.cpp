#include<iostream>

using namespace std;

struct node_rb
{
       int key;
       node_rb *parent;
       char color;
       node_rb *left;
       node_rb *right;
};


class RBtree
{
      node_rb *root;
      node_rb *cur;
   public :
      RBtree()
      {
          cur=NULL;
          root=NULL;
      }
    void insert(int key)
    {
        int i=0;
        node_rb* parent, *cur;
        node_rb* new_node =new node_rb;
        new_node->key=key;
        new_node->left=NULL;
        new_node->right=NULL;
        new_node->color='r';
        parent=root;
        cur=NULL;
        if(root==NULL)
        {
            root=new_node;
            new_node->parent=NULL;
        }
        else
        {
            while(parent != NULL)
            {
                cur=parent;
                if(parent->key < new_node->key)
                    parent=parent->right;
                else
                    parent=parent->left;
            }
            new_node->parent=cur;
            if(cur->key < new_node->key)
                cur->right=new_node;
            else
                cur->left=new_node;
        }
        insertfix(new_node);
    }
    void insertfix(node_rb *new_node)
    {
        node_rb* help_node;
        if(root == new_node)
        {
            new_node->color='b';
            return;
        }
        while(new_node->parent != NULL && new_node->parent->color == 'r')
        {
            node_rb* grant_parent = new_node->parent->parent;
            if(grant_parent->left == new_node->parent)
            {
                if(grant_parent->right != NULL)
                {
                    help_node=grant_parent->right;
                    if(help_node->color == 'r')
                    {
                        new_node->parent->color='b';
                        help_node->color='b';
                        grant_parent->color='r';
                        new_node=grant_parent;
                    }
                }
                else
                {
                    if(new_node->parent->right == new_node)
                    {
                        new_node=new_node->parent;
                        leftrotate(new_node);
                    }
                    new_node->parent->color='b';
                    grant_parent->color='r';
                    rightrotate(grant_parent);
                }
            }
            else
            {
                if(grant_parent->left != NULL)
                {
                    help_node=grant_parent->left;
                    if(help_node->color == 'r')
                    {
                        new_node->parent->color='b';
                        help_node->color='b';
                        grant_parent->color='r';
                        new_node=grant_parent;
                    }
                }
                else
                {
                    if(new_node->parent->left == new_node)
                    {
                        new_node=new_node->parent;
                        rightrotate(new_node);
                    }
                    new_node->parent->color='b';
                    grant_parent->color='r';
                    leftrotate(grant_parent);
                }
            }
            root->color='b';
        }
    }

    void del(int key)
    {
        if(root==NULL)
        {
            cout<<"\nEmpty Tree." ;
            return ;
        }
        node_rb *parent;
        parent=root;
        node_rb *suc=NULL;
        node_rb *help_node=NULL;
        int found=0;
        while(parent != NULL && found == 0)
        {
            if(parent->key == key)
                found=1;
            if(found==0)
            {
                if(parent->key < key)
                    parent=parent->right;
                else
                    parent=parent->left;
            }
        }
        if(found==0)
        {
            return ;
        }
        else
        {
            if(parent->color == 'b')
                cout<<"Black\n";
            else
                cout<<"Red\n";

            if(parent->parent != NULL)
                cout << "\nParent: " << parent->parent->key;
            else
                cout<<"\nThere is no parent of the node_rb.  ";
            if(parent->right != NULL)
                cout << "\nRight Child: " << parent->right->key;
            else
                cout<<"\nThere is no right child of the node_rb.  ";
            if(parent->left != NULL)
                cout << "\nLeft Child: " << parent->left->key;
            else
                cout<<"\nThere is no left child of the node_rb.  ";
            cout<<"\nNode Deleted.";
            if(parent->left == NULL || parent->right == NULL)
                suc=parent;
            else
                suc=successor(parent);
            if(suc->left != NULL)
                help_node = suc->left;
            else
            {
                if(suc->right != NULL)
                    help_node=suc->right;
                else
                    help_node=NULL;
            }
            if(help_node != NULL)
                help_node->parent=suc->parent;
            if(suc->parent == NULL)
                root=help_node;
            else
            {
                if(suc == suc->parent->left)
                    suc->parent->left=help_node;
                else
                    suc->parent->right=help_node;
            }
            if(suc != parent)
            {
                parent->color=suc->color;
                parent->key=suc->key;
            }
            if(suc->color == 'b')
                delfix(help_node);
        }
    }

    void delfix(node_rb *to_del)
    {
        node_rb *help_node;
        while(to_del != root && to_del->color == 'b')
        {
            if(to_del->parent->left == to_del)
            {
                help_node=to_del->parent->right;
                if(help_node->color == 'r')
                {
                    help_node->color='b';
                    to_del->parent->color='r';
                    leftrotate(to_del->parent);
                    help_node=to_del->parent->right;
                }
                if(help_node->right->color == 'b' && help_node->left->color == 'b')
                {
                    help_node->color='r';
                    to_del=to_del->parent;
                }
                else
                {
                    if(help_node->right->color == 'b')
                    {
                        help_node->left->color == 'b';
                        help_node->color='r';
                        rightrotate(help_node);
                        help_node=to_del->parent->right;
                    }
                    help_node->color=to_del->parent->color;
                    to_del->parent->color='b';
                    help_node->right->color='b';
                    leftrotate(to_del->parent);
                    to_del=root;
                }
            }
            else
            {
                help_node=to_del->parent->left;
                if(help_node->color == 'r')
                {
                    help_node->color='b';
                    to_del->parent->color='r';
                    rightrotate(to_del->parent);
                    help_node=to_del->parent->left;
                }
                if(help_node->left->color == 'b' && help_node->right->color == 'b')
                {
                    help_node->color='r';
                    to_del=to_del->parent;
                }
                else
                {
                    if(help_node->left->color == 'b')
                    {
                        help_node->right->color='b';
                        help_node->color='r';
                        leftrotate(help_node);
                        help_node=to_del->parent->left;
                    }
                    help_node->color=to_del->parent->color;
                    to_del->parent->color='b';
                    help_node->left->color='b';
                    rightrotate(to_del->parent);
                    to_del=root;
                }
            }
            to_del->color='b';
            root->color='b';
        }
    }

    void leftrotate(node_rb *node)
    {
        if(node->right == NULL)
            return ;
        else
        {
            node_rb *help_node=node->right;
            if(help_node->left != NULL)
            {
                node->right=help_node->left;
                help_node->left->parent=node;
            }
            else
                node->right=NULL;
            if(node->parent != NULL)
                help_node->parent=node->parent;
            if(node->parent == NULL)
                root=help_node;
            else
            {
                if(node == node->parent->left)
                    node->parent->left=help_node;
                else
                    node->parent->right=help_node;
            }
            help_node->left=node;
            node->parent=help_node;
        }
    }
    void rightrotate(node_rb *node)
    {
        if(node->left == NULL)
            return ;
        else
        {
            node_rb *help_node=node->left;
            if(help_node->right != NULL)
            {
                node->left=help_node->right;
                help_node->right->parent=node;
            }
            else
                node->left=NULL;
            if(node->parent != NULL)
                help_node->parent=node->parent;
            if(node->parent == NULL)
                root=help_node;
            else
            {
                if(node == node->parent->left)
                    node->parent->left=help_node;
                else
                    node->parent->right=help_node;
            }
            help_node->right=node;
            node->parent=help_node;
        }
    }

    node_rb* successor(node_rb *p)
    {
        node_rb *help_node=NULL;
        if(p->left!=NULL)
        {
            help_node=p->left;
            while(help_node->right != NULL)
                help_node=help_node->right;
        }
        else
        {
            help_node=p->right;
            while(help_node->left != NULL)
                help_node=help_node->left;
        }
        return help_node;
    }

    node_rb* search(int key)
    {
        if(root==NULL)
        {
            return root;
        }
        node_rb *parent=root;
        int found=0;
        while(parent != NULL && found == 0)
        {
            if(parent->key == key)
                found=1;
            if(found==0)
            {
                if(parent->key < key)
                    parent=parent->right;
                else
                    parent=parent->left;
            }
        }
        if(found==0)
            return root;
        else
        {
            return parent;
        }
    }

};


