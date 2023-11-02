#include<bits/stdc++.h>
using namespace std;
#define N 20
int n;
int c[N][N];
bool visited[N];
int x[N];
int fMin;
int cmin;
int fcur=0;
unsigned long long cnt=0;
void input(){
    cin>>n;
    int i;
    int j;
    for(i=1;i<=n-1;i++){
        for(j=1;j<=n;j++){
            cnt++;
            cin>>c[i][j];
            fMin+=c[i][j];
        }
    }
    for(j=1;j<=n;j++){
            cnt++;
            cin>>c[i][j];
        }

}
void fcmin(){
    int cmin=c[1][2];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
                cnt++;
                if(c[i][j]<cmin) cmin=c[i][j];}

    }
}
bool check(int v,int k){
    if(visited[v]) return false;
    if(c[x[k-1]][v]+fcur+(n-k+1)*cmin>fMin) return false;
    return true;
}
void Try(int k){
    int v;
    for(v=2;v<=n;v++){
        if(check(v,k)){
            cnt++;
            x[k]=v;
            visited[v]=true;
            fcur=fcur+c[x[k-1]][x[k]];
            if(k==n){
                if(fMin>fcur+c[x[k]][1]) fMin=fcur+c[x[k]][1];
            }
            else{
                if(cmin*(n-k+1)<fMin)
                Try(k+1);
            }
            visited[v]=false;
            fcur=fcur-c[x[k-1]][x[k]];

        }
    }

}
int main(){
    for(int v=2;v<=n;v++) visited[v] = false;
    input();
    x[1]=1;
    Try(2);
    cout<<fMin<<endl;
    cout<<cnt;
    return 0;
}
