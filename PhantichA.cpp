#include<bits/stdc++.h>
using namespace std;
int kq[5];
int g=-1;
int M[]={2,3};
int n=2;
int x=1e9;
void exchange(int A,int k){
	int i;
	for(i=0;i<n;i++){
		if(A-M[i]>=0){
			kq[i]++;
			A=A-M[i];
			if(A==0){
                    cout<<"[";
                    for(i=0;i<n;i++)
                    cout<<kq[i]<<" ";
                    cout<<"]"<<endl;
                    g=1;
			}
			else
                if(k<100){
				exchange(A,k+1);
                }
			A=A+M[i];
			kq[i]--;
		} else return;

	}

}
int addx(){

    return 0;
}
int main(){
    int v=0;
	int A; cin>>A;
	exchange(A,0);
	if(g==-1){
        cout<<addx();
	}
	return 0;
}
