#include<iostream>
#include <string>
#include <stdlib.h>
using namespace std;

typedef struct node
{
	int info;
	struct node * next;
}NODE;

typedef NODE* NodePtr;
NodePtr pHead;
void init(NodePtr &pHead)
{
	pHead=NULL;
}
int IsEmpty(NodePtr pHead)
{
	return (pHead==NULL);
}
void ShowNode(NodePtr q)
{
	cout<<q->info<<"\t";
}
void ShowList(NodePtr pHead)
 {
  	NodePtr p; 
	 p = pHead; 
	 while (p!=NULL)
 	{
 		ShowNode(p); 
 		p = p->next; 
 	}
 }
 void them_dau(NodePtr &pHead, int x)
 {
 	NodePtr node ;
 	node =new NODE;
 	node ->info = x;
 	if(pHead==NULL)
 	{
 		pHead=node;
 		pHead->next=NULL;
	 }
	 else
	 {
	 	node->next=pHead;
	 	pHead=node;
	 }
 }
 void them_cuoi(NodePtr &pHead, int x)
 {
 	NodePtr node ;
 	node =new NODE;
 	node ->info =x;
 	node ->next =NULL;
 	if(pHead==NULL)
 	{
 		pHead=node;
	 }
	 else
	 {
	 	NodePtr p;
	 	p=pHead;
	 	while(p->next!=NULL)
	 	p=p->next;
	 	p->next=node;
	 }
 }
 NodePtr Timkiem(NodePtr pHead, int x)
 {
 	NodePtr p; 
 	p = pHead; 
 	while ( p != NULL && p->info != x) 
 	p = p->next;
 	return p;
 }
 void them_sau(NodePtr &p, int x)
 {	int k;
 	cout<<"Can chen truoc nut co gia tri: ";cin>>k;
 	p = Timkiem(pHead,k);
 	if(p==NULL)
 	
 		cout<<"Can not insert new node!!!"<<endl;
	 
	 else
	 {
	 	NodePtr node;
 		node = new NODE;
 		node->info = x;
 		node->next = p->next;
	 	p->next = node;
	 }
 }
 void them_truoc(NodePtr &p, int x)
 {
 	NodePtr node;
 	node = new NODE;
 	node->info = x;
 	int  k;
 	cout<<"Can chen sau nut co gia tri: ";cin>>k;
 	p = Timkiem(pHead,k);
 	NodePtr q;
 	 
 	if(p==pHead)
 	{
 		
 		node->next=p;
 		pHead=node;
	 }
	 else
	 {
	 	q=pHead;
 	 while(q->next!=p)
 	 	{
		  q=q->next;
		  }
	 	q->next=node;
	 	node->next=p;
	 	
	 }
 }
 void nhap(NodePtr &pHead)
 {
 	int n;
 	cout<<"Moi ban nhap so node cua danh sach: ";
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{	int x;
 		cout<<"Nhap node thu "<<i<<":";
 		cin>>x;
 		them_cuoi(pHead,x);
	 }
}
void xoa_dau(NodePtr &pHead)
{
	NodePtr p;
 	if (pHead==NULL)
 		cout<<"Danh sach rong!!!";
	else
 	{	p = pHead;
		pHead = pHead->next;
		delete p;
	 }
}
void xoa_cuoi(NodePtr &pHead)
{
	if(pHead==NULL)
	{
		cout<<"Khong the xoa!!!"<<endl;
	}
	else
	{
		NodePtr p, q; 
		p = pHead -> next; 
		q = pHead;
		while (p -> next != NULL)
		{ 	p = p->next;
			q = q->next;
		}
		delete p;
		q -> next =NULL;
  	}
}
void xoa_sau(NodePtr &pHead, NodePtr &p)
{
	int x;
 	cout<<"Nhap gia tri node can xoa sau: ";cin>>x;
 	p = Timkiem(pHead,x);
 	NodePtr q;
 	 q=pHead;
 	 while(q!=p->next)
 	 q=q->next;
 	if(p->next==NULL)
 	{
 		cout<<"Can not delete node!!!"<<endl;
	 }
	 else
	 {
	 	q=p->next;
	 	p->next=q->next;
	 	delete q;
	 	
 	
	 }
}
void xoa_batki(NodePtr &pHead, NodePtr &p)
{
	 int x;
 	 cout<<"Nhap gia tri node  can xoa: ";cin>>x;
 	 p = Timkiem(pHead,x);
 	 if (p==pHead)	xoa_dau(pHead);
 	 else
 	 {	NodePtr q;
 	 	q=pHead;
 	 	while(q->next!=p)
 	 		q=q->next;
 		q->next=p->next;
 	 	delete p;
 	}
}
void xoa_toan_bo(NodePtr &pHead)
{
	NodePtr p;
	while (pHead!=NULL)
 	{
 		p = pHead;
 		pHead = pHead -> next;
 		delete p;
 }
}
void Sort(NodePtr &pHead)
{ 
	NodePtr q, min, p = pHead;
	while (p!=NULL)
	{
		min = p; q = p -> next;
		while (q!=NULL)
		{
			if (q->info < min->info)
			min = q;
			q = q->next;
		}
		swap(p->info, min->info);
		p = p->next;
 	}
}
void menu()
{
	int luachon;
	cout<<"\n";
		cout<<"\n------------------MENU------------------------------";
		cout<<"\n|1. Nhap cac Node trong danh sach                   |";
		cout<<"\n|2. Xuat cac Node trong danh sach                   |";
		cout<<"\n|3. Them 1 Node vao dau danh sach                   |";
		cout<<"\n|4. Them 1 Node vao cuoi danh sach                  |";
		cout<<"\n|5. Tim kiem 1 Node trong danh sach                 |";
		cout<<"\n|6. Them 1 Node sau Node bat ky trong danh sach     |";
		cout<<"\n|7. Them 1 Node truoc Node bat ky trong danh sach   |";
		cout<<"\n|8. Xoa 1 Node dau trong danh sach                  |";
		cout<<"\n|9. Xoa 1 Node cuoi trong danh sach                 |";
		cout<<"\n|10. Xoa 1 Node sau Node bat ky trong danh sach     |";
		cout<<"\n|11. Xoa 1 Node bat ky trong danh sach              |";
		cout<<"\n|12. Sap xep danh sach                              |";
		cout<<"\n|13. Xoa toan bo Node trong danh sach               |";
		cout<<"\n------------------MENU------------------------------";
	do{
		
		cout<<"\n\t\tNhap lua chon: ";
		do{
			cin>>luachon;
			if(luachon < 0 || luachon > 13)
			{
				cout<<"Khong co lua chon nay! Moi nhap lai: ";
				
			}
		}while(luachon < 0 || luachon > 13);
		
		switch(luachon){
			case 1:{
				nhap(pHead);
				break;
			}
			case 2:{
				cout<<"Danh sach sau khi nhap la: "<<endl;
				ShowList(pHead);
				break;
			}
			case 3:{
				int xf;
				cout<<"Nhap gia tri node them dau: ";
				cin>>xf;
				them_dau(pHead,xf);
				cout<<"Danh sach sau khi them dau: "<<endl;
				ShowList(pHead);
				break;
			}
			case 4:{
				int xl;
				cout<<"Nhap gia tri node them cuoi: ";
				cin>>xl;
				them_cuoi(pHead,xl);
				cout<<"Danh sach sau khi them cuoi: "<<endl;
				ShowList(pHead);
				break;
			}
			case 5:{
				int x;
				cout<<"Nhap phan tu can tim: ";cin>>x;
				if(Timkiem(pHead,x)==NULL)
					cout<<"Phan tu "<<x<<" khong co trong danh sach"<<endl;
				else
				{	cout<<"Phan tu "<<x<<" co trong danh sach";
					cout<<" o dia chi "<<Timkiem(pHead,x)<<endl;
				}
				break;			
			}
			case 6:{
				NodePtr p;
				int z;
				cout<<"Nhap gia tri cua node moi:";cin>>z;
				them_sau(p,z);
				cout<<"Danh sach sau khi chen sau: "<<endl;
				ShowList(pHead);
				break;
			}
			case 7:{
				NodePtr a;
				int y;
				cout<<"Nhap gia tri node moi:";cin>>y;
				them_truoc(a,y);
				cout<<"Danh sach sau khi chen truoc: "<<endl;
				ShowList(pHead);
				break;
			}
			case 8:{
				cout<<"Danh sach sau khi xoa phan tu dau la: "<<endl;
				xoa_dau(pHead);
				ShowList(pHead);
				break;
			}
			case 9:{
				cout<<"Danh sach sau khi xoa phan tu cuoi la: "<<endl;
				xoa_cuoi(pHead);
				ShowList(pHead);
				break;
			}
			case 10:{
				NodePtr b;
				xoa_sau(pHead,b);
				cout<<"Danh sach sau khi xoa phan tu sau node la:"<<endl;
				ShowList(pHead);
				break;
			}
			case 11:{
				NodePtr c;
				xoa_batki(pHead,c);
				cout<<"Danh sach sau khi xoa node can xoa: "<<endl;
				ShowList(pHead);
				break;
			}
			case 12:{
				cout<<"Danh sach sau sap xep: "<<endl;
				Sort(pHead);
				ShowList(pHead);
				break;
			}
			case 13:{
				cout<<"Danh sach sau khi xoa toan bo la: "<<endl;
				xoa_toan_bo(pHead);
				ShowList(pHead);
				break;
			}
			
			}
	}while(luachon != 0);
}
int main()
{
	
	init(pHead);
	menu();
	return 0;
}
