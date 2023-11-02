#include<bits/stdc++.h>
using namespace std;
int n;
int M;
int A[10];
void printsolution(){
    int i;
    for(i=0;i<n-1;i++)
        cout<<A[i]<<" ";
        cout<<A[i]<<endl;
}
void Try(int k){
    for(int i=1;i<=M-(n-k-1)+1;i++){
            A[k]=i;
            M=M-A[k];
            if(k==n-1){
                if(M==0) printsolution();
            }
            else{
                Try(k+1);
            }
            M=M+A[k];
    }
}
int main(){
    cin>>n>>M;
    Try(0);
    return 0;
}
