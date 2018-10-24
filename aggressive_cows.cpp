#include<bits/stdc++.h>
#define ll long long int
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
using namespace std;
bool fun(int mid,int a[],int n,int k){
	int i,c=1,val=a[0];
	if(c==k) return 1;
	for(i=1;i<n;i++){
		if((a[i]-val)>=mid){
			c++;
			if(c==k) return 1;
			val=a[i];
		}
	}
	return 0;
}

int main(){
	fast();
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n],i;
		for(i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		int l=0,h=a[n-1]-a[0]+1,mid,temp,ans=-1;
		while(l<=h){
			mid=l+(h-l)/2;
			if(fun(mid,a,n,k)){
				temp=mid;
				if(temp>ans) ans=temp;
				l=mid+1;
			}
			else h=mid-1;
		}
		cout<<ans<<"\n";
	}
}

