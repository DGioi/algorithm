#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
int n;
int k;
int a[maxN];
int AMIN[maxN][30];
int findMin(int f,int l){
    int amin=a[f];e
    for(int i=f+1;i<=l;i++){
        if(a[i]<amin) amin=a[i];
    }
    return amin;
}
void createAMIN(){
    for(int i=0;i<n;i++){
        for(int j=0;i+(1<<j)<n;j++){
             AMIN[i][j]=findMin(i,i+(1<<j));
        }
    }
    return ;
    }
int rmq(int f,int l){
    int d=l-f;
    int i=f,j=log2(d);
    int ans=a[f];

    while(1){
        if(ans>AMIN[i][j])
        ans=AMIN[i][j];
        d=d-(1<<j);
        i=i+(1<<j);
        if(d==0) break;
        j=log2(d);
    }
    return ans;

}
int main(){
    int sum=0;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    createAMIN();
    cin>>k;
    for(int i=0;i<k;i++){
        int first;
        int last;
        cin>>first>>last;
        sum=sum+rmq(first,last);
    }
    cout<<sum<<'\n';
    return 0;
}
