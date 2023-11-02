#include<bits/stdc++.h>
using namespace std;
bool checkPhone(string s){
    if(s.length()!=10) return false;
    for(int i=0;i<s.length();i++){
        if(s[i]<0||s[i]>9) return false;
    }
    return true;
}
int countTime(string ftime,string   etime){
    int startTime=((ftime[0]-'0')*10+ftime[1]-'0')*3600+60*((ftime[3]-'0')*10+ftime[4]-'0')+((ftime[6]-'0')*10+ftime[7]-'0');
    int endTime=((etime[0]-'0')*10+etime[1]-'0')*3600+60*((etime[3]-'0')*10+etime[4]-'0')+((etime[6]-'0')*10+etime[7]-'0');
    return  endTime-startTime;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string type;
    map<string,int > numberCall,timeCall;
    int totalCalls=0;
    int incorrectPhone=0;
    string fnum,tnum,date,ftime,etime;
    do{
        cin>>type;
        if(type=="#") break;
        cin>>fnum>>tnum>>date>>ftime>>etime;
        if(!checkPhone(fnum)||!checkPhone(tnum)) ++incorrectPhone;
        ++totalCalls;
        numberCall[fnum]++;
        timeCall[fnum]+=countTime(ftime,etime);

    }
    while(1)
    while(1){
        cin>>type;
        if(type=="#") break;
        if(type=="?check_phone_number") {
            if(incorrectPhone)cout<<0<<endl; else cout<<1<<endl;
        }
        if(type=="?number_calls_from"){
            string phone;
            cin>>phone;
            cout<<numberCall[phone]<<endl;
        }
        else
        if(type=="?number_total_calls")
            cout<<totalCalls<<endl;

        else
        if(type=="?count_time_calls_from")
        {
            string phone;
            cin>>phone;
            cout<<timeCall[phone]<<endl;
        }
    }
    return 0;
    }
