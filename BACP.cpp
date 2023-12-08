#include<bits/stdc++.h>
#define N 17
#define M 6

using namespace std;

int n,m;
int load[M];
int loadMin = INT_MAX;
int c[N], x[N];
int a[N][N];

bool Check(int v, int k)
{
    for(int i=1; i<k; i++)
	{
		if(a[i][k])
		{
			if(x[i]>=v) return false;
		}else if(a[k][i])
		{
			if(v>=x[i]) return false;
		}
	}
	return true;
}

int MAX(int* a, int* b)
{
	int j=0;
	for(int* i=a; i<=b; i++)
		if(*i>j) j=*i;
	return j;
}

void Solution()
{
	int maxLoad = MAX(&load[1], &load[m]);
	if(maxLoad < loadMin) loadMin = maxLoad;
}

void Try(int k)
{
	for(int v=1; v<=m ; v++)
	{
		if(Check(v, k))
		{
			x[k]=v;
			load[v]+=c[k];
			if(k==n) Solution();
			else{
				if(load[v]<loadMin) Try(k+1);
			}
			load[v]-=c[k];
		}
	}
}

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d",c+i);
    }
    for( int i=1; i<=n; i++){
        for( int j=1; j<=n; j++){
            scanf("%d",&a[i][j]);
        }
    }
}
int main()
{
	input();
	Try(1);
	printf("%d",loadMin);
	return 0;
}
