/*
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5

*/
#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000001];
int current;
int main(){
    fill(arr, arr+1000000, 1);
    arr[1] = 0;
    for(int i=2;i<=1413;i++){
        current = i-1;
        for(int j=2;i*j+current <= 1000000;j++){
            arr[i*j+current]++;
        }
    }
    int num;
    while(cin >> num){
        if (num == 0) break;
        cout << arr[num] << '\n';
    }
    return 0;
}