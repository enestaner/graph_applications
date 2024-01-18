#include "graph.h"

int graph :: leastLeaf(){

    int leaf = INT_MAX, temp;

    for(int i = 0; i < matrix_size; i++){
        temp = 0;

        for(int j = 0; j < matrix_size; j++){
            temp += this->adj_matrix[i * matrix_size + j];
        }
        if(temp == 1 && i < leaf)
        leaf = i;
    }

    return leaf;
}

void graph :: removeNode(int label){

    for(int i = 0; i < matrix_size; i++){
        this->adj_matrix[label * matrix_size + i] = 0;
        this->adj_matrix[i * matrix_size + label] = 0;
    }
}

int graph :: findAdjacent(int node){

    int adj;

    for(int i = 0; i < matrix_size; i++){
        if(this->adj_matrix[node * matrix_size + i] == 1){
            adj = i;
            break;
        }
    }
    return adj;
}

void graph :: findPrufer(){

    int least, adjacent;
    vector<int> prufer;

    for(int i = 0; i < matrix_size - 2; i++){
        least = leastLeaf();
        cout << "least: " << least + 1 << endl;
        adjacent = findAdjacent(least);
        cout << "adj " << adjacent + 1 << endl;
        prufer.push_back(adjacent + 1);
        removeNode(least);
    }

    cout << "Prufer: ";
    for(int i = 0; i < matrix_size - 2; i++)
    cout << prufer[i];

}

void graph :: pruferDecoder(){

    vector<int> prufer, prufer_check, all_nodes, last_nodes;
    int pf_size = matrix_size - 2, num;

    for(int i = 0; i < pf_size + 2; i++){
        prufer_check.push_back(0);
        all_nodes.push_back(i);
    }

    for(int i = 0; i < pf_size; i++){
        cout << "enter the " << i + 1 << ". number of the code: " << endl;
        cin >> num;
        prufer.push_back(num);
        prufer_check[num - 1] += 1;
    }

    for(int i = 0; i < pf_size; i++){

        for(int j = 0; j < matrix_size; j++){

            if(all_nodes[j] >= 0){
                if(prufer_check[all_nodes[j]] == 0){
                    this->adj_matrix[(prufer[i] - 1) * matrix_size + all_nodes[j]] = 1;
                    this->adj_matrix[all_nodes[j] * matrix_size + prufer[i] - 1] = 1;
                    all_nodes[j] = -1;
                    prufer_check[prufer[i] - 1] -= 1;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < matrix_size; i++){
        if(all_nodes[i] != -1)
        last_nodes.push_back(all_nodes[i]);
    }

    this->adj_matrix[last_nodes[0] * matrix_size + last_nodes[1]] = 1;
    this->adj_matrix[last_nodes[1] * matrix_size + last_nodes[0]] = 1;

    printMatrix(this->adj_matrix);
}


int main(){

    int size;

    // LABELED TREE - PRUFER
    cout << "Enter the node amount:" << endl;
    cin >> size;
    graph g1 = graph(size, 't');
    g1.printMatrix(g1.adj_matrix);
    g1.findPrufer();

    //PRUFER - LABELED TREE
    cout << endl << "enter the length of prufer" << endl;
    cin >> size;
    graph g2 = graph(size+2, 'o');
    g2.pruferDecoder();

    return 0;
}