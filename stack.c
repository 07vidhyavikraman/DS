#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
int stack[MAX];
int top=-1;
int max=100;
bool isempty()
{
if(top<=-1)
{
return 1;
}
else
{
return 0;
}
}
bool isfull()
{
if(top>=max)
{
return 1;
}
else
{
return 0;
}
}
void push()
{
int value;
if(isfull())
{
printf("stack is full\n");
}
else
{
printf("enter push item:");
scanf("%d",&value);
top=top+1;
stack[top]=value;
printf("\n%d pushed to stack",value);
}
}
void pop()
{
if(isempty())
{
printf("%d is popped out:",stack[top]);
top=top-2;
}
}
void display()
{
int i;
if(!isempty())
{
for(i=0;i<=top;i++)
{
printf("stack[%d]=%d\n",i+1,stack[i]);
}
}
else
{
printf("stack is empty");
}
}
void peek()
{
if(!isempty())
{
printf("top element is:%d",stack[top]);
}
}
int main()
{
int opt;
do
{
printf("\n......\n");
printf("1)push\n");
printf("2)pop\n");
printf("3)peek\n");
printf("4)display\n");
printf("5)quiet\n");
printf("\n......\n");
printf(" choose your option:");
scanf("%d",&opt);
switch(opt){
case 1:
   push();
   break;
case 2:
   pop();
   break;
case 3:
   peek();
   break;
case 4:
   display();
   break;
case 5:
   exit(0);
default:
    printf("\n invalid operation!try again.....\n");
  }
  }while(1);
  return 0;
}

