#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

int z[9][3][3],z1[9][3][3],a[9],b[9][9],b1[9][9],p[4];
int h,i,j,k,temp,check,m,n,x,y;

void sudo_gnrt();
void print();
void segment();
void method();
void puzzle();
void solver();
void exit();

void main()
{clrscr();
 randomize();

 method();
 puzzle();
 solver();
}

/********** CHECKER **********/
void sudo_gnrt()
   {for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    {x=i;
     y=j;
     do{if(kbhit())
	  break;
	check=0;
	for(h=0;h<m;h++)
	for(k=0;k<3;k++)
	   {temp=abs(n-p[h]);
	    if(temp%3==0)
	      {if(z[p[h]][k][j]==z[n][x][y])
		 {check=1;
		  break;}}
	    else
	      {if(z[p[h]][i][k]==z[n][x][y])
		 {check=1;
		  break;}}}
	if(check==0)
	  {temp=z[n][x][y];
	   z[n][x][y]=z[n][i][j];
	   z[n][i][j]=temp;}
	if(check==1)
	  {y++;
	   if(y==3)
	     {x++;
	      y=0;}}
	if(x==3)
	  {x=0; y=0;
	   method();}}while(check==1);}}

/********** RANDOM VALUE CREATOR **********/
void segment()
    {for(j=0;j<9;j++)
	{do{temp=random(9)+1;
	    check=0;
	    for(k=0;k<j;k++)
	       if(a[k]==temp)
		 check=1;}while(check==1);
	 a[j]=temp;}
     temp=0;
     for(j=0;j<3;j++)
	for(k=0;k<3;k++)
	   z[n][j][k]=a[temp++];}

/********** STRUCTURE **********/
void method()
{for(n=0;n<9;n++)
    segment();

 p[0]=0; m=1; n=1;
 sudo_gnrt();
 p[0]=0; m=1; n=3;
 sudo_gnrt();
 p[0]=0; p[1]=1; m=2; n=2;
 sudo_gnrt();
 p[0]=0; p[1]=3; m=2; n=6;
 sudo_gnrt();
 p[0]=1; p[1]=3; m=2; n=4;
 sudo_gnrt();
 p[0]=2; p[1]=3; p[2]=4; m=3; n=5;
 sudo_gnrt();
 p[0]=1; p[1]=4; p[2]=6; m=3; n=7;
 sudo_gnrt();
 p[0]=2; p[1]=5; p[2]=6; p[3]=7; m=4; n=8;
 sudo_gnrt();}

/********** PRINTER **********/
void print()
{//2D TO 3D
 x=0;
 y=0;
 for(i=0;i<9;i++)
    {if(i>0)
       {x+=3;
	if(i%3==0)
	  {y+=3;
	   x=0;}}
     m=x;
     n=y;
     for(j=0;j<3;j++)
	{for(k=0;k<3;k++)
	    b[n][m++]=z[i][j][k];
	 n++;
	 m=x;}}

 //PRINTER
 cout<<"\t\t\t\t  ";
 textcolor(LIGHTGREEN);
 cputs("SUDOKU");
 cout<<"\n\n";
 for(i=0;i<9;i++)
    {cout<<"\t\t\t   ";
     if(i>0&&i%3==0)
       cout<<endl<<"\t\t\t   ";
     for(j=0;j<9;j++)
	{if(j>0&&j%3==0)
	   cout<<"  ";
	 if(b1[i][j]==0)
	   {textcolor(LIGHTRED);
	    cprintf("%d",b[i][j]);}
	 else if(b1[i][j]==1)
	   {textcolor(WHITE);
	    cputs("_");}
	 else if(b1[i][j]==2)
	   {textcolor(LIGHTCYAN);
	    cprintf("%d",b[i][j]);}
	 cout<<" ";}
     cout<<endl;}}

/********** PUZZLE MAKER **********/
void puzzle()
{//PUZZLE
 for(n=0;n<5;n++)
    for(i=0;i<3;i++)
       for(j=0;j<3;j++)
	  {temp=random(3);
	   if(temp==0)
	     {z1[n][i][j]=0;
	      z1[8-n][abs(2-i)][abs(2-j)]=0;}
	   else
	     {z1[n][i][j]=1;
	      z1[8-n][abs(2-i)][abs(2-j)]=1;}}

 //2D TO 3D
 x=0;
 y=0;
 for(i=0;i<9;i++)
    {if(i>0)
       {x+=3;
	if(i%3==0)
	  {y+=3;
	   x=0;}}
     m=x;
     n=y;
     for(j=0;j<3;j++)
	{for(k=0;k<3;k++)
	    b1[n][m++]=z1[i][j][k];
	 n++;
	 m=x;}}}

/********** SOLVER **********/
void solver()
{do{check=0;
    textcolor(WHITE);
    clrscr();
    print();
    cout<<"\nPress 0 To Solve And Exit";
    cout<<"\nEnter Row - ";
    cin>>x;
    if(x==0)
      {exit();
       continue;}
    cout<<"Enter Column - ";
    cin>>y;
    if(y==0)
      {exit();
       continue;}
    cout<<"Enter Value - ";
    cin>>n;
    if(n==0)
      {exit();
       continue;}
    x-=1;
    y-=1;
    if(b1[x][y]==1)
      {if(b[x][y]==n)
	 b1[x][y]=2;
       else
	 {cout<<"\nWrong Value";
	  getch();}}
    else
      {check=1;
       cout<<"\nINVALID MOVE";
       getch();}
    for(i=0;i<9;i++)
       for(j=0;j<9;j++)
	  if(b1[i][j]==1)
	    check=1;
    if(check==0)
      {cout<<"\n\t\t\t\t";
       textcolor(YELLOW);
       cputs("You Won");
       getch();}}while(check==1);}

/********** EXIT **********/
void exit()
{clrscr();
 for(i=0;i<9;i++)
    for(j=0;j<9;j++)
       if(b1[i][j]==1)
	 b1[i][j]=2;
 print();
 getch();
 check=0;}