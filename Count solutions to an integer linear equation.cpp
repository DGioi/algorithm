#include<bits/stdc++.h>
using namespace std;
#define N 100
int n;
int M;
int x[N];
int a[N];
int suma=0;
int cnt=0;
void printsolution(){
    int i;
    for(i=0;i<n-1;i++)
        cout<<x[i]<<" ";
        cout<<x[i]<<endl;
}
void Try(int k){
    for(int i=1;i<=(M-(n-suma-1))/a[k]+1;i++){
            x[k]=i;
            M=M-x[k]*a[k];
            suma-=a[k];
            if(k==n-1){
                if(M==0) {
                   // printsolution();
                    cnt++;
                }
            }
            else{
                Try(k+1);
            }
            suma+=a[k];
            M=M+x[k]*a[k];
    }
}
int main(){
    cin>>n>>M;
    for(int i=0;i<n;i++){
        cin>>a[i];
        suma+=a[i];
    }
    Try(0);
    cout<<cnt;
    return 0;
}
