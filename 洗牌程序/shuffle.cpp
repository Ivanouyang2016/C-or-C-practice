#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct card
{
	int suit ; //花色
	char Number; //排数
}Card;

Card OneCard[52];  //保存每张扑克的花色、数字

void ShowCard()
{
	int i=0,j=0;
	int sign=0;

	for(i=0,i=0;i<52;i++,j++)
	{
		if(!(j%13))
		{
			printf("\n");
		}
		switch(OneCard[i].suit)  //显示花色
		{
		case 0: 
				sign = 3; break;
		case 1:
				sign = 4; break;
		case 2:
				sign = 5; break;
		case 3:
				sign = 6; break;
		default :
			;
		}
		printf("  %c%c",sign,OneCard[i].Number);  //输出显示
	}
	printf("\n");
}

void shuffle()  //算法
{
  int i,j,temp;
  int suit;
  Card tempcard;

  suit = 0;
  for(i=0;i<52;i++)  //生成52张牌
  {
	if(i%13==0)  
	{
		suit++;     //改变花色
	}            
	OneCard[i].suit = suit;  //保存花色
	temp = i%13;
	switch(temp)   //特殊处理
	{
		case 0:
			OneCard[i].Number = 'A'; break;
		case 9:
			OneCard[i].Number = '0'; break;
		case 10:
			OneCard[i].Number = 'J';break;
		case 11:
			OneCard[i].Number = 'Q'; break;
		case 12:
			OneCard[i].Number = 'K';break;
		default:
			OneCard[i].Number = temp+'1';
	}
}


  printf("一副新牌的输出排序如下：\n");

  ShowCard();
  srand(time(NULL));  //随机种子
  for (i=0;i<52;i++)
  {                   //随机换牌
	  j=rand()%52;
	  tempcard = OneCard[j];
	  OneCard[j]= OneCard[i];
	  OneCard[i] = tempcard;

  }
 }


void main()   //主函数
{
	shuffle();	  //洗牌
	printf("\n 洗牌后的排列顺序如下：\n");
	ShowCard();
}