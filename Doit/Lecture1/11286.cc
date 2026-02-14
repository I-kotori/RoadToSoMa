#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
int main(){
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        if(num == 0){
            if(maxHeap.empty() && minHeap.empty()) {
                cout << 0 << '\n';
                continue;
            }

            if(maxHeap.empty()){
                cout << minHeap.top() << '\n';
                minHeap.pop();
            }
            else if(minHeap.empty()){
                cout << maxHeap.top() << '\n';
                maxHeap.pop();
            }
            else{
                if(abs(maxHeap.top()) == abs(minHeap.top())){
                    cout << maxHeap.top() << '\n';
                    maxHeap.pop();
                }
                else if(abs(maxHeap.top()) < abs(minHeap.top())){
                    cout << maxHeap.top() << '\n';
                    maxHeap.pop();
                }
                else{
                    cout << minHeap.top() << '\n';
                    minHeap.pop();
                }
            }
        }
        else{
            if(num > 0){
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
        }
    }
    return 0;
}