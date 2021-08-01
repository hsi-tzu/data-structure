#include <iostream> 
#include <string> 
using namespace std; 

struct nodeName  //建立一個包包，裝有1.data，2.指標next
{
    int data;
    nodeName *next; //nodeName 要與struct的名稱相同

};

int main(){
    nodeName *head =new nodeName; //用nodeName建立一個head指標
    //用new要一塊nodeName大小的記憶體空間，把這個位址給指標head
    //new運算子，從可用存放區為 類型名稱 的物件或物件陣列配置記憶體，並傳回適當類型的非零指標給物件。
    //指標變數 = new 指標的變數型別[記憶體大小];
    //分配一塊動態記憶體，大小為 nodeName，ptr 指到此記憶體位址
    nodeName * current = head; //為了建立後續的節點，我們宣告一個臨時的指標 current ，讓它指向新建立的節點、並表明我們現在正在哪，也就是 student *current = head。


    //建立新節點

    current -> next = new nodeName; //採用指標方法存取struct裡的next，相對的存取方式必須使用箭頭
    //指標 -> struct裡的變數 = 變數內容
    current = current -> next; //指標 = 指標指向的next node

    //結束新節點
    current->next = NULL;
}

