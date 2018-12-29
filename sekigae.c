#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
		int seki[7][6]={
		{ 42, 0, 0, 0, 0,42}, /*42は机がない場所を指す*/
		{  0, 0, 0, 0, 0, 0},
		{  0, 0, 0, 0, 0, 0},
		{  0, 0, 0, 0, 0, 0},
		{  0, 0, 0, 0, 0, 0}, /*ここで席の固定を行う*/
		{  0, 0, 0, 0, 0, 0},
		{  0, 0, 0, 0, 0, 0},

	};
	int a, b,n,i,c,d,f=0;
	char temp[80];	/*fflushを使うためだけの文字配列*/

	srand((unsigned)time(NULL));/*乱数の種を作成*/

	for(i=1;i<=41;i++){
		do{
			if(i==32) f = 1; /*32番は今クラスにいないのでループを打ち切る*/
			else{
				a= rand()%7;
				b= rand()%6;
				if(seki[a][b]==0){
					seki[a][b]=i;
					f=1;			/*0が入っているところを選べたらそこに代入しループを終了*/
				}
				else{
					f=0;
				}
			}
		}while(f==0);
	}

	printf("Are you ready?");
	fflush(stdin);
	gets(temp);   /*Enterを押すと進むようにする*/
	puts("");

	printf("             I教卓I        \n");
	for(c=0;c<7;c++){
		printf(" I ");
		for(d=0;d<6;d++){
			n = seki[c][d];
			for(i=0;i<100000000;i++){} /*出力に時間差を持たすための無駄ループ*/
			if(n==42)printf("  ");
			else printf("%2d",n);
			printf(" I ");
		}
		puts("");
	}

}
