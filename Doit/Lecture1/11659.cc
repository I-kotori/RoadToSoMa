#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int arr[101010] = {0,};
    long long prefix[101010] = {0,};
    int N, K;
    cin >> N >> K;

    for(int i=1;i<=N;i++){
        cin >> arr[i];
        prefix[i] = arr[i] + prefix[i-1];
    }
    for(int i=0;i<K;i++){
        int start, end;
        cin >> start >> end;
        cout << prefix[end] - prefix[start-1] << '\n';
    }
    return 0;
}