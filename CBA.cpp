#include<bits/stdc++.h>
using namespace std;
#define N 40
#define M 20
bool A[M][N];
bool Conflict[N][N];
int m,n;
int load[M];
int maxload=0;
int cmaxload=0;
int lcmaxload=0;
int x[N];
int res=30;
void solution(){
    for(int i=0;i<m;i++){
        cout<<load[i]<<" ";
    }
    cout<<endl;
}
int findmaxload(){
    int lmax=0;
    for(int i=0;i<m;i++){
        if(load[i]>lmax)
            lmax=load[i];
    }
    return lmax;
}
void input(){
    cin>>m>>n;
    for( int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            A[i][j]=false;
        }
    }
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        load[i]=0;
        for(int j=0;j<t;j++){
            int d;
            cin>>d;
            A[i][d-1]=true;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            Conflict[i][j]=false;
        }

    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int x,y;
        cin>>x>>y;
        Conflict[x-1][y-1]=true;
        Conflict[y-1][x-1]=true;
    }

}
bool check(int v,int k){
    if(!A[v][k]) return false;
    for(int i=0;i<k;i++){
        if(x[i]==v)
        if(Conflict[i][k]){
            return false;
        }
    }
    return true;
}
void Try(int k){
    for(int v=0;v<m;v++){
        if(check(v,k)){
            x[k]=v;
            load[v]++;
            if(load[v]>cmaxload) {
                lcmaxload=cmaxload;
                cmaxload=load[v];
            }
            if(k==n-1){
//                maxload=findmaxload();
                if(res>cmaxload)  res=cmaxload;
//                cmaxload=0;
            }
            else if( cmaxload<res){
                Try(k+1);
            }
            if(load[v]>lcmaxload) {
                cmaxload=lcmaxload;
            }
            load[v]--;
        }
    }

}
int main(){
    input();
    Try(0);
    cout<<res;
    return 0;

}
