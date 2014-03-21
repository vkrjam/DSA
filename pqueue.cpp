#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;
struct Node {
	         int dat;
			 int key;
			 Node *prev;
			 Node *next;
			}*temp,*np,*front,*ptr,*save;
			
int insert(int);
int remove();
int peek();
int increase_p(int);
void maxheapify(int);
int data,heapsize=0;
int psearch(int,Node*);
void display(Node*);
int main()
{
 char fname[20];
 int ch,p,v,ele;
 cout<<"Enter filename: ";
 gets(fname);
 ifstream fin(fname,ios::in);
 while(1)
{ 
fin>>ch;
v=0;
switch(ch)
{
 case 1: fin>>ele;fin>>p;
         data=ele;
         v=insert(p);
         cout<<"\n";
         if(v==-1)
          cout<<"Occupied"<<"\n";
         //display(front);
         break;
 case 2: v=remove();
         if(v==-1)
          cout<<"EMPTY\n";
         else
          cout<<data<<" "<<"("<<v<<")\n";
         break;
 case 3: v=peek();
         if(v!=-1)
          cout<<data<<" "<<"("<<v<<")\n";
         else
          cout<<"EMPTY\n";
         break;
case 4: fin>>ele;fin>>p;
        data=ele;
        v=increase_p(p);
        if(v==-1)
         cout<<"Element not present\n";
         else
         cout<<"\n";   
        break;
case 0: return 1;

default:cout<<"Wrong choice";
         return 1;
}
}
}

int insert(int key)
{
	ptr=new Node;
    if(ptr==NULL)
      { cout<<"OVERFLOW\n"; return 1;}
        ptr->key=key;
        ptr->dat=data;
        ptr->next=NULL;
        ptr->prev=NULL;
        
	if(heapsize==0)
	{
        front=ptr;
        heapsize +=1;
     }
    else
    {
		int v;
		v=psearch(key,front);
		if(v==-1)
		{
		 save=front;
		 front=ptr;
		 ptr->next=save;
	    }
		else
		{
			np=front;
			while(v--!=1)
			np=np->next;
			if(np->next==NULL)
			{
				np->next=ptr;
				ptr->prev=np;
			}
			else 
			{
			 save=np->next;
			 np->next=ptr;
			 ptr->prev=np;
			 ptr->next=save;
			}
		 heapsize += 1; 
		}		
	}	
return 1;
}			 

int psearch(int key,Node *n)
{
 int i=1;	
 if(n->next == NULL && n->key > key)
 return -1; 	
 if(n->next == NULL && n->key < key)
 return 1;	
 while(n->next!=NULL)
 {
   if(n->key < key && n->next->key > key)
   return i;
   i++;
   n=n->next;
 }
 if(key < front->key)
  return -1;
return i;
}

void display(Node* n)
{
	while(n!=NULL)
	{cout<<n->key<<" "<<n->dat<<"\n";
     n=n->next;
   }
}
int peek()
{
	if(heapsize != 0)
	{	
		data=front->dat;
		return front->key;
	}
	else
		return -1;
}
int remove()
{
 int i=-1;
 if(heapsize!=0)
 {
 data=front->dat;
 i=front->key;
 ptr=front;
 front=front->next;
 delete ptr;
 heapsize -= 1;
 return i;
 
}
else 
return i;
}	
int increase_p(int key)
{
	int flag=-1;
	np=front;
	while(np!=NULL)
	{if(np->dat==data)
	  {flag=1;
	   break;}
	  np=np->next;
    }
    if(flag==-1)
    return flag;
    else
    {   if(np->next!= NULL)
		{
		 data=np->dat;
		 save=np->next;
		 np=np->prev;
		 np->next=save;
		 save->prev=np;
	    }
	    else
	    {
		 ptr=np;
		 np=np->prev;
		 delete ptr;
	  
	  }
	  return insert(key);
	  
	  }	
         
}	 
