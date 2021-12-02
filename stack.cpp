#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
typedef Node* nodePtr;
nodePtr CreateNode(int x)
{
	nodePtr tmp = new Node;
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
void Push(nodePtr &pTop, int x)
{
	nodePtr tmp = CreateNode(x);
	if(pTop == NULL){
		pTop = tmp;
	}
	else{
		tmp->next = pTop;
		pTop = tmp;
	}
}
void Pop(nodePtr &pTop)
{
	nodePtr p;
	if(pTop == NULL){
		cout<<"Khong co phan tu trong ngan xep!!!"<<endl;
	}
	else{
		p = pTop;
		cout<<"Phan tu o dinh ngan xep la:"<<p->data<<endl;
		pTop = pTop->next;
		delete p;
	}
}
void showstack(nodePtr &pTop)
{
	nodePtr p;
	if(pTop == NULL){
		cout<<"Ngan xep rong!!!"<<endl;
	}
	else{
		p = pTop;
		while(p != NULL){
			cout<<"|"<<p->data<<"|"<<endl;
			cout<<"---"<<endl;
			p = p->next;
		}
	}
}
void getSize(nodePtr &pTop)
{
	int cnt=0;
	nodePtr p;
	if(pTop == NULL){
		cout<<"Ngan xep rong!!!"<<endl;
	}
	else{
		p = pTop;
		while(p != NULL){
			cnt++;
			p = p->next;
		}
		cout<<"Do lon cua ngan xep la:"<<cnt<<endl;
	}
	
}
int main(){
	nodePtr pTop = NULL;
	while(true){
		cout<<"===============menu==============="<<endl;
		cout<<"1.them mot phan tu vao ngan xep"<<endl;
		cout<<"2.in ra mot phan tu o dinh ngan xep"<<endl;
		cout<<"3.in ra ngan xep"<<endl;
		cout<<"4.in ra do lon cua ngan xep"<<endl;
		cout<<"===============end================"<<endl;
		int luachon;
		cout<<"Nhap lua chon:";cin>>luachon;
		if(luachon == 1){
			int x;
			cout<<"Nhap gia tri can them vao ngan xep:";cin>>x;
			Push(pTop,x);
		} 
	      else if(luachon == 2){
			Pop(pTop);
		} 
		else if(luachon == 3){
			cout<<"Ngan xep:"<<endl;
			showstack(pTop);
		} 
		else if(luachon == 4){
			getSize(pTop);
		}
		
	}
	return 0;
}