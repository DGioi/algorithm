#include<bits/stdc++.h>
using namespace std;
#define N 23
int n;
int capacity;
int c[N][N];
bool visited[N];
int x[N];
int fMin=1e9;
int cmin=1e9;
int fcur=0;

void input(){
    cin>>n>>capacity;
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            cin>>c[i][j];
            if(i!=j) cmin=min(cmin,c[i][j]);
        }
    }
}
void fcmin(){
    cmin=c[0][1];
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(c[i][j]<cmin) cmin=c[i][j];
        }
    }
}
bool check(int v,int k){

    if(visited[v]) return false;
    if(v<=n&&capacity==0) return false;
    if(v>n&&!visited[v-n]) return false;
   // if(c[x[k-1]][v]+fcur+(2*n-k+1)*cmin>fMin) return false;
    return true;

}
void Try(int k){
    for(int v=1;v<=2*n;v++){
        if(check(v,k)){
            x[k]=v;
            visited[v]=true;
            fcur+=c[x[k-1]][v];
            if(v<=n) capacity--;
            else capacity++;
            if(k==2*n){
                if(fcur+c[x[k]][0]<fMin){
                    fMin=fcur+c[x[k]][0];
                }
            }
            else{
                if(cmin*(2*n-k+1)+fcur<fMin)
                    Try(k+1);
            }
            if(v<=n) capacity++;
            else capacity--;
            fcur-=c[x[k-1]][v];
            visited[v]=false;
        }
    }
}
int main(){
    for(int i=0;i<=2*n;i++) visited[i]=false;
    input();
    x[0]=0;
   // fcmin();
    Try(1);
    cout<<fMin;
    return 0;
}
