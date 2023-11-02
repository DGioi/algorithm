#include<bits/stdc++.h>
using namespace std;
int M[32][1000000]
int n;
int d[32][32];

unsigned int removeItem( unsigned int S, int i){
    //
    return S|(1<<i);
}
bool contains (unsigned int S, int j){
    //
    if((S>>i)>0) return true;
    return false;
}
void printSet(unsigned int S){
    for(int i=0;i<=31;i++){
        if(contains(S,i)) cout<<i<<" ";
    }
}
int TSP(int i , unsigned int S){
    if(S == 0){
        M[i][S]=d[i][1]
    }
}
int main(){
    unsigned int S=0xFFFFFFFF;

    S=removeItem(S,1);
    return 0;

}
