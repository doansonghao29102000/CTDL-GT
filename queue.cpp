#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
typedef Node* nodePtr;
struct Queue
{
	nodePtr pHead;
	nodePtr pTail;
};
nodePtr CreateNode(int x)
{
	nodePtr tmp = new Node;
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
void Init(Queue &p)
{
	p.pHead = NULL;
	p.pTail = NULL;
	
}
void Push(Queue &p, int x)
{
	nodePtr node = CreateNode(x);
	if(p.pHead == NULL){
		p.pHead = p.pTail = node;
	}
	else{
		p.pTail->next = node;
		p.pTail = node;
	}
}
void Top(Queue &p)
{
	if(p.pHead == NULL){
		cout<<"Hang doi rong!!"<<endl;
	}
	else{
		cout<<"Phan tu dau hang doi la:"<<p.pHead->data<<endl;
	}
}
void Pop(Queue &p)
{
	nodePtr node;
	if(p.pHead == NULL){
		cout<<"Hang doi rong!!"<<endl;
	}
	else{
		node = p.pHead;
		cout<<"Phan tu dau hang doi la:"<<node->data<<endl;
		p.pHead = p.pHead->next;
		delete node;
	}
}
void getSize(Queue &p){
	nodePtr q;
	int cnt=0;
	if(p.pHead == NULL){
		cout<<"Danh sach rong!!!"<<endl;
	}
	else{
		q = p.pHead;
		while(q != NULL){
			cnt++;
			q = q->next;
		}
		cout<<"So luong cac phan tu trong hang doi:"<<cnt<<endl;
	}
}
void deleteQueue(Queue &p){
	nodePtr q;
	if(p.pHead == NULL){
		cout<<"Danh sach rong!!!"<<endl;
	}
	else{
		q = p.pHead;
		while(p.pHead != NULL){
			q = p.pHead;
			p.pHead = p.pHead->next;
			delete q;
		}
	}
	cout<<"Hang doi da duoc xoa!!!"<<endl;
}
void in(Queue &p){
	nodePtr q;
	if(p.pHead == NULL){
		cout<<"Danh sach rong!!!"<<endl;
	}
	else{
		q = p.pHead;
		cout<<"Danh sach cac phan tu trong hang doi:";
		while(q != NULL){
			cout<<" | "<<q->data<<" | ";
			q = q->next;
		}
		cout<<endl;
	}
}
int main(){
	Queue p;
	Init(p);
	while(true){
		cout<<"==================menu===================="<<endl;
		cout<<"1.them mot phan tu vao hang doi"<<endl;
		cout<<"2.lay ra phan tu dau tien cua hang doi"<<endl;
		cout<<"3.lay ra phan tu dau tien cua hang doi va xoa"<<endl;
		cout<<"4.so luong cac phan tu trong hang doi"<<endl;
		cout<<"5.xoa cac phan tu cua hang doi"<<endl;
		cout<<"6.in ra cac phan tu cua hang doi"<<endl;
		cout<<"===================end======================="<<endl;
		int luachon;
		cout<<"Nhap lua chon:";cin>>luachon;
		if(luachon == 1){
			int x;
			cout<<"Nhap gia tri can them vao hang doi:";cin>>x;
			Push(p,x);
		}
		else if(luachon == 2){
			Top(p);
		}
		else if(luachon == 3){
			Pop(p);
		}
		else if(luachon == 4){
			getSize(p);
		}
		else if(luachon == 5){
			deleteQueue(p);
		}
		else if(luachon == 6){
			in(p);
		}
	}
	return 0;
}