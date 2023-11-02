#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int n;
int t;
int k;
int a[MAX];
bool check (int distance){
    int count = 1;
    int i=1, last = 2;
    while(i<n){
        while(last<=n && a[last]-a[i]<distance) ++last;
        if(last<=n) count++;
        if(count >=k) return true;
        i=last;
        last++;
    }
    return false;
}
int MaxDistance(){
    int l=0, r=a[n]-a[1];
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid))) l=mid+1;
        else r=mid-1;
    }
    return r;

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sort(a+1,a+n+1)
            cout<<MaxDistance()<<endl;
        }
    }
}
