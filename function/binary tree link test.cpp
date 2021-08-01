#include <iostream>
using namespace std;

class binary_tree
{   private:
    struct node
    {
        int data;
        node *left;
        node *right;
    };
    node *root;
    node *current; /* 目前樹節點指標     */
    node *back;    /* 父節點指標         */
    
    public:
    binary_tree();
    void insert(int);
    void inorder();
};
 binary_tree::binary_tree()
 {
     root=current=back=NULL;
 }

 void binary_tree::insert(int n)
 {
     node *temp=new node;
     temp->data=n;
     temp->left=NULL;
     temp->right=NULL;
     if (root==NULL)
     {
         root=current=back=temp;
         return;
     }
     else
     {
         current = root;             /* 保留目前樹指標     */
         while ( current != NULL )
        {
            back = current;          /* 保留父節點指標     */
            if ( current->data > n )    /* 比較節點值  */
                current = current->left;     /* 左子樹      */
            else
                current = current->right;    /* 右子樹      */
        }
        if ( back->data > n )   /* 接起父子的鏈結     */
        {
            back->left = temp; 
        }   /* 左子樹             */
        else
        {
            back->right = temp;   /* 右子樹             */
        }
     }
 }

 int main()
 {
     binary_tree test;
     test.insert(5);

 }