#include <bits/stdc++.h>
using namespace std;

#define pop2 y = calcStack.top(); calcStack.pop(); x = calcStack.top(); calcStack.pop();

void IOInit(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("task.inp","r",stdin);
}

vector <string> converter(string raw){
    string text = raw;
    regex rgx(R"([0-9]+|[*-\/+()])");
    smatch m;
    vector <string> list;
    while(regex_search(text,m,rgx)){
        for (auto x : m) list.push_back(x.str());
        text = m.suffix().str();
    }
    return list;
}

int Priority(string s){
    int x;
    if (s == "*" || s == "/") x = 2;
        else if (s == "+" || s == "-") x = 1;
            else if (s == "(") x = 0;
    return x;
}

vector <string> processString(string text){
    string raw = text;
    smatch m;
    regex rgx(R"([0-9]+|[\/*+-])");
    vector <string> list;
    while (regex_search(raw,m,rgx)) {
      for (auto x : m){
          list.push_back(x.str());
      }
      raw = m.suffix().str();
    }
    return list;
}

int main(){

    //infix => RPN

    stack <string> processor;
    IOInit();
    string text; 
    getline(cin, text);
    string k;
    string RPNformula = "";
    vector <string> list = converter(text);
    for (int i = 0; i < list.size(); i++){
        if (list[i] == "("){
            processor.push(list[i]);
        } else if (list[i] == ")"){
            string k = "";
            while (k != "("){
                k = processor.top();
                processor.pop();
                if (k != "(") RPNformula += (k + " ");
            }
        } else if (list[i] == "+" || list[i] == "-" || list[i] == "*" || list[i] == "/"){
            while (!processor.empty() && Priority(list[i]) <= Priority(processor.top())){
                RPNformula += (processor.top() + " ");
                processor.pop();
            }
			processor.push(list[i]);
        }
        else RPNformula+= (list[i] + " ");
    }
    while (!processor.empty()){
        RPNformula += (processor.top() + " ");
        processor.pop();
    }

    //RPN => calculate

    stack <int> calcStack;
    string raw;
    raw = RPNformula;
    int x, y;
    vector <string> processed = processString(raw);
    for (int i = 0; i < processed.size(); i++){
        if (processed[i] == "+"){ 
            pop2;
            calcStack.push(x+y);
        }
        else if (processed[i] == "-"){
            pop2;
            calcStack.push(x-y);
        }
        else if (processed[i] == "*"){
            pop2;
            calcStack.push(x*y);
        }
        else if (processed[i] == "/"){
            pop2;
            calcStack.push(x/y);
        }
        else{
            int x = stoi(processed[i]);
            calcStack.push(x);
        }
    }
    cout << text << " = " << calcStack.top() << "\n";
}