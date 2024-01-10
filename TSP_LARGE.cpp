#include<bits/stdc++.h>
#define N 1001
using namespace std;

int n;
int a[N][N];
bool visited[N];

void greedyTSP() {
    vector<int> path;
    visited[1] = true;
    path.push_back(1);

    int currentNode = 1;

    for (int i = 1; i < n ; i++) {
        int nextNode;
        int minDistance = INT_MAX;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && a[currentNode][j] < minDistance) {
                minDistance = a[currentNode][j];
                nextNode = j;
            }
        }
        currentNode = nextNode;
        visited[currentNode] = true;
        path.push_back(currentNode);
    }

    // Return to the start node
    path.push_back(0);

    // Print the path
    for (int i = 0; i < path.size()-1; i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main() {
    // Assume that the adjacency matrix a[][] is already filled
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("data.txt","r",stdin);

    cin>>n;
    cout<<n<<endl;
    for(int i = 1; i <= n; i++){ 
        for(int j = 1; j <= n; j++){
            cin>> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    greedyTSP();
    return 0;
}