#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
int i,j,height=20,width=20,gameover,score,fruitx,fruity,x,y,flag;

void draw()
{
	system("cls");
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			if(i==0|| i==width-1 || j==0 || j==height-1)
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	 printf("score = %d", score);
    printf("\n");
    printf("press X to quit the game");
}

void setup()
{
	gameover=0;
	x=width/2;
	y=height/2;
	label1:
		fruitx=rand()%20;
		if(fruitx==0)
		{
			goto label1;
		}
	label2:
		fruity=rand()%20;
		if(fruity==0)
		{
			goto label2;
		}
	score=0;
}
void input()
{
	if(kbhit()) //predefined function to know whether key is pressed or not
	{
		switch(getch())
		{
			case 'a':
				flag=1;
				break;
			case 'w':
				flag=2;
				break;
			case 'd':
				flag=3;
				break;
			case 's':
				flag=4;
				break;
			case 'x':
				gameover=1;
				break;
			
		}
	}
}
void logic()
{
	sleep(0.1);
	switch(flag)
	{
		case 1:
			y--;
			break;
		case 2:
			x++;
			break;
		case 3:
			y++;
			break;
		case 4:
			x--;
			break;
		default:
			break;
				
	}
	if (x<=0 || x>=height || y<=0 || y>= width)
	{
		gameover=1;
	}
	if(x==fruitx && y==fruity)
	{
		label3:
			fruitx=rand();
			if(fruitx==0)
				goto label3;
		label4:
			fruity=rand();
			if(fruity==0)
				goto label4;
		score=score+10;	
	}
}
void main()
{
	setup();
	while(!gameover)
	{
	draw();
	
	
	input();
	logic();
}
}
