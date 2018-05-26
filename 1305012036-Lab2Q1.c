#include <stdio.h> 
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void ctrl_c(int);
void calculate();
void insertFirst(int);
struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

	int main(){
	
	int num = 0;
	
	(void) signal(SIGINT, ctrl_c);
	while (num!=-1)
	{
	printf("enter a number :");
	scanf("%d",&num);
	insertFirst(num);	
	
	}


	return 0;

	}

	void insertFirst(int data) {

struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->data = data;
	
 
   link->next = head;
	

   head = link;
}

	void ctrl_c(int signum) 
	{		
		//(void)signal(SIGINT, ctrl_c); 
		printf("\n<CTRL-C>\n");
		calculate();
	}


	void calculate()
	{
struct node *temp=head;
int average=0;
int inputs=0;
	while(temp!=NULL)
	{
	average += temp->data;
	temp=temp->next;
	inputs++;
	}

	printf("Inputs : %d, Average : %d\n",inputs,average/inputs);
	
	}



