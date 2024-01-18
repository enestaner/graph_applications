#include "graph.h"

vector<int> createSequence(int size){

    vector<int> sequence;
    int num;

    for(int i = 0; i < size; i++){
        cout << "Enter " << i+1 << ". number: " << endl;
        cin >> num;
        sequence.push_back(num);
    }

    printSequence(sequence);

    return sequence;
}

void printSequence(vector<int> seq){
    cout << "Sequence: ";
    for(int i = 0; i < seq.size(); i++){
        cout << seq[i] << " ";
    }
    cout << endl;
}

int isGraphic(vector<int> seq){

    int flag = 1, num, temp;

    while(flag){

        num = seq.front();
        seq.erase(seq.begin());

        for(int i = 0; i < num; i++){
            seq[i] -= 1;

            if(seq[i] < 0)
            return 0;
        }

        printSequence(seq);

        for(int i = 0; i < seq.size() - 1; i++){

            for(int j = i + 1; j < seq.size(); j++){
                
                if(seq[i] < seq[j]){
                    temp = seq[i];
                    seq[i] = seq[j];
                    seq[j] = temp;
                    
                    cout << "Rearranged ";
                    printSequence(seq);
                }
            }
        }

        flag = 0;
        for(int i = 0; i < seq.size(); i++){
            if(seq[i] != 0)
            flag = 1;
        }
    }
    return 1;
}

int main(){

    int size;
    string is_graphic;
    vector<int> sequence;

    cout << "Enter the size of sequence" << endl;
    cin >> size;
    sequence = createSequence(size);
    isGraphic(sequence) == 1 ? is_graphic = "YES" : is_graphic = "NO";
    cout << "Is sequence graphic: " << is_graphic << endl;

    return 0;
}

