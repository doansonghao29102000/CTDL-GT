#include <iostream>
using namespace std;
bool binarysearch(int a[] , int n , int x)
{
	int l=0 , r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid] == x) return true;
		else if(a[mid] < x) l=mid+1;
		else r=mid-1;
	}
	return false;
}
bool bs(int a[],int l,int r,int x){
	if(l > r) return false;
	int m=(l+r)/2;
	if(a[m] == x) return true;
	else if(a[m] < x) bs(a,m+1,r,x);
	else bs(a,l,m-1,x);
}
int main()
{
	int n,x;
	cin>>n>>x;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<bs(a,0,n-1,x);
	return 0;
}