#include <iostream>
using namespace std;
typedef struct node
{
	int data;
	node* left;
	node* right;
}NODE;
typedef NODE* NodePtr;
NodePtr pTree;//nut goc
//khoi tao
void InitTree(NodePtr &pTree)
{
 	pTree = NULL;
}
//tao nut moi
NodePtr CreateNode(int x)
{
	NodePtr node = new NODE;
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void ThemNodeVaoCay(NodePtr &pTree ,int x)
{
	if(pTree == NULL){
		NodePtr p = new NODE;
		p = CreateNode(x);
		pTree = p;
	}
	else
	{
		if(x < pTree->data){
			ThemNodeVaoCay(pTree->left,x);
		}
		else  if(x > pTree->data){
			ThemNodeVaoCay(pTree->right,x);
		}
		else{
			cout<<"khong the them vao cay!!!"<<endl;
		}
	}
}
void NLR(NodePtr pTree)
{
	if(pTree != NULL)
	{
		cout<<pTree->data<<" ";
		NLR(pTree->left);
		NLR(pTree->right);
	}
}

int main()
{
	pTree = NULL;
	while(true){
		cout<<"=======menu======="<<endl;
		cout<<"1.them mot node vao cay"<<endl;
		cout<<"2.xuat du lieu cay"<<endl;
		cout<<"3.thoat"<<endl;
		int luachon;
		cout<<"nhap lua chon:";cin>>luachon;
		if(luachon == 1){
			int x;
			cout<<"nhap gia tri cua nut can them vao cay:";cin>>x;
			ThemNodeVaoCay(pTree,x);
		}
		else if(luachon == 2){
			cout<<"xuat du lieu theo kieu node left right"<<endl;
			NLR(pTree);
			cout<<endl;
		}
		else if(luachon == 3){
			break;
		}
			
	}
}
