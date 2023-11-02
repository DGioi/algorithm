#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
int n;
int a[maxN];
int AMIN[30][1000000];
void createAMIN(){
    for( int i=0;i<n-1;i++){
        AMIN[0][i]=a[i];
        if(a[i]<=a[i+1]) AMIN[1][i]=a[i];
        else AMIN[1][i]=a[i+1];
    }
    AMIN[0][n-1]=a[n-1];
    AMIN[1][n-1]=a[n-1];
        for(int j=2;j<=log2(n);j++){
            for(int i=0;i<n+1-(1<<j);i++){
            if(AMIN[j-1][i]<AMIN[j-1][i+(1<<(j-1))]) AMIN[j][i]=AMIN[j-1][i];
            else AMIN[j][i]=AMIN[j-1][i+(1<<(j-1))];
        }
        }
    return ;
}
int rmq(int i,int j){
    int d=j-i+1;
    int k=log2(d);
    if(AMIN[k][j-(1<<k)+1]>AMIN[k][i])
    return AMIN[k][i];
    else return AMIN[k][j-(1<<k)+1];
}
int main(){
    int sum=0;
    int k;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    createAMIN();
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int first;
        int last;
        scanf("%d %d",&first,&last);
        sum+=rmq(first,last);
    }
    printf("%d\n",sum);
    return 0;
}

