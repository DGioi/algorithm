#include<bits/stdc++.h>
using namespace std;
int n,m;
int Matrix[1000][1000];
int A[1000];
stack<int> S;
int maxArea=0;
int area=0;
void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Matrix[i][j];
        }
    }
}
void setA(){
    for(int i=0;i<m;i++) A[i]=0;
}
void makeA(int i){
    for(int j=0;j<m;j++){
        if(Matrix[i][j]==0){
            A[j]=0;
        }
        else{
            A[j]+=1;
        }
    }


}
void maxHistogram(){
    int i;
    for( i=0;i<m;){
        if(S.empty()||A[S.top()]<=A[i]){
            S.push(i++);
        }
        else{
            int e=S.top(); S.pop();
            if(S.empty()){
                area=A[e]*i;
            }
            else{
                area=A[e]*(i-S.top()-1);
            }
            if(area>maxArea){
                maxArea=area;
            }
        }
    }
    while(!S.empty()){
            int e=S.top(); S.pop();
            if(S.empty()){
                area=A[e]*i;
            }
            else{
                area=A[e]*(i-S.top()-1);
            }
            if(area>maxArea){
                maxArea=area;
            }
    }
    return;
}
void largestBlack(){
    for(int i=0;i<n;i++){
        makeA(i);
        maxHistogram();
    }
}
 int main(){
    input();
    largestBlack();
    cout<<maxArea<<"\n";
    return 0;

 }
