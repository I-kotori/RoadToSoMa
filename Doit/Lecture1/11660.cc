#include<iostream>
using namespace std;
int arr[1050][1050];
int prefix[1050][1050] = {0,};
int main(){
    int N, K;
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + arr[i][j];
        }
    }
    int s1, s2, e1, e2;
    for(int i=0;i<K;i++){
        cin >> s1 >> s2 >> e1 >> e2;
        cout << prefix[e1][e2] - prefix[s1-1][e2] - prefix[e1][s2-1] + prefix[s1][s2-1] << '\n';
    }
    return 0;
}