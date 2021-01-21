#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[100]; //an adjacency list for nodes
int nodes, edges;
bool visited[100] = {false}; //at first, you haven't visited any nodes

void IOInit(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("graph.inp","r",stdin);
}

void readGraph(){
    IOInit();
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++){
        int x, y;
        cin >> x >> y;
        adjList[x - 1].push_back(y - 1);
        adjList[y - 1].push_back(x - 1);
    }
}

void dfs(int s){
    if (visited[s]) return;
    visited[s] = true;
    cout << s + 1 << " ";
    for (auto x : adjList[s]){
        dfs(x);
    }
}

int main(){
    IOInit();
    readGraph();
    int count = 0;
    for (int i = 0; i < nodes; i++){
        if (visited[i] == false){
            count++;
            cout << count << ". : ";
            dfs(i);
            cout << "\n";
        }
    }
}