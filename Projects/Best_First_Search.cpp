#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Compare {
    bool operator()(pair<int, char> a, pair<int, char> b) {
        return a.first > b.first;
    }
};

void bestFirstSearch(unordered_map<char, vector<char>> &graph,
                     unordered_map<char, int> &heuristic,
                     char start, char goal) {
    priority_queue<pair<int, char>, vector<pair<int, char>>, Compare> pq;
    unordered_map<char, bool> visited;

    pq.push({heuristic[start], start});
    visited[start] = true;

    cout << "Path: ";

    while(!pq.empty())
    {
        char current = pq.top().second;
        pq.pop();
        cout<< current <<" ";
        if(current==goal)
        {
            cout<< "\nGoal Reached!"<<endl;
            return;
        }
        for(char neighbor : graph[current]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                pq.push({heuristic[neighbor],neighbor});
            }
        }
        
    }
    cout<< "\n No path found!"<<endl;
}

int main() {
    unordered_map<char, vector<char>> graph ={
        {'A',{'B','C'}},
        {'B',{'D','E'}},
        {'C',{'F'}},
        {'D',{}},
        {'E',{'F'}},
        {'F',{}}
    };
    unordered_map<char,int> heuristic = {
        {'A',6},{'B',4},{'C', 5},
        {'D',2},{'E',1},{'F',0}
    };
    char start  = 'A', goal = 'F';
    bestFirstSearch(graph,heuristic,start,goal);
    return 0;
}
