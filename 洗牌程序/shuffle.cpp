#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct card
{
	int suit ; //��ɫ
	char Number; //����
}Card;

Card OneCard[52];  //����ÿ���˿˵Ļ�ɫ������

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
		switch(OneCard[i].suit)  //��ʾ��ɫ
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
		printf("  %c%c",sign,OneCard[i].Number);  //�����ʾ
	}
	printf("\n");
}

void shuffle()  //�㷨
{
  int i,j,temp;
  int suit;
  Card tempcard;

  suit = 0;
  for(i=0;i<52;i++)  //����52����
  {
	if(i%13==0)  
	{
		suit++;     //�ı仨ɫ
	}            
	OneCard[i].suit = suit;  //���滨ɫ
	temp = i%13;
	switch(temp)   //���⴦��
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


  printf("һ�����Ƶ�����������£�\n");

  ShowCard();
  srand(time(NULL));  //�������
  for (i=0;i<52;i++)
  {                   //�������
	  j=rand()%52;
	  tempcard = OneCard[j];
	  OneCard[j]= OneCard[i];
	  OneCard[i] = tempcard;

  }
 }


void main()   //������
{
	shuffle();	  //ϴ��
	printf("\n ϴ�ƺ������˳�����£�\n");
	ShowCard();
}