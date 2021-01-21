#include <bits/stdc++.h>
bool stop = false;
bool negativeCycle = false;
int distance[100];
int edges, nodes, start, finish;
int tracer[100]; //Trace the optimal from a node to another node.
std::vector<std::tuple<int,int,int>> edgList; //Edge list
void IOInit(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    freopen("graph.inp","r",stdin);
}

void graphRead(){ //Read the graph as a edge list.
    std::cin >> nodes >> edges >> start >> finish;
    int a, b, weight;
    for (int i = 0; i < edges; i++){
        std::cin >> a >> b >> weight;
        edgList.push_back({a,b,weight});
        edgList.push_back({b,a,weight});
    }
}

void BellmanFord(){ 
    for (int i = 1; i <= nodes; i++) distance[i] = 9999999; //Init every node has infinity distance
    distance[start] = 0; //except the start node
    for (int i = 1; i <= nodes - 1; i++){ //Bellman-Ford algo
        stop = true;
        //The boolean plays two roles.
        //1. It will stop the algorithm if it can not make any distances smaller
        //2. It can identify whether the graph has a negative cycle or not.
        for (auto e: edgList){
            int a, b, w;
            std::tie(a,b,w) = e; //unpack the tuple (other way, the edge)
            if (distance[b] > distance[a] + w){ //Check whether the algo can reduce the distance. 
                distance[b] = distance[a] + w;
                tracer[b] = a; //The optimal node to go to
                stop = false; //We should not stop the algorithm because it can reduce more
            }
        }
        if (i == nodes - 1){ //If the algo have to run fully, graph contains a negative cycle
            negativeCycle = true;
            return;
        }
        if (stop) return; //If there is a negative cycle, or the algo can't reduce anymore
    }
}

int main(){
    IOInit();
    graphRead();
    BellmanFord();
    if (negativeCycle){
        std::cout << "There is a negative cycle in this graph. \n";
    }
    else{
    if (distance[finish] == 9999999){ //If we can not reduce the distance to the finish node
            std::cout << "There aren't any from " << start << " to " << finish << ".\n";
        }
        else{ //Otherwise, we found a path
            std::cout << "Shortest path from " << start << " to " << finish << ": \n";
            std::cout << "With the cost: " << distance[finish] << "\n";
            while (start != finish){ //while we reach the finish node
                std::cout << finish << "<-";
                finish = tracer[finish]; //We trace to the best node to go to 
            }
            std::cout << start << "\n";
        }
    }
    
}