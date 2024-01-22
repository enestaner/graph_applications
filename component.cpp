#include "graph.h"

int graph :: anyNonVisited(vector<int> visited){

    for(int i = 0; i < matrix_size; i++){
        if(visited[i] == -1)
        return 1;
    }
    return 0;
}

void graph :: countComponents(){

    int num;

    initSomeValues(0);
        
    for(int i = 0; anyNonVisited(visited_nodes); i++){
        
        nodeStack(adj_matrix, i);

        while(!stacked_nodes.empty() && isCycle == 0){
            num = stacked_nodes.back();
            stacked_nodes.pop_back();
            nodeStack(adj_matrix, num);
        }
    }

    visited_nodes.clear();
    isStacked.clear();
    stacked_nodes.clear();
}

int main(){

    int size;

    cout << "Enter the node amount: " << endl;
    cin >> size;

    if(size > 0){
        graph g1 = graph(size, 'w');
        g1.printMatrix(g1.adj_matrix);
        g1.countComponents();
        cout << "Component Count: " << g1.components << endl;
    }
    else cout << "Error" << endl;

    return 0;
}