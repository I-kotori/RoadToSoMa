#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    int arr[1010101];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    stack<int> s;
    vector<int> ans(N, -1);
    s.push(arr[0]);
    for(int i=0;i<N;i++){
        while(!s.empty() && arr[s.top()] < arr[i]){
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    for(int i : ans){
        cout << i << ' ';
    }
    return 0;
}