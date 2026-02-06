#include<iostream>
#include<queue>
using namespace std;
int adj[5][5];
bool visited[5][5];
queue<pair<int,int>> q;
int main(){
    int N;
    cin >> N;
    if(N==1){
        cout << N;
    }
    else if(N==2){
        int a, b,c,d;
        cin >> a >> b>> c >> d;
        cout << a + b + c + d;
    }
    else{
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> adj[i][j];
            }
        }
        
    }
    return 0;
}