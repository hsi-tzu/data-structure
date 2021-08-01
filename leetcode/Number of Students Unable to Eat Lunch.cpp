#include <iostream>
using namespace std;
struct QNode { //建立節點
    QNode(int d)  //應該是初始化
    {
        data = d;
        next = NULL;
    }
    int data;
    QNode* next;
};

struct Queue {
    QNode *front, *rear, *tempUse; //建立指標front前.rear後
    Queue() //初始化
    {
        front = rear = NULL;
    }
    //加入
    void enQueue(int x) // int x 是要輸入的數字
    {
  
        // Create a new LL node
        QNode *temp1 = new QNode(x);//新增動態空間，配置完成後指定儲存值
  
        // If queue is empty, then
        // new node is front and rear both
        if (rear == NULL) {
            front = rear = temp1;
            return;
        }
        rear->next = temp1; //將rear指向的struct裡的next指向temp
        rear = temp1;
    }
    void deQueue()
    {
        // If queue is empty, return NULL.
        if (front == NULL)
            return;
        // Store previous front and
        // move front one node ahead
        QNode* temp2 = front;
        front = front->next;
        if (front == NULL){
            rear = NULL;
        }
        delete (temp2); //須是先前配置給以 new 運算子建立之物件的記憶體區塊指標
    }
    void goBack()
    {
        rear->next=front;
        front=front->next;
        rear=rear->next;
        rear->next=NULL;
    }
    int size()
    {
        QNode* temp3 = front;
        int sizeNum=0;
        while(temp3!=NULL){
            if(temp3==NULL){
                break;
            }
            temp3=temp3->next;
            sizeNum=sizeNum+1;
        }
        return sizeNum;
    }
};

int main()
{
    int input,i,number,count;
    Queue student;
    Queue lunch;
    cout<<"輸入學生、餐點數量:";
    cin>> number;
    cout<<"\n輸入學生餐點:"<<endl;
    for (i=0;i<number;i++){
        cin>>input;
        student.enQueue(input);
    }
    cout<<"\n輸入餐點排序:"<<endl;
    for (i=0;i<number;i++){
        cin>>input;
        lunch.enQueue(input);
    }
    lunch.tempUse=lunch.front;
    student.tempUse=student.front;
    count=0;
    while(true){
        if((student.tempUse)->data ==(lunch.tempUse)->data)
        {
            student.tempUse=student.tempUse->next;
            lunch.tempUse=lunch.tempUse->next;
            student.deQueue();
            lunch.deQueue();
            count=0;
            //cout<<"time1  "<<count<<endl;
            if(student.tempUse == NULL){
                cout<<"剩"<<student.size()<<"人"<<endl;
                break;
            }
        }
        if((student.tempUse)->data != (lunch.tempUse)->data)
        {
            student.tempUse=student.tempUse->next;
            student.goBack();
    
            count=count+1;
            //cout<<"time2  "<<count<<endl;
            if (count == student.size()){
                cout<<"剩"<<student.size()<<"人"<<endl;
                break;
            }
        }
    }
    return 0;
}