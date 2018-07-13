#include <curses.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int rand_k(int t)
{
	return rand()%t;
}

int main()
{
	char st[10];
	int i,k=0;
	k=rand_k(3)+1;
	initscr();
	cbreak();
	echo();
	mvaddstr(1,18,"MORA-GAME");
	mvaddstr(2,10,"Please Input Your Name.");
	mvaddstr(20,1,"______________________________");
	refresh();
	move(21,1);
	getstr(st);
	mvaddstr(3,10,"Your Name Is:");
	mvaddstr(3,25,st);
	mvaddstr(21,1,"\t\t\t\t");
	refresh();
	mvaddstr(4,10,"Enter The Number.[1-3]"); 
	move(21,1);
	i=getch()%3+1;
	//i=i-'0';
	if(i<k) mvprintw(5,10,"Youer Number Is:%d,k=%d.You Lose",i,k);
	else if(i>k) mvprintw(5,10,"Youer Number Is:%d,k=%d.You Win",i,k);
	else mvprintw(5,10,"Youer Number Is:%d,k=%d.DRAW",i,k);
	getch();
	clear();
	refresh();
	endwin();
	return 0;
}

