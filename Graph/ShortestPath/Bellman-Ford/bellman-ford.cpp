#include <bits/stdc++.h>
bool stop = false;
int distance[100];
int edges, nodes, start, finish;
int tracer[100];
std::vector<std::tuple<int,int,int>> edgList;
void IOInit(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    freopen("graph.inp","r",stdin);
}

void graphRead(){
    std::cin >> nodes >> edges >> start >> finish;
    int a, b, weight;
    for (int i = 0; i < edges; i++){
        std::cin >> a >> b >> weight;
        edgList.push_back({a,b,weight});
        edgList.push_back({b,a,weight});
    }
}

void BellmanFord(){
    for (int i = 1; i <= nodes; i++) distance[i] = 9999999;
    distance[start] = 0;
    for (int i = 1; i <= nodes - 1; i++){
        stop = true;
        for (auto e: edgList){
            int a, b, w;
            std::tie(a,b,w) = e;
            if (distance[b] > distance[a] + w){
                distance[b] = distance[a] + w;
                tracer[b] = a;
                stop = false;
            }
        }
        if (stop) return;
    }
}

int main(){
    IOInit();
    graphRead();
    BellmanFord();
    if (stop == false){
        std::cout << "There is a negative cycle in this graph. \n";
    }
    else{
    if (distance[finish] == 9999999){
            std::cout << "There aren't any from " << start << " to " << finish << ".\n";
        }
        else{
            std::cout << "Shortest path from " << start << " to " << finish << ": \n";
            while (start != finish){
                std::cout << finish << "<-";
                finish = tracer[finish];
            }
            std::cout << start << "\n";
        }
    }
    
}