#include<iostream>
using namespace std;
struct Node {
    int data;
    Node * next;
};
typedef Node* nodePtr;
 
nodePtr CreateNewNode(int x)
{
	nodePtr tmp = new Node;
	tmp->data = x;
	return tmp;
}
void in(nodePtr &tail) {
    nodePtr current;
    if (tail == NULL) return;
    current = tail->next;
    do {
    	   cout<<current -> data<<" ";
         current = current -> next;
        } while (current != tail -> next);
}
 
int Length(nodePtr tail) {
    nodePtr current = tail;
    int i = 1;
    if (tail == NULL) {
        return 0;
    } else {
        current = current -> next;
        while (current != tail) {
            i++;
            current = current -> next;
        }
    }
    return i;
}
 
void InsertAtHead(nodePtr &tail, int data){
    nodePtr newNode = CreateNewNode(data);
    if (tail == NULL) {
        tail = newNode;
        newNode -> next = newNode;
    } else {
        newNode -> next = tail -> next;
        tail -> next = newNode;
    }
}
 
nodePtr InsertAtEnd(nodePtr &tail, int data){
     nodePtr newNode = CreateNewNode(data);
     if (tail == NULL) {
        tail = newNode;
        newNode -> next = newNode;
    } else {
        newNode -> next = tail -> next;
        tail -> next = newNode;
        tail = newNode;
    }
}

void InsertAtArbitrary(nodePtr &tail, int data, int location) {
    int len = Length(tail), i;
    if(location < 1 || location > len + 1){
        cout<<"vi tri chen khong hop le"<<endl;
    }else{
        if (tail == NULL) return InsertAtHead(tail, data);
        nodePtr newNode = CreateNewNode(data);
        nodePtr current = tail;
        for (i = 1; i != location; i++) current = current -> next;
        newNode -> next = current -> next;
        current -> next = newNode;
        if (location == len + 1) tail = newNode;
    }
}
void DeleteByValue(nodePtr &tail, int data) {
    nodePtr current = tail;
    nodePtr  previous;
    if (tail == NULL) return;
    else if (tail == tail -> next) {
        if (tail -> data == data) {
            tail = NULL;
            free(current);
        }
    }
    do {
        previous = current;
        current = current -> next;
        if (current -> data == data) {
            previous -> next = current -> next;
            if (current == tail) tail = previous;
            free(current);
            current = previous -> next;
        }
    } while (current != tail);
}

void DeleteByLocation(nodePtr tail, int location) {
    nodePtr  current;
    nodePtr previous = tail;
    int len = Length(tail), i;
    if (location < 1 || location > len) {
        cout<<"vi tri xoa khong hop le"<<endl;
    } else if (len == 1) {
        tail = NULL;
        free(current);
    } else {
        current = tail -> next;
        for (i = 1; i < location; i++) {
            previous = current;
            current = current -> next;
        }
        previous -> next = current -> next;
        if (current == tail) tail = previous;
        free(current);
    }
}
void sort(nodePtr  tail) {
    if (Length(tail) < 2) return;
    nodePtr  ptr1 = tail -> next;
    nodePtr  ptr2, min;
    int temp;
    // selection sort 
    while (ptr1 -> next != tail -> next) {
        min = ptr1;
        ptr2 = ptr1 -> next;
        while (ptr2 != tail -> next) {
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
int main() {
    	nodePtr pList = NULL;
	while(1){
		cout<<"=========menu======="<<endl;
		cout<<"1.them nut vao dau danh sach lk vong"<<endl;
		cout<<"2.them nut vao sau danh sach lk vong"<<endl;
		cout<<"3.them nut vao vi tri bat ki trong danh sach lk vong"<<endl;
		cout<<"4.xoa gia tri can xoa"<<endl;
		cout<<"5.xoa nut co vi tri cho truoc"<<endl;
		cout<<"6.sap xep cac nut"<<endl;
		cout<<"0. dung vong lap"<<endl;
		cout<<"==========end======="<<endl;
		int lc;
		cout<<"Nhap lua chon:";cin>>lc;
		if(lc == 1){
			int x;cout<<"Nhap gia tri can chen:";cin>>x;
			InsertAtHead(pList,x);
		}
		if(lc == 2){
			int x;cout<<"Nhap gia tri can chen:";cin>>x;
			InsertAtEnd(pList,x);
		}
		if(lc == 3){
			int x;cout<<"Nhap gia tri can chen:";cin>>x;
			int vitri;cout<<"Nhap vi tri can chen:";cin>>vitri;
			InsertAtArbitrary(pList,x,vitri);
		}
		if(lc == 4){
			int x;cout<<"Nhap gia tri can xoa:";cin>>x;
			DeleteByValue(pList,x);
		}
		if(lc == 5){
			int vitri;cout<<"Nhap vi tri nut can xoa:";cin>>vitri;
			DeleteByLocation(pList,vitri);
		}
		if(lc == 6){
			sort(pList);
		}
		else if(lc == 0){
			break;
		}
	}
	in(pList);
    return 0;
}