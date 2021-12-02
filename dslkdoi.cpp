#include<iostream>
using namespace std; 
struct Node
{
	int data;
	Node* prev;
	Node* next;
};
typedef Node * nodePtr;
nodePtr CreateNode(int x) {
    nodePtr tmp = new Node;
    tmp->data = x;
    tmp->prev = NULL;
    tmp->next = NULL;
    return tmp;
}
int Sizeof(nodePtr &pHead)
{
	int cnt = 0;
	nodePtr p = pHead;
	while(p != NULL){
		cnt++;
		p = p->next;
	}
	return cnt;
}
void in(nodePtr pHead)
{
	if (pHead == NULL ) return;
	nodePtr p = pHead;
	while(p !=  NULL){
		cout<<p->data<<" ";
		p = p->next;
	}
}
void insertfirst(nodePtr &pHead, int x)
{
	nodePtr tmp = CreateNode(x);
	if(pHead == NULL){
		pHead = tmp;
		pHead->prev =pHead->next = NULL;

	}
	else{
		tmp->next = pHead;
		pHead->prev = tmp;
            tmp->prev = NULL;
		pHead = tmp;
	}	
}
void insertlast(nodePtr &pHead, int x)
{
	nodePtr tmp = CreateNode(x);
	if(pHead == NULL){
		pHead = tmp;
		pHead->prev =pHead->next = NULL;
	}
	else{
		nodePtr p = pHead;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = tmp;
		tmp->prev = p->next;
		tmp->next = NULL;
	}
}
void DeleteFirst(nodePtr &pHead)
{
     nodePtr p;
     if (pHead == NULL) return;
     else
         if(pHead ->prev == pHead->next){
			 delete pHead;
			 pHead = NULL;
         }
         else
   	   {
			 p = pHead; 
			 pHead = pHead ->next; 
			 pHead -> prev = NULL;
			 delete p; 
         }
}
void DeleteLast(nodePtr &pHead)
{ 
     if(pHead == NULL) return;
     else
         if(pHead ->prev == pHead->next){
			 delete pHead;
			 pHead = NULL;
         }
         else{ 
			 nodePtr p;
			 p = pHead;
			 while (p-> next != NULL) 
			 p = p ->next;
			 nodePtr q = p -> prev;
			 q -> next = NULL;
			 delete p;
       }
}
void Search (nodePtr pHead, int x)
{
	 nodePtr p;
	 if (pHead == NULL) cout<<"khong tim thay!!!"<<endl;
	 p = pHead;
	 while (p->data != x && p != NULL)
	 p = p->next;
	 if ( p->data == x){
	 	cout<<"thong tin nut can tim la:";
 		cout<<p<<"  "<<p->data<<endl;
 	 }
	 else cout<<"khong tim thay!!!"<<endl;;
}
int main(){
      nodePtr pHead = NULL;
	while(1){
		cout<<"=========menu======="<<endl;
		cout<<"1.them nut vao dau danh sach"<<endl;
		cout<<"2.them nut vao cuoi danh sach"<<endl;
		cout<<"3.xoa nut vao dau danh sach"<<endl;
		cout<<"4.xoa nut vao cuoi danh sach"<<endl;
		cout<<"5.tim nut co gia tri x cho truoc"<<endl;
		cout<<"0. dung vong lap"<<endl;
		cout<<"==========end======="<<endl;
		int lc;
		cout<<"Nhap lua chon:";cin>>lc;
		if(lc == 1){
			int x;cout<<"Nhap gia tri can chen:";cin>>x;
			insertfirst(pHead,x);
		}
		else if(lc == 2){
			int x;cout<<"Nhap gia tri can chen:";cin>>x;
			insertlast(pHead,x);
		}
		else if(lc == 3){
			DeleteFirst(pHead);
		}
		else if(lc == 4){
			DeleteLast(pHead);
		}
		else if(lc == 5){
			int x;cout<<"Nhap gia tri can tim:";cin>>x;
			Search(pHead,x);
		}
		else if(lc == 0){
			break;
		}
	}
	in(pHead);
	return 0;
}