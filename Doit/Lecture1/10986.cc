#include<iostream>
using namespace std;
int main(){
    int N, M;
    int prefix[1010101] = {0, };
    int cnt[1010101] = {0, };
    cin >> N >> M;
    int temp = 0;
    int answer = 0;
    for(int i=1;i<=N;i++){
        cin >> temp;
        prefix[i] = temp + prefix[i-1];
    }
    for(int i=0;i<N;i++){
        int mod = prefix[i] % M;
        if(mod == 0){
            answer++;
        }
        cnt[mod]++;
    }
    for(int i=0;i<M;i++){
        if(cnt[i] > 1){
            answer = answer + (cnt[i] * (cnt[i]-1) / 2);
        }
    }
    cout << answer;
    return 0;
}