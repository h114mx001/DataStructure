#include <bits/stdc++.h>
using namespace std;
int main(){
    vector <int> list{2, 4, 5, 6};
    list.erase(list.begin(), list.end());
    if (list.empty()){
        cout << "Het roi";
    }
}