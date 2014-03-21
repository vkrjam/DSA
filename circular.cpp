#include<iostream>
#include<fstream>
using namespace std;
struct Node
{int dat;
 Node *next;
}*front,*np,*f1,*save,*ptr;
Node* func1(char fname[]);
void display(Node*);
int main()
{
char a[20];	
cout<<"Enter filename: ";
gets(a);	
f1=func1(a);
display(f1);
}
Node* func1(char fname[])
{
 int i,len;
 front=NULL;
 ifstream fit(fname,ios::in|ios::binary);
//fin.read((char*) &i,sizeof(i));
fit.seekg(0,ios::end);
len=fit.tellg();
if(len==0)
return NULL;
fit.close();
ifstream fin(fname,ios::in|ios::binary);
if(!fin)	
{cout<<"File doesn't exist\n";
 return NULL;
}
do
{
ptr=new Node;
if(front==NULL)
{
fin.read((char*) &i,sizeof(i));
ptr->dat=i;
ptr->next=NULL;
front=ptr;
}	
else
{
ptr->dat=i;
ptr->next=NULL;		
np=front;
while(np->next!=NULL)
np=np->next;
np->next=ptr;
}
fin.read((char*) &i,sizeof(i));	
}while(fin);	
//display(front);
np=front;
while(np->next!=NULL)
np=np->next;
np->next=front;
return front;

}

void display(Node *n)
{
	if(n==NULL)
	{cout<<"Empty";
	 return;
   }
	do
	{cout<<n->dat<<"\n";
		n=n->next;
	}while(n!=front);
}
