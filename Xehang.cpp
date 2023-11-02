#include<bits/stdc++.h>
using namespace std;
#define N 100
int n,K,Q;
int d[N]; //
int c[N][N];
//solution model
int Y[N];
int X[N];
int  load[N];
int f; // distance accumulated
int f_min;// min-distance found
bool visited[N];
int nbSegment;
void input(){
    cin>>n>>K>>Q;
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
        cin>>c[i][j];
        }
    }
}
bool checkY(int v, int k){
    if(visited[v]) return false;
    if(load[k]+d[v]>Q) return false;
    return true;

}
void solution(){
    if(f<f_min){
        f_min=f;
        cout<<"Update best"<<f_min<<endl;
    }
}
bool checkX(int v,int i,int k){
    if(v==0) return true;
    if(visited[v]) return false;
    if(load[k]+d[v]>Q) return false;
    return true;
}
void TryX(int i,int k){
    for(int v=0;v<n;v++){
        if(checkX(v,i,k)){
                X[i]=v;visited[v]=true;
                f=f+c[i][X[i]]; load[k]+=d[v];
                nbSegment++;
                if(v==0){
                    if(k<K) TryX(Y[k+1],k+1);
                    else {
                        if(nbSegment==n+k) solution();
                    }
                }else{
                    TryX(v,k);
                }
            nbSegment--;
            visited[v]=false;
            f=f-c[i][v];
        }
    }
}
void TryY(int k){
    for(int v=Y[k-1]+1;v<=n-K+k;v++){
        if(checkY(v,k)){
            Y[k]=v; visited[v]=true;
            f=f+c[0][v];
            load[k]+=d[v];
            nbSegment+=1;
            if(k=K) TryX(Y[1],1);
            else TryY(k+1);
            visited[v]=false;
            f=f-c[0][Y[k]];
            load[k]-=d[v];
            nbSegment-=1;
        }
    }
}
int main(){
    input();
    for(int v=1;v<=n;v++) visited[v] = false;
    for(int k=1;k<K;k++) load[k]=0;
    f=0;f_min=1e9;nbSegment=0;
    Y[0]=0;
    TryY(1);
    cout<<f_min;
    return 0;
}
