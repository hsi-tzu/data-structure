#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
void create_btree(int *btree,int *data,int len)
{
   int level;                       /* 樹的階層           */
   int i,j;
 
   btree[1] = data[1];              /* 建立根節點         */
   for ( i = 2; i <= len; i++ )     /* 用迴路建立其它節點 */
   {
      level = 1;      /* 從階層1開始        */
      while ( btree[level] != 0 )   /* 是否有子樹         */
      {
         if ( data[i] > btree[level] )   /* 是左或右子樹  */
            level = level * 2 + 1;  /* 右子樹             */
         else
            level = level * 2;      /* 左子樹             */
      }
      btree[level] = data[i];       /* 存入節點資料       */
   }
}
 
/* ---------------------------------------- */
/*  主程式: 建立陣列的二元樹.               */
/* ---------------------------------------- */
int main()
{
   int btree[16];                   /* 二元樹陣列         */
   /* 二元樹節點資料 */
   int data[10] = { 0, 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   int i;
 
   for ( i = 1; i < 16; i++ )       /* 清除二元樹陣列     */
      btree[i] = 0;
   create_btree(btree,data,9);      /* 建立二元樹         */
   for ( i = 1; i < 16; i++ )       /* 列出二元樹內容     */
      printf("%2d: [%d] \n",i,btree[i]);

   return 0;
}