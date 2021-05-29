#include<bits/stdc++.h>
 
#define lmao cout<<"\nLick My Ass onii-chann ~";
#define alphaa "abcdefghijklmnopqrstuvwxyz"
#define ALPHAA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define mp make_pair
#define fi first
#define se second
#define pb push_back
 
using namespace std;
 
typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
 
const ld pi=2*acos(0);
const ll inf  = LLONG_MAX;
const ll ninf = LLONG_MIN;
const int oo = INT_MAX;
const int noo = INT_MIN;
 
struct HCN{
    int x1,y1;
    int x2,y2;
};
 
int n;
int X[10000];
int u=0;
int Y[10000];
 
bool KT(HCN H,int a,int b,int c,int d){
    if(H.x1<=a && a<=H.x2 && H.x1<=c && c<=H.x2 && H.y2<=b && b<=H.y1 && H.y2<=d && d<=H.y1)
    	return true;
    return false;
}
 
 
int main(){
    
    cin>>n;
    HCN H[n+5];
    for(int i=1;i<=n;i++){
        cin>>H[i].x1>>H[i].y1>>H[i].x2>>H[i].y2;
        u++;  X[u]=H[i].x1; Y[u]=H[i].y1;
        u++;  X[u]=H[i].x2; Y[u]=H[i].y2;
    }
    
    for(int i=1;i<u;i++)
    	for(int j=i+1;j<=u;j++){
   		 	if(X[i]>X[j]) swap(X[i],X[j]);
   		 	if(Y[i]>Y[j]) swap(Y[i],Y[j]);
   		 }
 
    		
    int S=0;
    for(int i=1;i<u;i++)
	    for(int j=1;j<u;j++){
	        for(int k=1;k<=n;k++)
	        if(KT(H[k],X[i],Y[j+1],X[i+1],Y[j])){
				S += (X[i+1]-X[i])*(Y[j+1]-Y[j]);
				break;
			}
	    }
	    
    cout<<S;
} 
