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
/* 其他寫法*/
/*struct QNode { //建立節點
    QNode(int);
    int data;
    QNode* next;
};
QNode::QNode(int d)  //應該是初始化

    {
        data = d;
        next = NULL;
    }*/
struct Queue {
    QNode *front, *rear; //建立指標front前.rear後
    Queue() //初始化
    {
        front = rear = NULL;
    }
    //加入
    void enQueue(int x) // int x 是要輸入的數字
    {
  
        // Create a new LL node
        QNode* temp = new QNode(x);//新增動態空間，配置完成後指定儲存值
  
        // If queue is empty, then
        // new node is front and rear both
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
  
        // Add the new node at
        // the end of queue and change rear
        // 如果已經有節點的狀況
        rear->next = temp; //將rear指向的struct裡的next指向temp
        rear = temp;
    }
  
    // Function to remove
    // a key from given queue q
    void deQueue()
    {
        // If queue is empty, return NULL.
        if (front == NULL)
            return;
        // Store previous front and
        // move front one node ahead
        QNode* temp = front;
        front = front->next;
  
        // If front becomes NULL, then
        // change rear also as NULL
        if (front == NULL)
            rear = NULL;
  
        delete (temp); //須是先前配置給以 new 運算子建立之物件的記憶體區塊指標
    }
};
/*其他寫法*/
/*struct Queue {
    QNode *front, *rear; //建立指標front前.rear後
    Queue(); //初始化
    void enQueue(int);
    void deQueue();
};
 Queue::Queue(){
        front = rear = NULL;
 }
 void Queue::enQueue(int x){
        QNode* temp = new QNode(x);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
 }

 void Queue::deQueue(){
        if (front == NULL)
            return;
        QNode* temp = front;
        front = front->next;
  
        // If front becomes NULL, then
        // change rear also as NULL
        if (front == NULL)
            rear = NULL;
  
        delete (temp);
 }
  */

  
// Driven Program
int main()
{
  
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.deQueue();
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data;
}