#include<iostream>
#include<queue>
using namespace std;
int main(){
    int N;
    queue<int> q;
    cin >> N;
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    int ans;
    while(!q.empty()){
        ans = q.front();
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << ans;
    return 0;
}