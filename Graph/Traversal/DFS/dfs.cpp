#include <bits/stdc++.h>
using namespace std;
void IOInit(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("graph.inp","r",stdin);
}

vector<int> adjList[100];

bool notVisited[100] = {false};

void readGraph(){
    IOInit();
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++){
        int x, y;
        cin >> x >> y;
        adjList[x - 1].push_back(y - 1);
        adjList[y - 1].push_back(x - 1);
    }
    for (int i = 0; i < nodes; i++){
        cout << "Adjacency nodes of " << i+1 << " node: ";
        for (int j = 0; j < adjList[i].size(); j++){
            cout << adjList[i][j] + 1 << " ";
        }
        cout << "\n";
    }
}

void dfs(int s){
    if (notVisited[s] == true) return;
    notVisited[s] = true;
    cout << s << " ";
    for (auto u: adjList[s]){
        dfs(u);
    }
}

int main(){
    readGraph();
    dfs(0);    
}