#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    int arr[20202];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int i = 0;
    int j = N-1;
    int cnt = 0;
    while(i < j){
        if(arr[i] + arr[j] < M){
            i++;
        }
        else if(arr[i] + arr[j] > M){
            j--;
        }
        else{
            cnt++;
            i++;
            j--;
        }
    }
    cout << cnt;
    return 0;
}