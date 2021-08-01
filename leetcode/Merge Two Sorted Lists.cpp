#include <iostream> 
#include <string> 
using namespace std;

struct nodeName  //建立一個包包，裝有1.data，2.指標next
{
    int data;
    nodeName *next; //nodeName 要與struct的名稱相同

};

int main(){
    int count1,count2;
    int inNum1,inNum2,i;
    cout<<"請輸入list1的node個數:";
    cin >> count1; //指定有幾個節點

    nodeName *head1 =new nodeName();  //取得一個和 nodeName 大小一樣的區塊，然後配給 head 這個指標
    cout<<"請輸入list1數字:\n";
    cin >> inNum1;
    head1 -> data=inNum1; //把inNum1放進 head所指的data裡
    head1->next = NULL;

    nodeName * current1 = head1; 
    //建立新節點
    for (i=1;i<count1;i++){
        cin >> inNum1;
        current1 -> next = new nodeName(); 
        current1 = current1 -> next; 
        current1 -> data= inNum1;
    //結束新節點
        current1->next = NULL;
    }
    //印出
    cout <<"list1的數為:\n";
    current1=head1;
    while(true){
        cout<< current1->data<<" "; //印目前的節點
        current1 = current1->next; //印完後要印下一個節點的內容
        if (current1 == NULL){ //current為NULL的時候停下來
            break;
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n請輸入list2的node個數:";
    cin >> count2; //指定有幾個節點

    nodeName *head2 =new nodeName();  //取得一個和 nodeName 大小一樣的區塊，然後配給 head 這個指標
    cout<<"\n"<<"請輸入list2數字:\n";
    cin >> inNum2;
    head2 -> data=inNum2; //把inNum1放進 head所指的data裡
    head2->next = NULL;

    nodeName * current2 = head2; 
    //建立新節點
    for (i=1;i<count2;i++){
        cin >> inNum2;
        current2 -> next = new nodeName(); 
        current2 = current2 -> next; 
        current2 -> data= inNum2;
    //結束新節點
        current2->next = NULL;
    }
    //印出
    cout <<"\n"<<"list2的數為:\n";
    current2=head2;
    while(true){
        cout<< current2->data<<" "; //印目前的節點
        current2 = current2->next; //印完後要印下一個節點的內容
        if (current2 == NULL){ //current為NULL的時候停下來
            break;
        }
    }
    
    //開始排序
    current1=head1;
    current2=head2;
    nodeName *temp = new nodeName();
    nodeName *tempHead = temp;
    while(true){
        if (current2->data > current1->data){
            temp -> next =current1;
            temp=temp->next;
            current1 = current1->next;
            if (current1 == NULL){
                temp -> next =current2;
                temp=temp->next;
                break;
            }
            
        }
        else if(current2->data < current1->data)
        {
            temp -> next =current2;
            temp=temp->next;
            current2 = current2->next;
            if (current2 == NULL){
                temp -> next =current1;
                temp=temp->next;
                break;
            }
        }
       else{
           temp -> next =current2;
            temp=temp->next;
            current2 = current2->next;
            if (current2 == NULL){
                temp -> next =current1;
                temp=temp->next;
                break;
            }
       }
    }
    cout<<"\n合併後為:";
    while(true){
        if (tempHead->next == NULL){ //current為NULL的時候停下來
            break;
        }
        cout<<tempHead->next->data<<" "; //印目前的節點
        tempHead = tempHead->next; //印完後要印下一個節點的內容
       
    }


    return 0;

}