#include<iostream.h>
#include<conio.h>
#include<process.h>

struct node
{	int info;
	node* next;
}*top,*newptr,*temp,*ptr;

node* create_new_node(int);
void push(node*);
void pop();
void peep(node*);

void main()
{	top=NULL;
	newptr=NULL;
	temp=NULL;
	ptr=NULL;
	int element,choice;
	while(1)
	{	clrscr();
		cout<<"\n~~~~~~~~~~~~~~~~~";
		cout<<"\n~~~~~~MENU~~~~~~~";
		cout<<"\n\t1.push";
		cout<<"\n\t2.pop";
		cout<<"\n\t3.peep";
		cout<<"\n\t4.Exit";
		cout<<"\n~~~~~~~~~~~~~~~~~";
		cout<<"\n\nEnter your choice :";
		cin>>choice;
		switch(choice)
		{	case 1:cout<<"\nEnter element to be inserted ";
				cin>>element;
				newptr=create_new_node(element);
				push(newptr);
				getch();	break;
			case 2:pop();
				getch();	break;
			case 3:peep(top);
				getch();	break;
			case 4:exit(0);
			default:cout<<"\nEnter choice again\n";
				getch();
		}
	}
}

node* create_new_node(int n)
{       ptr=new node;
	ptr->info=n;
	ptr->next=NULL;
	return ptr;
}

void push(node* np)
{       if(np==NULL)
	{	cout<<"\nOVERFLOW!!!!!";
		return;
	}
	else if(top==NULL)
		top=np;
	else
	{       temp=top;
		top=np;
		np->next=temp;
	}
	cout<<"\nElement inserted sucessfully";
}

void pop()
{	if(top==NULL)
	{	cout<<"\nUNDERFLOW!!!!!!";
		return;
	}
	else
	{    	ptr=top;
		top=top->next;
		delete ptr;
	}
	cout<<"\nElement deleted sucessfully";
}

void peep(node *np)
{	if(np==NULL)
		cout<<"\nEmpty List";
	else
	{	cout<<"\nElements from start are ";
		while(np!=NULL)
		{     	cout<<np->info<<" -> ";
			np=np->next;
		}
	}
}