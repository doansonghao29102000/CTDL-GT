#include <iostream>
using namespace std;
struct Node
{
      int data;
	Node* prev;
	Node* next;
};
typedef Node* NodePtr;
NodePtr CreateNode(int x){
     NodePtr temp = new Node;
     temp->prev = temp;
     temp->next = temp;
     temp->data = x;
     return temp;
}
int Length(NodePtr &pHead) {
    NodePtr current = pHead;
    int i = 1;
    if (pHead == NULL) {
        return 0;
    } else {
        current = current -> next;
        while (current != pHead) {
            i++;
            current = current -> next;
        }
    }
    return i;
}
void in(NodePtr pHead) 
{
     NodePtr p;
     if (pHead == NULL ) return;
     p = pHead;
     do{
          cout<<p->data<<" ";
          p = p->next;
     }while (p != pHead);
}
void InsertFirst(NodePtr &pHead, int x) 
{ 
     NodePtr node = CreateNode(x);
     if(pHead == NULL){ 
        pHead = node;
        pHead->prev =pHead->next = pHead;
     }
     else{ 
         NodePtr q; 
         q = pHead -> prev;
         node->next = pHead;
	   pHead -> prev = node;
         q -> next = node;
         node->prev = q;
         pHead = node;
     }
}
void InsertLast(NodePtr &pHead, int x) 
{ 
     NodePtr node = CreateNode(x);
     if(pHead == NULL){ 
	     pHead = node;
	     pHead->prev = pHead->next = pHead;
     }
    else{
	    NodePtr q;
	    q = pHead ->prev; 
	    node->next = pHead;
	    pHead -> prev = node;
	    q -> next = node;
	    node->prev = q;
    }
}
void InsertAtArbitrary(NodePtr &pHead, int data, int location) {
    int len = Length(pHead), i;
    if(location < 1 || location > len + 1){
        cout<<"vi tri chen khong hop le"<<endl;
    }else{
        if (pHead == NULL) return InsertFirst(pHead, data);
        NodePtr newNode = CreateNode(data);
        NodePtr current = pHead;
        for (i = 1; i != location; i++) current = current -> next;
        newNode -> next = current -> next;
        current -> next = newNode;
        if (location == len + 1) pHead = newNode;
    }
}
void DeleteFirst(NodePtr &pHead)
{
     NodePtr p;
     if(pHead == NULL) return;
     else
         if(pHead ->prev == pHead->next){
             delete pHead;
             pHead = NULL;
         }
         else{
		p = pHead;
		NodePtr q = pHead -> prev;
		pHead = pHead ->next;
		pHead -> prev = q;
		q -> next = pHead;
		delete p;
       }
}
void DeleteLast(NodePtr &pHead){
	if (pHead == NULL) return;
      else
	    if(pHead ->prev == pHead->next){
			delete pHead;
			pHead = NULL;
          }
          else{ 
			NodePtr p = pHead -> prev;
			NodePtr q = p -> prev;
			q -> next = pHead;
			pHead -> prev = q;
			delete p;
         }
}
void DeleteByLocation(NodePtr &pHead, int location) {
     NodePtr  current;
     NodePtr previous = pHead;
     int len = Length(pHead), i;
     if (location < 1 || location > len) {
        cout<<"vi tri xoa khong hop le"<<endl;
     } else if (len == 1){
        pHead = NULL;
     } else {
        current = pHead -> next;
        for (i = 1; i < location; i++) {
            previous = current;
            current = current -> next;
        }
        previous -> next = current -> next;
        if (current == pHead) pHead = previous;
    }
}
void sort(NodePtr  &pHead) {
    if (Length(pHead) < 2) return;
    NodePtr  ptr1 = pHead -> next;
    NodePtr  ptr2, min;
    int temp;
    // selection sort 
    while (ptr1 -> next != pHead -> next) {
        min = ptr1;
        ptr2 = ptr1 -> next;
        while (ptr2 != pHead -> next) {
            if (min -> data > ptr2 -> data) min = ptr2;
            ptr2 = ptr2 -> next;
        }
        if (min != ptr1) {
            temp = min -> data;
            min -> data = ptr1 -> data;
            ptr1 -> data = temp;
        }
        ptr1 = ptr1 -> next;
    }
}
int main(){
	NodePtr pHead = NULL;
	while(1){
		cout<<"=========menu======="<<endl;
		cout<<"1.them nut vao dau danh sach lk vong doi"<<endl;
		cout<<"2.them nut vao sau danh sach lk vong doi"<<endl;
		cout<<"3.them nut vao vi tri bat ki trong danh sach lk doi vong"<<endl;
		cout<<"4.xoa nut o vi tri dau tien"<<endl;
		cout<<"5.xoa nut o vi tri cuoi cung"<<endl;
		cout<<"6.xoa nut o vi tri bat ki"<<endl;
		cout<<"7.sap xep cac nut"<<endl;
		cout<<"0.dung vong lap"<<endl;
		cout<<"==========end======="<<endl;
		int lc;
		cout<<"Nhap lua chon:";cin>>lc;
		if(lc == 1){
			int x;cout<<"Nhap gia tri can chen:";cin>>x;
			InsertFirst(pHead,x);
		}
		else if(lc == 2){
			int x;cout<<"Nhap gia tri can chen:";cin>>x;
			InsertLast(pHead,x);
		}
		else if(lc == 3){
			int x;cout<<"Nhap gia tri can chen:";cin>>x;
			int vitri;cout<<"Nhap vi tri can chen:";cin>>vitri;
			InsertAtArbitrary(pHead,x,vitri);
		}
		else if(lc == 4){
			DeleteFirst(pHead);
		}
		else if(lc == 5){
			DeleteLast(pHead);
		}
		else if(lc == 6){
			int vitri;cout<<"Nhap vi tri nut can xoa:";cin>>vitri;
			DeleteByLocation(pHead,vitri);
		}
		if(lc == 7){
			sort(pHead);
		}
		else if(lc == 0){
			break;
		}
	}
      in(pHead);
      return 0;
}