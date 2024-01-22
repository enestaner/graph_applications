#include "graph.h"

int main(){

    int size;

    cout << "Enter the node amount: " << endl;
    cin >> size;

    if(size > 0){
        graph g1 = graph(size, 'r');
        g1.printMatrix(g1.adj_matrix);
    }
    else cout << "Error" << endl;

    return 0;
}