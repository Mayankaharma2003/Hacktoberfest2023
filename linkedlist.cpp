#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *address;
};
struct node *start=NULL,*temp,*New,*prev,*next;
void create();
void insert();
void Delet();
void display();
int main()
{
	int ch;
	do
	{
	    printf("\n---------------linked list----------------");
	    printf("\nenter 1 to create");
	    printf("\nenter 2 to insert");
	    printf("\nenter 3 to Delet");
	    printf("\nenter 4 to display");
	    printf("\nenter 5 to exit");
	    printf("\nenter your choice");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:create();break;
		    case 2:insert();break;
		    case 3:Delet();break;
		    case 4:display();break;
		    case 5:break;
		    daufalt:printf("\nyou have enter wrong choice");
		}
    }while(ch!=5);
}
void create()
{
	int n;
	char choice;
    if(start!=NULL)
    {
	printf("\nlist already created");
	}
	else
	{
		printf("enter element in list");
		scanf("%d",&n);
		start=(struct node*)malloc(sizeof(struct node));
	    start->data=n;
	    start->address=NULL;
		temp=start;
		printf("to add more elements in list press Y");
		scanf("%c",choice);
		while(choice=='y'||choice=='Y')
		{
		    printf("enter element in list");
		    scanf("%d",&n);
		    New=(struct node*)malloc(sizeof(struct node));
		    New->data=n;
		    New->address=NULL;
		    temp->address=New;
		    temp=New;
		    printf("to add more elements in list press Y");
		    scanf("%c",choice);
		}
	}
}	
void insert()
{   
    int count =0;
    if(start==NULL)
    {
	    printf("\nlist not created , create a list first");
	}
	else
    {
        int pos;
        printf("enter position you have to insert");
        scanf("%d",&pos);
	    int n;
		printf("enter element in list");
		scanf("%d",&n);
		New=(struct node*)malloc(sizeof(struct node));
		New->data=n;
		New->address=NULL;   
	    if(pos==1)
	    {
	    	New->address=start;
	    	start=New;
		}
		else
		{
		    temp=start;
		    while(temp!=NULL)
		    {
			    count++;
		    }
	    }
	    if(pos>count+1)
	    {
	    	printf("invalid position maximum posible position is %d",count);
	   	}
		else if(pos==count+1)
		{
			temp=start;
		    while(temp!=NULL)
		    {
			    temp=temp->address;
		    }
			temp->address=New;
		}
		else
		{
			next=start;
            int i=1;
			while(i!=pos)
			{
				prev=next;
				next=next->address;
			}
			prev->address=New;
			New->address=next;
		}
    }	
}	
void Delet() 
{   
    int count;
    if(start==NULL)
    {
	    printf("\nlist not created , create a list first");
	}
	else
    {
        int pos;
        printf("enter position you have to delet");
        scanf("%d",&pos);
		if(pos==1)
	    {
	    	temp=start;
	    	printf("the deleted element is %d",temp->data);
	    	free(temp);
        }
		else
		{
		    temp=start;
		    while(temp!=NULL)
		    {
			    count++;
		    }
	    }
	    if(pos>count)
	    {
	    	printf("invalid position maximum posible position is %d",count);
	    }
		else if(pos==count)
		{
			next=start;
			while(next!=NULL)
			{
				prev=next;
				next=next->address;
			}
		    prev->address=NULL;
		    printf("the deleted element is %d",next->data);
		    free(next);
		}
		else
		{
			next=start;
            int i=1;
			while(i!=pos)
			{
				prev=next;
				next=next->address;
			}
			temp=next;
			next=next->address;
			printf("the deleted element is %d",temp->data);
			free(temp);
		}
    }	
}	
void display()
{   
    if(start==NULL)
    {
	    printf("\nlist not created , create a list first");
	}

	else
	{
		temp=start;
		while(temp!=NULL)
	    {
	    	printf("\n%d\t",temp->data);
	    	temp=temp->address;
		}
	}
}
