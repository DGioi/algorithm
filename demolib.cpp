#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
void demostack() {
	stack<int> S;
	for (int i = 1; i <= 5; i++) {
		S.push(i);
		cout << "PUSH" << i << endl;
		S.push(i);
	}
	while(!S.empty()) {
		int e = S.top();
		S.pop();
		cout << "POP" << e << endl;
	}
}
void demoqueue() {

	//demo queue
	queue<int> Q;
	for (int e = 1; e <= 5; e++) {
		Q.push(e);
		cout << "QUEUE PUSH" << e << endl;

	}
	while (!Q.empty()) {
		int e = Q.front();
		Q.pop();
		cout << "Queue pop" << e << endl;
	}

}

void demomap() {
	map<string, int>	M;
	M["abc"] = 4;
	for (map<string, int>::iterator p = M.begin(); p != M.end(); p++) {
		cout << p->first << "value of key" << p->second << endl;
	}
	string k = "abc";
	cout << "value of key" << k << "=" << M[k] << endl;
}
void demoPriorityQueue() {
	/* Moi phan tu trong queue co 1 truong thong tin la khoa khi lay mot phan tu
	* ra khoi queue thi uu tien phan tu co khoa lon nhat hoac nho nhat
	*/
	priority_queue<int> pq;
	pq.push(5);
	pq.push(1);
	pq.push(100);
	pq.push(30);
	while (!pq.empty()) {
		int e = pq.top(); pq.pop();
		cout << "pq.pop" << e << endl;
	}
	priority_queue<pii, vector<pii>, greater<pii>>PQ;
	PQ.push(make_pair(4, 40));
	PQ.push(make_pair(1, 10));
	PQ.push(make_pair(9, 900));
	while (!PQ.empty()) {
		pii e = PQ.top(); PQ.pop();
		cout << "PQ.pop (" << e.first <<"," <<e.second<<")"<<endl;
	}
}

int main() {
	demoPriorityQueue();
	return 0;
}
