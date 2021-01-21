#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[100]; //an adjacency list for nodes
int nodes, edges, start, target;
bool notVisited[100] = {false}; //at first, you haven't visited any nodes
vector <int> roads; // this use to store roads

void IOInit(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("map.inp","r",stdin);
}

void printRoad(){  //print the roads if we find one.
    for (int i = 0; i < roads.size() - 1; i++){
        cout << roads[i] + 1 << " => ";
    }
    cout << roads[roads.size()-1] + 1 << "\n";
}

void readGraph(){
    IOInit();
    cin >> nodes >> edges >> start >> target;
    for (int i = 0; i < edges; i++){
        int x, y;
        cin >> x >> y;
        adjList[x - 1].push_back(y - 1);
        adjList[y - 1].push_back(x - 1);
    }
}

void dfs(int s){
    if (notVisited[s] == true){ //if this node is visited, you can't visit it again.
        return;
    }
    // otherwise, there are 2 cases if a node is not visited yet:
    else if (s == target - 1){ // +First, it is the target we want to reach
        roads.push_back(s);     // add it in to the path.
        printRoad();            // print the path.
        roads.pop_back();       // remove the target node, for another paths
    }
    else{                       // +Second, it isnt the target, so we have to continue searching
        notVisited[s] = true;   //this node is visited
        roads.push_back(s);     //add it in to the path
        for (auto u: adjList[s]){   //visit another adjacency nodes of it
            dfs(u);
        }
        roads.pop_back();       // regardless you complete the path or not, you must remove visited nodes for continuing searching
        notVisited[s] = false;
    }
}

int main(){
    readGraph();
    cout << "Moves from " << start << " to " << target << ": \n";
    dfs(start - 1);    //start with the "start" node.
}

