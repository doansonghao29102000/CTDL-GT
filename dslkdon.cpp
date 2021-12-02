#include<iostream>
using namespace std;
typedef struct Node
{
	int data;
	Node *next;
};
typedef Node* nodePtr;
//cap phat dong mot nut moi voi du lieu la sao nguyen x
nodePtr CreateNode(int x)
{
	nodePtr tmp = new Node;
	tmp->data = x;
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
void insertfirst(nodePtr &pHead, int x)
{
	nodePtr tmp = CreateNode(x);
	if(pHead == NULL){
		pHead = tmp;
	}
	else{
		tmp->next = pHead;
		pHead = tmp;
	}
	
}

void insertlast(nodePtr &pHead, int x)
{
	nodePtr tmp = CreateNode(x);
	if(pHead == NULL){
		pHead = tmp;
	}
	else{
		nodePtr p = pHead;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = tmp;
	}
}
void insertafter(nodePtr &pHead, int x, int vitrinut)
{
	if(vitrinut < 1 || vitrinut > (Sizeof(pHead)+1)){
		cout<<"vi tri chen nut khong hop le!!"<<endl;
	}
	else if(vitrinut == Sizeof(pHead)){
		insertlast(pHead,x);
		return;
	}
	else{
		nodePtr p = pHead;
		for(int i=1; i< vitrinut; i++){
			p = p->next;
		}
		nodePtr tmp = CreateNode(x);
		tmp->next = p->next;
		p->next = tmp;
	}
}
void insertbefore(nodePtr &pHead, int x, int vitrinut)
{
	if(vitrinut < 1 || vitrinut > Sizeof(pHead)){
		cout<<"vi tri chen nut khong hop le!!"<<endl;
	}
	else if(vitrinut == 1){
		insertfirst(pHead,x);
		return;
	}
	else{
		nodePtr p = pHead;
		for(int i=1; i< vitrinut-1; i++){
			p = p->next;
		}
		nodePtr tmp = CreateNode(x);
		tmp->next = p->next;
		p->next = tmp;
	}
}
void deletefirst(nodePtr &pHead)
{
	nodePtr p;
	if(pHead == NULL){
		cout<<"khong the xoa nut trong danh sach lien ket rong!!"<<endl;
	}
	else{
		p = pHead;
		pHead = pHead->next;
		delete p;
	}
}
void deletelast(nodePtr &pHead)
{
	nodePtr p;
	if(pHead == NULL){
		cout<<"khong the xoa nut trong danh sach lien ket rong!!"<<endl;
	}
	else{
		nodePtr truoc = NULL;
		p = pHead;
		while(p->next != NULL){
			truoc = p;
			p = p->next;
		}
		if(truoc == NULL){
			pHead = NULL;
		}
		else{
			truoc->next = NULL;
			delete p;
		}
	}
}
void deleteafter(nodePtr &pHead, int vitrinut)
{
	if(vitrinut < 1 || vitrinut >= Sizeof(pHead)){
		cout<<"vi tri xoa nut khong hop le!!"<<endl;
	}
	else if(vitrinut == Sizeof(pHead) - 1){
		deletelast(pHead);
	}
	else{
		nodePtr truoc = NULL;
		nodePtr p = pHead;
		for(int i=1;i<=vitrinut;i++){
			truoc = p;
			p = p->next;
		}
		truoc->next = p->next;
		delete p;
	}
}
void deletebefore(nodePtr &pHead, int vitrinut)
{
	if(vitrinut <= 1 || vitrinut > Sizeof(pHead)){
		cout<<"vi tri xoa nut khong hop le!!"<<endl;
	}
	else if(vitrinut == 2){
		deletefirst(pHead);
	}
	else{
		nodePtr truoc = NULL;
		nodePtr p = pHead;
		for(int i=1;i<vitrinut-1;i++){
			truoc = p;
			p = p->next;
		}
		truoc->next = p->next;
		delete p;
	}
}
void deletenode(nodePtr &pHead, int vitrinut)
{
	if(vitrinut < 1 || vitrinut > Sizeof(pHead)){
		cout<<"vi tri xoa nut khong hop le!!"<<endl;
	}
	else if(vitrinut == 1){
		deletefirst(pHead);
	}
	else if(vitrinut == Sizeof(pHead)){
		deletelast(pHead);
	}
	else{
		nodePtr truoc = NULL;
		nodePtr p = pHead;
		for(int i=1;i<vitrinut-1;i++){
			truoc = p;
			p = p->next;
		}
		truoc->next = p->next;
		delete p;
	}
}
void deleteall(nodePtr &pHead)
{
	nodePtr p;
	while(pHead	 != NULL){
		p = pHead;
		pHead = pHead->next;
		delete p;
	}
}
void Search(nodePtr &pHead, int x){
	nodePtr p = pHead;
	while(p != NULL && p->data != x){
		p = p->next;
	}
	cout<<p<<"  "<<p->data<<endl;
}
void selectionsort(nodePtr &pHead){
	for(nodePtr p = pHead; p->next != NULL; p=p->next){
		nodePtr min = p;
		for(nodePtr q = p->next; q != NULL; q = q->next){
			if(q->data < min->data){
				min = q;
			}
		}
		int tmp = min->data;
		min->data = p->data;
		p->data = tmp;
	}
}
void in(nodePtr pHead)
{
	while(pHead !=  NULL){
		cout<<pHead->data<<" ";
		pHead = pHead->next;
	}
}
int main(){
	nodePtr pHead = NULL;
	while(1){
		cout<<"=========menu======="<<endl;
		cout<<"1.them nut vao dau danh sach"<<endl;
		cout<<"2.them nut vao cuoi danh sach"<<endl;
		cout<<"3.them nut vao sau vi tri mot nut da cho truoc"<<endl;
		cout<<"4.them nut vao truoc vi tri mot nut da cho truoc"<<endl;
		cout<<"5.xoa nut dau tien trong danh sach lien ket"<<endl;
		cout<<"6.xoa nut cuoi cung trong danh sach lien ket"<<endl;
		cout<<"7.xoa nut vao sau vi tri mot nut da cho truoc"<<endl;
		cout<<"8.xoa nut vao truoc vi tri mot nut da cho truoc"<<endl;
		cout<<"9.xoa nut co vi tri da cho truoc"<<endl;
		cout<<"10.xoa danh sach"<<endl;
		cout<<"11.tim nut co phan tu x"<<endl;
		cout<<"12.sap xep cac nut theo thu tu tang dan cua truong data"<<endl;
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
			int x;cout<<"Nhap gia tri can chen:";cin>>x;
			int vitri;cout<<"Nhap vi tri cua nut dung truoc nut can chen:";
			cin>>vitri;
			insertafter(pHead,x,vitri);
		}
		else if(lc == 4){
			int x;cout<<"Nhap gia tri can chen:";cin>>x;
			int vitri;cout<<"Nhap vi tri cua nut dung sau nut can chen:";
			cin>>vitri;
			insertbefore(pHead,x,vitri);
		}
		else if(lc == 5){
			deletefirst(pHead);
		}
		else if(lc == 6){
			deletelast(pHead);
		}
		else if(lc == 7){
			int vitri;cout<<"Nhap vi tri cua nut dung truoc nut can xoa:";
			cin>>vitri;
			deleteafter(pHead,vitri);
		}
		else if(lc == 8){
			int vitri;cout<<"Nhap vi tri cua nut dung sau nut can xoa:";
			cin>>vitri;
			deletebefore(pHead,vitri);
		}
		else if(lc == 9){
			int vitri;cout<<"Nhap vi tri cua nut can xoa:";
			cin>>vitri;
			deletenode(pHead,vitri);
		}
		else if(lc == 10){
			deleteall(pHead);
		}
		else if(lc == 11){
			int x;
			cout<<"nhap gia tri cua nut can tim:";cin>>x;
			cout<<"Dia chi nut can tim la:";
			Search(pHead,x);
		}
		else if(lc == 12){
			selectionsort(pHead);
		}
		else if(lc == 0){
			break;
		}
	}
	in(pHead);
	
	return 0;
}