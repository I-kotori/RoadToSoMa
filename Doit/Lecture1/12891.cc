#include<iostream>
using namespace std;
int main(){
    int S, P;
    string dna;
    cin >> S >> P >> dna;
    int cnt = 0;
    int gene[2][4] = {0,0,0,0,0,0,0,0,}; // A C G T
    for(int i=0;i<4;i++){
        cin >> gene[0][i];
    }
    for(int i=0;i<P;i++){
        if(dna[i] == 'A'){
            gene[1][0]++;
        }
        else if(dna[i] == 'C'){
            gene[1][1]++;
        }
        else if(dna[i] == 'G'){
            gene[1][2]++;
        }
        else if(dna[i] == 'T'){
            gene[1][3]++;
        }
    }
    bool flag = true;
    for(int i=0;i<4;i++){
        if(gene[0][i] > gene[1][i]) flag = false;
    }
    if(flag) cnt++;
    for(int i=0;i<S-P;i++){
        if(dna[i] == 'A'){
            gene[1][0]--;
            if(dna[i+P] == 'A'){
                gene[1][0]++;
            }
            else if(dna[i+P] == 'C'){
                gene[1][1]++;
            }
            else if(dna[i+P] == 'G'){
                gene[1][2]++;
            }
            else if(dna[i+P] == 'T'){
                gene[1][3]++;
            }
        }
        else if(dna[i] == 'C'){
            gene[1][1]--;
            if(dna[i+P] == 'A'){
                gene[1][0]++;
            }
            else if(dna[i+P] == 'C'){
                gene[1][1]++;
            }
            else if(dna[i+P] == 'G'){
                gene[1][2]++;
            }
            else if(dna[i+P] == 'T'){
                gene[1][3]++;
            }
        }
        else if(dna[i] == 'G'){
            gene[1][2]--;
            if(dna[i+P] == 'A'){
                gene[1][0]++;
            }
            else if(dna[i+P] == 'C'){
                gene[1][1]++;
            }
            else if(dna[i+P] == 'G'){
                gene[1][2]++;
            }
            else if(dna[i+P] == 'T'){
                gene[1][3]++;
            }
        }
        else if(dna[i] == 'T'){
            gene[1][3]--;
            if(dna[i+P] == 'A'){
                gene[1][0]++;
            }
            else if(dna[i+P] == 'C'){
                gene[1][1]++;
            }
            else if(dna[i+P] == 'G'){
                gene[1][2]++;
            }
            else if(dna[i+P] == 'T'){
                gene[1][3]++;
            }
        }
        for(int i=0;i<4;i++){
            if(gene[0][i] > gene[1][i]) flag = false;
        }
        if(flag) cnt++;
    }
    cout << cnt;
    return 0;
}