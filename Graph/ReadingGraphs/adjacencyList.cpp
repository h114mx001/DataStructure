#include <bits/stdc++.h>
using namespace std;
void IOInit(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}
int edges, nodes;
void readUnweightedGraph(){
    freopen("unWeighted.txt","r",stdin);
    cin >> nodes >> edges;
    vector<int> adj[nodes];
    for (int i = 0; i < edges; i++){
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    for (int i = 0; i < nodes; i++){
        cout << "Adjacency nodes of " << i+1 << " node: ";
        for (int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j] + 1 << " ";
        }
        cout << "\n";
    }
}
// void readWeightedGraph(){
//     freopen("weighted.txt","r",stdin);
//     int edges, nodes;
//     cin >> nodes >> edges;
//     vector<pair<int,int>> adj[nodes];
//     for (int i = 0; i < edges; i++){
//         int x, y, weight;
//         cin >> x >> y >> weight;
//         pair <int,int> temp;
//         temp = make_pair(y, weight);
//         adj[x-1].push_back(temp);
//         temp = make_pair(x,weight);
//         adj[y-1].push_back(temp);
//     }
//     for (int i = 0; i < nodes; i++){
//         cout << "Adjacency nodes of " << i+1 << " node: ";
//         for (int j = 0; j < adj[i].size(); j++){
//             cout << adj[i][j].first << "(" << adj[i][j].second << ")" << " ";
//         }
//         cout << "\n";
//     }
// }
void DFS(){

}
int main(){
    IOInit();
    cout << "Unweighted Graph: " << "\n\n";
    readUnweightedGraph();
    cout << "\n";
    // cout << "Weighted Graph: " << "\n\n";
    // readWeightedGraph();
}