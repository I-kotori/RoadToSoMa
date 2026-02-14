#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    int arr[N +5];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int cnt = 0;
    for(int i=0;i<N;i++){
        int target = arr[i];
        int start  = 0;
        int end = N-1;
        while(start < end){
            if(arr[start] + arr[end] == target){
                if(i != start && i != end){
                    cnt++;
                    break;
                }
            }
            else if(arr[start] + arr[end] < target){
                start++;
            }
            else{
                end--;
            }
        }
    }
    cout << cnt;
    return 0;
}