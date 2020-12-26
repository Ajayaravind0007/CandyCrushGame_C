#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int **mat,flag=0,score=0,flagm,flag_b4_mov=1,x,y,*prow,*pcol,*pcs,*pce,*prs,*pre,head1,head2,moves,moveLimit=25;

char ch;

int* getArr(int size)
{
int *ptr;
ptr=(int*)calloc(size,sizeof(int));
return ptr;
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void move(int m,int n,char c)
{
	if(c=='w')
	swap(&mat[m][n],&mat[m-1][n]);
	else if(c=='a')
	swap(&mat[m][n],&mat[m][n-1]);
	else if(c=='d')
	swap(&mat[m][n],&mat[m][n+1]);
	else
	swap(&mat[m][n],&mat[m+1][n]);
}

int getRand()
{
	return rand()%4;
}

void randFill()
{
	int i,j;
	mat=(int**)calloc(6,sizeof(int*));
	for(i=0;i<=5;i++)
	{
		mat[i]=(int*)calloc(6,sizeof(int));
		for(j=0;j<=5;j++)
		mat[i][j]=getRand();
	}
}

void display()
{
	int i,j;
	printf("\nSCORE : %d			MOVES USED : %d\n",score,moves);
	printf("\n\n");
	for(i=0;i<6;i++)
	{
		for(j=0;j<5;j++)
		printf("%d  ",mat[i][j]);
		printf("%d\n",mat[i][j]);
	}
	printf("\n");
	printf("\nRemaining moves : %d\n",moveLimit-moves);
}

void moveUp(int i,int j)
{
while(i>0)
{
swap(&mat[i][j],&mat[i-1][j]);
i--;
}
mat[0][j]=getRand();
score++;
}

void patternRow(int pr,int start,int end)
{
int i;
for(i=start;i<=end;i++)
{
if(mat[pr][i]!=-1)
mat[pr][i]=-1;
}
}

void patternColumn(int pc,int start,int end)
{
int i;
for(i=start;i<=end;i++)
{
if(mat[i][pc]!=-1)
mat[i][pc]=-1;
}
}

void solveMat()
{
int i,j;
for(i=0;i<=5;i++)
for(j=0;j<=5;j++)
{
if(mat[i][j]==-1)
moveUp(i,j);
}
}

void crush()
{
	int i,j,start1,count1,temp1,temp2,start2,count2,flagr,flagc;
	l1:
	flagr=0;
	flagc=0;
	flagm=0;
	count2=0;
	head1=-1;
	head2=-1;
	j=5;
	count1=0;
	while(j>=0 && flagm==0)
	{
	i=1;
	while(i<=4 && flagm==0)
	{
		if(flagm==0)
		{
		if(j==5 || j==0)
		{
			if(j==5)
				{
			if((mat[j][i]==mat[j][i-1] && mat[j][i]==mat[j-1][i+1]) || (mat[j][i]==mat[j][i+1] && mat[j-1][i-1]==mat[j][i]) || (mat[j][i-1]==mat[j][i+1] && mat[j][i-1]==mat[j-1][i]))
				flagm=1;
				}
			else
				{
			if((mat[j][i]==mat[j][i+1] && mat[j][i]==mat[j+1][i-1]) || (mat[j][i]==mat[j][i-1] && mat[j][i]==mat[j+1][i+1]) || (mat[j][i-1]==mat[j][i+1] && mat[j-1][i]==mat[j][i-1]))
				flagm=1;
				}
		}
		else
		{
			if((mat[j][i]==mat[j][i-1] && (mat[j][i]==mat[j-1][i+1] || mat[j][i]==mat[j+1][i+1])) || (mat[j][i]==mat[j][i+1] && (mat[j][i]==mat[j+1][i-1] || mat[j][i]==mat[j-1][i-1])) || (mat[j][i-1]==mat[j][i+1] && (mat[j][i-1]==mat[j-1][i] || mat[j][i-1]==mat[j+1][i])))
flagm=1;
		}
		}
		i++;
		}
		j--;
		}
		j=0;
		while(j<=5 && flagm==0)
		{
		i=4;
		while(flagm==0 && i>0)
if(flagm==0)
		{
			if(j==0 || j==5)
			{
				if(j==0)
				{
					if((mat[i][j]==mat[i+1][j] && mat[i][j]==mat[i-1][j+1]) || (mat[i][j]==mat[i-1][j] && mat[i+1][j+1]==mat[i][j]) || (mat[i-1][j]==mat[i+1][j] && mat[j+1][i]==mat[i+1][j]))
					flagm=1;
				}
				else
				{
					if((mat[i][j]==mat[i+1][j] && mat[i-1][j-1]) || (mat[i][j]==mat[i-1][j] && mat[i][j]==mat[i+1][j-1]) || (mat[i+1][j]==mat[i-1][j] && mat[i][j-1]==mat[i-1][j]))
flagm=1;
				}
			}
			else
			{
			if((mat[i][j]==mat[i+1][j] && (mat[i][j]=mat[i-1][j-1] || mat[i][j]==mat[i-1][j+1])) || (mat[i][j]==mat[i-1][j] && (mat[i][j]==mat[i+1][j-1] || mat[i][j]==mat[i+1][j+1])) || (mat[i-1][j]==mat[i+1][j] && (mat[i-1][j]==mat[i][j-1] || mat[i-1][j]==mat[i][j+1])))
flagm=1;
			}
			i--;
		}
		j++;
		}
		j=5;
	while(j>=0)
	{
		i=1;
	while(i<=4)
	{
		if(mat[j][i-1]==mat[j][i] && mat[j][i]==mat[j][i+1])
		{
			count1=3;
			temp1=i+1;
			temp2=i-1;
				while(temp1<5 && mat[j][temp1]==mat[j][temp1+1])
				{
				count1++;
				temp1++;
				}
				while(temp2>0 && mat[j][temp2]==mat[j][temp2-1])
				{
				count1++;
				temp2--;
				}
				start1=temp2;
			printf("Pattern found from column %d to column %d in row %d of gem type %d\n",start1+1,start1+count1,j+1,mat[j][start1]);
			flagr=1;
			//patternRow(j,start1,start1+count1-1);
			prs[++head1]=start1;
			pre[head1]=start1+count1-1;
			prow[head1]=j;
			i=temp1-1;
		}
		i++;
	}
	j--;
	}
	j=0;
	while(j<=5)
	{
		i=4;
	while(i>0)
	{
		if(mat[i-1][j]==mat[i][j] && mat[i][j]==mat[i+1][j])
		{
			count2=3;
			temp1=i-1;
			temp2=i+1;
			while(temp1>0 && mat[temp1][j]==mat[temp1-1][j])
			{
			count2++;
			temp1--;
			}
			while(temp2<5 && mat[temp2][j]==mat[temp2+1][j])
			{
			count2++;
			temp2++;
			}
			start2=temp2;
			printf("Pattern found from row %d to row %d in column %d of gem type %d\n",start2-count2+2,start2+1,j+1,mat[start2-count2+1][j]);
			flagc=1;
			pcs[++head2]=start2-count2+1;
			pce[head2]=start2;
			pcol[head2]=j;
			i=temp1+1;
		}
		
		i--;
	}
	j++;
	}
	while(head1>-1)
	{
	patternRow(prow[head1],prs[head1],pre[head1]);
	head1--;
	}
	while(head2>-1)
	{
	patternColumn(pcol[head2],pcs[head2],pce[head2]);
	head2--;
	}
	if(flagr==1 || flagc==1)
	{
	solveMat();
	display();
	flag_b4_mov=1;
	goto l1;
	}
	if(flagm==0)
	{
		printf("Changing cells ...\n");
		randFill();
		display();
		goto l1;
	}
	else
	{
		if(flag_b4_mov==0)
		{
			printf("No pattern matching on your move ....\n");
			move(x,y,ch);
			display();
		}
	}
}

void error()
{
printf("Can't move\n");
}

int main()
{
	int limit=50;
	prs=getArr(6);
	pre=getArr(6);
	pcs=getArr(6);
	pce=getArr(6);
	prow=getArr(6);
	pcol=getArr(6);
	char inp[4],wish,name[40];
	printf("* * * * * * * *		Candy crush	* * * *	* * * *\n");
	printf("Welcome to the console-based candy crush game designed by RavageR(Aravind R).\n");
	printf("Enter your nickname : ");
	scanf("%s",name);
	printf("Welcome %s,\n",name);
	printf("Glad to see you here !!!\n");
	printf("Match similar gem patterns either in row or column wise of atleast 3 to score.\n");
	levelplus:
	moves=0;
	printf("Reach score above %d within %d moves to get into next level.\n",limit,moveLimit);
	srand(time(0));
	randFill();
	printf("Enter the value in the format row,column .\n");
	printf("To move cell up enter 'w'\n");
	printf("To move cell down enter 's'\n");
	printf("To move cell right enter 'd'\n");
	printf("To move cell left enter 'a'\n");
	while(score<=limit && moves<moveLimit)
	{
		display();
		crush();
		printf("Enter the row,column : \n");
		scanf("%s",inp);
		flag_b4_mov=0;
		x=inp[0]-49;
		y=inp[2]-49;
		d1:
		printf("Enter wasd input :\n");
		scanf(" %c",&ch);
		if(x==0 || x==5)
		{
			if(x==0 && ch=='w')
			{
				error();
				goto d1;
			}
			else if(x==5)
			{
				if(ch=='s')
				{
				error();
				goto d1;
				}
			}
		}
		if(y==0 || y==5)
		{
			if(y==0 && ch=='a')
			{
				error();
				goto d1;
			}
			else if(y==5)
			{
				if(ch=='d')
				{
				error();
				goto d1;
				}
			}
		}
		move(x,y,ch);
		moves+=1;
	}
	printf("You had successfully completed the level %d !!!\n",limit/50);
	printf("Hey %s , Do you wish to proceed to next level ?\n",name);
	printf("If yes , press 'y' and hit enter.\n");
	scanf(" %c",&wish);
	if(wish=='y')
	{
	limit+=50;
	moveLimit+=25;
	goto levelplus;
	}
	free(mat);
	free(prs);
	free(pre);
	free(pcs);
	free(pce);
	free(prow);
	free(pcol);
	return 0;
}
