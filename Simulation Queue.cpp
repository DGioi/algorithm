#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int> Q;
    while(true){
    string cmd; cin>>cmd;
    if(cmd=="#") return 0;
    if(cmd=="PUSH"){
        int k; cin>>k;
        Q.push(k);
    }else{
        if(Q.empty()){
        cout<<"NULL"<<endl;
        } else{
        int e=Q.front();
        Q.pop();
        cout<<e<<endl;
        }
    }
    }
    return 0;
}
