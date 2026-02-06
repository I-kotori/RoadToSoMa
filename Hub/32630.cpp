#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> v;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end(),greater<>());
    /*
    cout << '\n';
    for(int i : v){
        cout << i << ' ';
    }
    cout << '\n';
    */
    long long sum = 0;
    for(int i=0;i<N;i++){
        sum += v[i];
    }
    long long calcSum = 0;
    int tmp0 = v[0];
    int tmp1 = v[1];
    v[0] = v[1] * v[0];
    v[1] = v[0];
    for(int i=0;i<N;i++){
        calcSum += v[i];
    }
    v[0] = tmp0;
    v[1] = tmp1;
    v[N-1] = v[N-1] * v[N-2];
    v[N-2] = v[N-1];
    long long minusSum = 0;
    for(int i=0;i<N;i++){
        minusSum += v[i];
    }
    cout << max(minusSum, max(sum, calcSum));
    return 0;
}