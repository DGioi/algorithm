#include<bits/stdc++.h>
using namespace std;
void demomap() {
    map<string,int>    M;
    int     i=0;
    bool    startWord=false;
    bool    endchar=false;
    char    word[50];
    char    k;
    while(true){
        k=fgetc(stdin);
        if(k<='z'&&k>='a'||k<=9&&k>=0){
            if(!startWord) startWord= true;
                i++;
                word[i-1]=k;
            }
            else {
            if(startWord){
                    word[i]='\0';
                    M[word]++;
                    i=0;
                    startWord=false;
            }else {
                if(k=='\n') {
                    if(endchar) break;
                    endchar=true;
                    continue;
                }

            }
            }
            endchar=false;
    }
	for ( map<string,int>::iterator p = M.begin(); p != M.end(); p++) {
		cout << p->first << " " << p->second << endl;
	}
}
int main(){
    demomap();
    return 0;
}
