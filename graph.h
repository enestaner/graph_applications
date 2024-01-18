#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class graph{

    int matrix_size;

    public:
        int components, isCycle = 0;
        vector<int> adj_matrix, visited_nodes, stacked_nodes, isStacked, min_span_tree;

        graph(int size, char type);
        void zeroMatrix(int size);
        void printMatrix(vector<int> matrix);
        void initSomeValues(int type);

        void countComponents();
        int anyNonVisited(vector<int> visited);
        void nodeStack(vector<int> matrix, int node, int min_weight = -2);

        int leastLeaf();
        void removeNode(int label);
        void findPrufer();
        int findAdjacent(int node);
        void pruferDecoder();

        vector<int> minEdge();
        void addEdge(int weight, int node_1, int node_2);
        void kruskal();
};

vector<int> createSequence(int size);
void printSequence(vector<int> seq);
int isGraphic(vector<int> seq);

graph :: graph(int size, char type){

    this->matrix_size = size;
    this->components = size;
    int num;

    zeroMatrix(matrix_size);

    if(type == 'w'){
        vector<int> weights;

        cout << "Enter the upper triangular of matrix" << endl << endl;
        for(int i = 0; i < ((size - 1) * size) / 2; i++){
            cout << "Enter " << i+1 << ". weight: ";
            cin >> num;
            cout << endl;
            weights.push_back(num);
        }

        for(int i = 0, k = 0; i < matrix_size-1; i++){
            for(int j = i + 1; j < matrix_size; j++, k++){
                this->adj_matrix[matrix_size * i + j] = weights[k];
                this->adj_matrix[matrix_size * j + i] = weights[k];
            }
        }
    }
    else if(type == 'r'){
        srand(time(NULL));

        for(int i = 0, k = 0; i < matrix_size-1; i++){
            for(int j = i + 1; j < matrix_size; j++, k++){
                num = rand() % 2;
                this->adj_matrix[matrix_size * i + j] = num;
                this->adj_matrix[matrix_size * j + i] = num;
            }
        }
    }
    else if(type == 't'){
        vector<int> labels;
        int amount, num;

        for(int i = 0; i < matrix_size; i++){
            cout << endl << endl << "How many adjacent nodes does " << i+1 << ". have? " << endl;
            cin >> amount;

            for(int j = 0; j < amount; j++){
                cout << endl <<"Enter the " << j+1 << ". adjacent node: ";
                cin >> num;
                this->adj_matrix[matrix_size * i + num - 1] = 1;
            }
        }
    }
    else{
        zeroMatrix(matrix_size);
    }
}

void graph :: zeroMatrix(int size){

    for(int i = 0; i < size * size; i++){
            this->adj_matrix.push_back(0);
    }
}

void graph :: printMatrix(vector<int> matrix){

    cout << endl << "    ";
    for(int i = 0; i < matrix_size; i++)
    cout << "v" << i + 1 << "  ";  
    cout << endl << endl;

    for(int i = 0; i < matrix_size; i++){
        cout << "v" << i + 1 << "  ";  
        for(int j = 0; j < matrix_size; j++){
            cout << matrix[matrix_size * i + j] << "   ";
        }
        cout << endl << endl;
    }
}

void graph :: initSomeValues(int type){

    for(int i = 0; i < matrix_size; i++){
        if(type == 0){
            visited_nodes.push_back(-1);
            isStacked.push_back(-1);  
        }
        else if(type == 1){
            visited_nodes[i] = -1;
            isStacked[i] = -1;  
        }
    }
}

void graph :: nodeStack(vector<int> matrix, int node, int node2){

    if(visited_nodes[node] == -1){

        visited_nodes[node] = 1;
        
        for(int j = 0; j < matrix_size; j++){
            if(matrix[node * matrix_size + j] != 0 && isStacked[j] == -1){
                stacked_nodes.push_back(j);
                isStacked[j] = 1;
                visited_nodes[j] == -1 ? components-- : 0;

                if(j == node2){
                    isCycle = 1;
                    break;
                }
            }
        }
    }
}
