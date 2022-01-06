#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
// tao cau truc mat hang
struct Mat_Hang
{
	int MaMH;
	string TenMH;
	string DonViTinh;
	float TrongLuong;
	float DonGia;
};
// tao cau truc danh sach lien ket don
typedef struct node
{
	Mat_Hang data;
	node* next;
}NODE;
typedef NODE* NodePtr;         // dinh nghia kieu NodePtr;
NodePtr   pHead;             // nut dau quan ly danh sach

// khoi tao danh dach mat hang
void Khoi_Tao(NodePtr &pHead)
{
	pHead = NULL;
}
// ham kiem tra danh sach co rong khong
bool IsEmpty(NodePtr pHead)
{
	return (pHead == NULL);
}
// cap phat dong mot node moi luu chu thong tin mat hang
NodePtr CreateNode(Mat_Hang x)
{
	cout<<"Nhap Ma Mat Hang : ";
	cin >> x.MaMH;
	cin.ignore();
	cout<<"Nhap Ten Mat Hang : ";
	getline(cin, x.TenMH);
	cout<<"Nhap Don Vi Tinh : ";
	cin >> x.DonViTinh;
	cout<<"Nhap Trong Luong : ";
	cin >> x.TrongLuong;
	cout<<"Nhap Don Gia : ";
	cin >> x.DonGia;
	NodePtr tmp = new NODE();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
// so luong mat hang trong danh sach lien ket don
int Size(NodePtr pHead)
{
	int cnt = 0;
	NodePtr p;
	p = pHead;
	while(p != NULL){
		cnt++;
		p = p->next;
	}
	return cnt;
}
// in ra thong tin mat hang 
void In(Mat_Hang x)
{
	cout<<"|"<<setw(15)<<left<<x.MaMH<<"|"<<setw(20)<<left<<x.TenMH<<"|"<<setw(15)<<left<<x.DonViTinh;
	cout<<"|"<<setw(15)<<left<<x.TrongLuong<<"|"<<setw(15)<<left<<x.DonGia<<"|"<<endl;
	cout<<"--------------------------------------------------------------------------------------"<<endl;
}
// 1.in ra thong tin cac mat hang trong danh sach lien ket
void InMatHang(NodePtr pHead)
{
      cout<<"______________________________________________________________________________________"<<endl;
      cout<<"|"<<setw(15)<<left<<"Ma Mat Hang"<<"|"<<setw(20)<<left<<"Ten Mat Hang";
	cout<<"|"<<setw(15)<<left<<"Don Vi Tinh";
      cout<<"|"<<setw(15)<<left<<"Trong Luong"<<"|"<<setw(15)<<left<<"Don Gia"<<"|"<<endl;
      cout<<"--------------------------------------------------------------------------------------"<<endl;
	NodePtr p;          //p la con tro de duyet
	p = pHead;          //bat dau tu nut dau
	while(p != NULL){   //khi chua het ds
		In(p->data);  //in ra thong tin mat hang cua node
		p = p->next;  //chuyen nut sau
	}
}
// 2.tim mot mat hang theo ma mat hang
void TimKiemMa(NodePtr pHead, int Ma)
{
	int cnt = 0;
	NodePtr p;
	p = pHead;
      while(p != NULL){
	     if(p->data.MaMH == Ma){
	     	        cnt++;
	     	        cout<<"\n\n                   THONG TIN MAT HANG TIM KIEM BANG MA NHAP VAO                   "<<endl;
			  cout<<"______________________________________________________________________________________"<<endl;
		        cout<<"|"<<setw(15)<<left<<"Ma Mat Hang"<<"|"<<setw(20)<<left<<"Ten Mat Hang";
			  cout<<"|"<<setw(15)<<left<<"Don Vi Tinh";
		        cout<<"|"<<setw(15)<<left<<"Trong Luong"<<"|"<<setw(15)<<left<<"Don Gia"<<"|"<<endl;
		        cout<<"--------------------------------------------------------------------------------------"<<endl;
	     	        In(p->data);
	      }
	      p = p->next;
      }
	
	if(cnt == 0) cout<<"\n\tNote*: Khong Tim Thay Mat Hang Nao Co Ma Giong Ma Duoc Nhap Vao!"<<endl;
}
// kiem tra ma mat hang giong nhau trong dslk
bool KiemTraMa(NodePtr pHead, NodePtr x)
{
	NodePtr p;
	p = pHead;
	while(p != NULL){
		if(p->data.MaMH == x->data.MaMH){
			return true;
		}
		p = p->next;
	}
	return false;
}
// 3.them mat hang vao dau danh sach lien ket neu khong bi trung ma
void ThemDau(NodePtr &pHead, Mat_Hang x)
{
 	NodePtr p ;
 	cout<<"==>Nhap Thong Tin Mat Hang Them Vao Danh Sach."<<endl;
 	p = CreateNode(x);
 	if(pHead == NULL){
 		pHead = p;
 		pHead->next=NULL;
      }
      else{
           if(KiemTraMa(pHead,p) == true){
      	 cout<<"\n\tNote*: Mat Hang Nay Da Bi Trung Ma Len Khong Them Vao Dau DSLK!!!"<<endl;
           }
           else{
   	       p->next = pHead;
    	       pHead = p;
    	       cout<<"\n\n       DANH SACH THONG TIN MAT HANG SAU KHI THEM MOT MAT HANG VAO DAU DANH SACH            "<<endl;
           	 InMatHang(pHead);
           }
      }
}
// tim node chua mat hang can xoa trong dslk
NodePtr TimNode(NodePtr pHead, int Ma)
{
	NodePtr q = NULL;
	NodePtr p;
	p = pHead;
	while(p != NULL){
		if(p->data.MaMH == Ma){
			q = p;
			return q;
		}
		p = p->next;
	}
	return q;
}
// 4.xoa mat hang tu ma mat hang nhap vao
void XoaMatHang(NodePtr &pHead, int Ma)
{
	NodePtr pos = TimNode(pHead,Ma);
	if(pos == NULL) cout<<"\n\tNote*: Khong Co Mat Hang Can Xoa Trong Danh Sach!"<<endl;
	else{
		NodePtr p = pHead;
		if(pos == pHead){
			pHead = pHead->next;
			delete p;
		}
		else{
			while(p->next != pos){
				p = p->next;
			}
			p->next = pos->next;
			delete pos;
		}
		cout<<"\n\n         DANH SACH THONG TIN MAT HANG SAU KHI XOA MOT MAT HANG TU MA NHAP VAO            "<<endl;
           	InMatHang(pHead);	
	}
}
// 5.in ra danh sach mat hang co cung dvt duoc nhap vao
void InDSMoi(NodePtr pHead, string dvt)
{
	int cnt=0;
	NodePtr p;
	p = pHead;
	cout<<"\n\n              DANH SACH THONG TIN CAC MAT HANG CO CUNG DON VI TINH                "<<endl;
      cout<<"______________________________________________________________________________________"<<endl;
      cout<<"|"<<setw(15)<<left<<"Ma Mat Hang"<<"|"<<setw(20)<<left<<"Ten Mat Hang";
	cout<<"|"<<setw(15)<<left<<"Don Vi Tinh";
      cout<<"|"<<setw(15)<<left<<"Trong Luong"<<"|"<<setw(15)<<left<<"Don Gia"<<"|"<<endl;
      cout<<"--------------------------------------------------------------------------------------"<<endl;
      while(p != NULL){
      	if(p->data.DonViTinh == dvt){
      		  cnt++;
	     	        In(p->data);
	      }
	      p = p->next;
      } 
	if(cnt == 0) cout<<"\n\tNote*: Khong Tim Thay Cac Mat Hang Voi Don Vi Tinh Da Nhap"<<endl;     
}
// 6.dem so mat hang co don vi tinh la hop
int Dem_Hop(NodePtr pHead)
{
	int cnt=0;
	NodePtr p;
	p = pHead;
	cout<<"\n\n                     THONG TIN CAC MAT HANG CO DON VI TINH LA HOP                 "<<endl;
      cout<<"______________________________________________________________________________________"<<endl;
      cout<<"|"<<setw(15)<<left<<"Ma Mat Hang"<<"|"<<setw(20)<<left<<"Ten Mat Hang";
	cout<<"|"<<setw(15)<<left<<"Don Vi Tinh";
      cout<<"|"<<setw(15)<<left<<"Trong Luong"<<"|"<<setw(15)<<left<<"Don Gia"<<"|"<<endl;
      cout<<"--------------------------------------------------------------------------------------"<<endl;
      while(p != NULL){
      	if(p->data.DonViTinh == "hop"){
      		cnt++;
      		In(p->data);
	      }
	      p = p->next;
      }  
      cout<<"\n\tNote*: So Mat Hang Co Don Vi Tinh La Hop Trong Danh Sach La : "<<cnt<<endl;
}
// 7.sap xep danh sach mat hang tang dan theo don gia
void Sap_Xep(NodePtr &pHead)
{
	for(NodePtr p = pHead; p->next != NULL; p = p->next){
		NodePtr min = p;
		for(NodePtr q = p; q != NULL; q = q->next){
			if(q->data.DonGia < min->data.DonGia){
				min = q;
			}
		}
		Mat_Hang tmp = min->data;
		min->data = p->data;
		p->data = tmp;
	}
}
// 8.them mot mat hang moi vao danh sach, sao cho danh sach van thoa man 
// tang dan theo don gia
void Them_Node(NodePtr &pHead, Mat_Hang x)
{
	NodePtr pos, psau, ptruoc;
	cout<<"===>Nhap Thong Tin Mat Hang Can Them Vao."<<endl;
	pos = CreateNode(x);
 	ptruoc = NULL;
 	psau = pHead;
	if(pHead == NULL){
		pHead = pos;
	      pHead->next = NULL;
	}
	else{
	      Sap_Xep(pHead);
	 	while(psau != NULL){
		 	if(pos->data.DonGia >= psau->data.DonGia){
		 	      ptruoc = psau;
		 	      psau = psau->next;
		 	}
		 	else break;
	      }
	      if(ptruoc == NULL){
	      	if(KiemTraMa(pHead,pos) == true){
      	            cout<<"\tNote*: Mat Hang Nay Da Bi Trung Ma Len Khong Them Vao Dau DSLK!"<<endl;
                  }
	            else{
		   	       pos->next = pHead;
		    	       pHead = pos;
	           	
	            }
	      }
	      else{
	      	if(KiemTraMa(pHead,pos) == true){
      	            cout<<"\tNote*: Mat Hang Nay Da Bi Trung Ma Len Khong Them Vao Dau DSLK!"<<endl;
                  }
	            else{
		   	       pos->next = ptruoc->next;
		   	       ptruoc->next = pos;
	            }
            }
	}
}
// 9.luu tru danh sach sinh vien nay vao file.txt
void Ghi_Tep(NodePtr pHead)
{
	ofstream fo;
	fo.open("MatHang.txt",ios_base::out);
	NodePtr p;          
	p = pHead;
	fo<<"\n\n                            DANH SACH THONG TIN MAT HANG                           "<<endl;
	fo<<"______________________________________________________________________________________"<<endl;
      fo<<"|"<<setw(15)<<left<<"Ma Mat Hang"<<"|"<<setw(20)<<left<<"Ten Mat Hang";
	fo<<"|"<<setw(15)<<left<<"Don Vi Tinh";
      fo<<"|"<<setw(15)<<left<<"Trong Luong"<<"|"<<setw(15)<<left<<"Don Gia"<<"|"<<endl;
      fo<<"--------------------------------------------------------------------------------------"<<endl;          
	while(p != NULL){   
		fo<<"|"<<setw(15)<<left<<p->data.MaMH<<"|"<<setw(20)<<left<<p->data.TenMH<<"|"<<setw(15)<<left<<p->data.DonViTinh;
	      fo<<"|"<<setw(15)<<left<<p->data.TrongLuong<<"|"<<setw(15)<<left<<p->data.DonGia<<"|"<<endl;
	      fo<<"--------------------------------------------------------------------------------------"<<endl;
		p = p->next;  
	}
	fo.close();
}
// 10.huy toan bo danh sach
void Xoa_Danh_Sach(NodePtr &pHead)
{
	NodePtr p;
	while(pHead != NULL){
		p = pHead;
		pHead = pHead->next;
		delete p;
	}
	cout<<"\tNote: Danh Sach Cac Mat Hang Rong!"<<endl;
}
// nhap vao danh sach mat hang ban dau
void Nhap_Danh_Sach_MH(NodePtr &pHead)
{
	int n;
	cout<<"Nhap So Mat Hang Co Trong Danh Sach : ";cin>>n;
	NodePtr p;
	Mat_Hang x;
	for(int i = 1; i <= n; i++){
		cout<<"===>Nhap Thong Tin Mat Hang Thu "<<i<<endl;
		p = CreateNode(x);
		if(pHead == NULL){
			pHead = p;
		}
		else{
			NodePtr q = pHead;
			while(q->next != NULL){
				q = q->next;
			}
			q->next = p;
		}
	}	
	
}
int main(){
	pHead = NULL;//khoi tao danh sach
	Nhap_Danh_Sach_MH(pHead);
	while(true){
		cout<<"\n==============================MENU============================="<<endl;
		cout<<"|1.In Thong Tin Cac Mat Hang Trong Danh Sach                  |"<<endl;
		cout<<"|2.In Ra Thong Tin Mat Hang Theo Ma Nhap Vao                  |"<<endl;
		cout<<"|3.Them Mot Mat Hang Vao Dau Danh Sach Neu Khong Trung Ma     |"<<endl;
		cout<<"|4.Xoa Mot Mat Hang Khoi Danh Sach Tu Ma Nhap Vao             |"<<endl;
		cout<<"|5.In Thong Tin Danh Sach Cac Mat Hang Co Cung Don Vi Tinh    |"<<endl;
		cout<<"|6.Dem So Mat Hang Co Don Vi Tinh La Hop Trong Danh Sach      |"<<endl;
		cout<<"|7.Sap Xep Danh Sach Mat Hang Tang Dan Theo Don Gia           |"<<endl;
		cout<<"|8.Them Mot Mat Hang Vao DS Van Thoa Man DK Sap Xep Tang Dan  |"<<endl;
		cout<<"|9.Ghi Danh Sach Ra File MatHang.txt                          |"<<endl;
		cout<<"|10.Huy Toan Bo Danh Sach                                     |"<<endl;
		cout<<"|0.Thoat                                                      |"<<endl;
		cout<<"================================END============================"<<endl;
		int luachon;
		cout<<"\n\tNhap Lua Chon : ";cin>>luachon;
		cin.ignore();
		if(luachon == 1){
			cout<<"\n\n                            DANH SACH THONG TIN MAT HANG                              "<<endl;
			InMatHang(pHead);
		}
		else if(luachon == 2){
		      int Ma;
			cout<<"\n\tNhap Vao Ma Mat Hang Can Tim Kiem : "; cin>>Ma;
			TimKiemMa(pHead,Ma);
		}
		else if(luachon == 3){
			Mat_Hang x;
			ThemDau(pHead,x);
		}
		else if(luachon == 4){
			int Ma;
			cout<<"\n\tNhap Vao Ma Cua Mat Hang Can Xoa : ";cin>>Ma;
			XoaMatHang(pHead,Ma);
		}
		else if(luachon == 5){
			string dvt;
			cout<<"\n\tNhap Vao Don Vi Tinh Cua Cac Mat Hang Can Tim : ";
			getline(cin,dvt);
			InDSMoi(pHead,dvt);
		}
		else if(luachon == 6){
			Dem_Hop(pHead);
		}
		else if(luachon == 7){
                  Sap_Xep(pHead);
                  cout<<"\n\n           DANH SACH THONG TIN CAC MAT HANG SAP XEP TANG DAN THEO DON GIA                 "<<endl;
                  InMatHang(pHead);
		}
		else if(luachon == 8){
			Mat_Hang x;
			Them_Node(pHead,x);
			cout<<"\n\n  DS THONG TIN CAC MAT HANG SAP XEP TANG DAN THEO DON GIA SAU KHI CHEN MOT MAT HANG         "<<endl;
                  InMatHang(pHead);
		}
		else if(luachon == 9){
			Ghi_Tep(pHead);
		}
		else if(luachon == 10){
			Xoa_Danh_Sach(pHead);
		}
		else if(luachon == 0){
			break;
		}
		else{
			cout<<"\n\tLua Chon Khong Hop Le. Moi Ban Nhap Lai Lua Chon!";
		}
	}
	return 0;
}
