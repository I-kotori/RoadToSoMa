#include<iostream>
using namespace std;
int main(){
    int X = 64;
    int left = 0;
    int target;
    cin >> target;
    int level = 1;
    while(true){
        if(target == X){
            break;
        }
        left = X/2;
        X = X/2;
        X = left + X/2;
        level++;
    }
    cout << level;
    return 0;
}