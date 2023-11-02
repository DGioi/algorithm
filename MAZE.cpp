#include<bits/stdc++.h>
using namespace std;
    typedef pair<int,int> ii;
    int n;  // n so hang
    int m;  // m la so cot
    int r;  // hang xuat phat
    int c;  // cot xuat phat
    const int maxN=999;
    int a[maxN][maxN];  // luu ma tran
    int steps[maxN][maxN]; //luu quang duong di toi 1 diem
    queue<ii> Q;
    int dx[]={1,0,-1,0}; // luu cac huong di chuyen
    int dy[]={0,-1,0,1};
int BFS(){
    Q.push(ii(r,c));
    a[r][c]=1;
    steps[r][c]=0;
    while(!Q.empty()){
        ii currentNode=Q.front(); Q.pop();
        for(int i=0;i<4;i++){
        int x=currentNode.first+dx[i];
        int y=currentNode.second+dy[i];
        if(x<0||y<0||x>=n||y>=m) return steps[currentNode.first][currentNode.second]+1;
        if(!a[x][y]){
            Q.push(ii(x,y));
            steps[x][y]=steps[currentNode.first][currentNode.second]+1;
            a[x][y]=1;
        }
    }
    }
    return -1;
    }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>r>>c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    r=r-1;
    c=c-1;
    if(a[r][c]==1) cout<<-1<<'\n';
    else
    cout<<BFS()<<'\n';
    return 0;
}
