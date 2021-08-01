#include <cstdlib>
#include <iostream>



using namespace std;
class Stack{
    private:

    struct SNode{
        string name;
        int data;
        SNode *prev;
    };
    SNode* stackPtr;

    public:
     void Push(string,int);
     void Pop();
     void Read(SNode *r);
     void Print();

     Stack();
     ~Stack();
};
Stack::Stack(){
    stackPtr == NULL;
}
Stack::~Stack(){
     SNode *p1;
     SNode *p2;
     p1=stackPtr;
     while(p1!=NULL){
         p2=p1;
         p1=p1->prev;
         p2->prev=NULL;
         delete p2;
     }
 }

void Stack::Push(string name,int data){
     SNode *n= new SNode;
     n->name=name;
     n->data=data;
     if (stackPtr!=NULL){
        stackPtr=n;
        stackPtr->prev=NULL;
     }
     else{
        n->prev=stackPtr;
        stackPtr =n;
     }
 }

void Stack::Read(SNode *r){
     cout<<"---------------"<<endl;
     cout<<"name: "<<r->name<<endl;
     cout<<"value: "<<r->data<<endl;
     cout<<"---------------"<<endl;
 }
void Stack::Pop(){
     if (stackPtr==NULL){
         cout<<"Nothing on the stack"<<endl;
     }
     else{
         SNode *p=stackPtr;
         Read(p);
         stackPtr=stackPtr->prev;
         p->prev=NULL;
         delete p;
     }
 }
void Stack::Print(){
     SNode *p= stackPtr;
     while(p != NULL){
         Read(p);
         p =p->prev;
     }
 }
int main(){
    Stack test;
    test.Push("kiki",3);
    test.Print();
    return 0;
}