#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int cnt=1;
int n;
pii last;
priority_queue<pii, vector<pii>, greater<pii>>PQG;
void input(){
    cin>>n;
    for(int  i =0;i<n;i++){
            pii e;
            cin>>e.second>>e.first;
            PQG.push(e);
    }
}
int thamlam(){
    last=PQG.top(); PQG.pop();
    while(!PQG.empty()){
        pii e=PQG.top(); PQG.pop();
        if(e.second>last.first){
            last=e;
            cnt++;
        }
    }
    return cnt;

}
int main(){
    input();
    cout<<thamlam();
    return 0;
}
