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

    nodeName *head =new nodeName();  //取得一個和 nodeName 大小一樣的區塊，然後配給 head 這個指標
    cout<<"請輸入list1數字:\n";
    cin >> inNum1;
    head -> data=inNum1; //把inNum1放進 head所指的data裡
    head->next = NULL;

    nodeName * current = head; 


    //建立新節點
    for (i=1;i<count1;i++){
        cin >> inNum1;
        current -> next = new nodeName(); 
        current = current -> next; 
        current -> data= inNum1;
    //結束新節點
        current->next = NULL;
    }
    //印出
    cout <<"list1的數為:\n";
    current=head;
    while(true){
        cout<< current->data<<" "; //印目前的節點
        current = current->next; //印完後要印下一個節點的內容
        if (current == NULL){ //current為NULL的時候停下來
            break;
        }
    }

    return 0;

}