#include "graph.h"

vector<int> graph :: minEdge(){

    int min_weight = INT_MAX, val;
    vector<int> min_location;

    for(int i = 0; i < matrix_size - 1; i++){
        for(int j = i + 1; j < matrix_size; j++){
            val = this->adj_matrix[matrix_size * i + j];
            if(val != 0 && val < min_weight){
                min_weight = val;
                min_location.clear();
                min_location.push_back(min_weight);
                min_location.push_back(i);
                min_location.push_back(j);
            }
        }
    }
    this->adj_matrix[matrix_size * min_location[1] + min_location[2]] = 0;
    this->adj_matrix[matrix_size * min_location[2] + min_location[1]] = 0;

    return min_location;
}

void graph :: addEdge(int weight, int node_1, int node_2){

    min_span_tree[node_1 * matrix_size + node_2] = weight;
    min_span_tree[node_2 * matrix_size + node_1] = weight;
}

void graph :: kruskal(){

    int num, node1, node2, weight, total = 0;
    vector<int> min_edge;

    initSomeValues(0);

    for(int i = 0; i < matrix_size * matrix_size; i++) min_span_tree.push_back(0);
       
    for(int i = 0; i < matrix_size - 1;){
        
        min_edge = minEdge();
        weight = min_edge[0]; node1 = min_edge[1]; node2= min_edge[2];

        nodeStack(min_span_tree, node1); 

        while(!stacked_nodes.empty() && isCycle == 0){
            num = stacked_nodes.back();
            stacked_nodes.pop_back();
            nodeStack(min_span_tree, num, node2);
        }

        if(isCycle == 0){
            addEdge(weight, node1, node2);
            total += weight;
            i++;
        }
        else isCycle = 0;

        initSomeValues(1);
        stacked_nodes.clear();
    }

    cout << "Spanning Tree Adjacency Matrix" << endl;
    printMatrix(min_span_tree);
    cout << "Minimum Spanning Tree Weight: " << total << endl;
    
    visited_nodes.clear();
    isStacked.clear();
    stacked_nodes.clear();
}


int main(){

    int size;

    cout << "enter the node amount: " << endl;
    cin >> size;
    graph g1 = graph(size, 'w');
    g1.kruskal();

    return 0;
}