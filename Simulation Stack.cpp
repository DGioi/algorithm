#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> S;
    while(true){
    string cmd; cin>>cmd;
    if(cmd=="#") return 0;
    if(cmd=="PUSH"){
        int k; cin>>k;
        S.push(k);
    }else{
        if(S.empty()){
        cout<<"NULL"<<endl;
        } else{
        int e=S.top();
        S.pop();
        cout<<e<<endl;
        }
    }
    }
    return 0;
}
