#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    int arr[101010];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    int num = 1;
    bool flag = true;
    stack<char> s;
    vector<char> seq;
    for(int i=0;i<N;i++){
        int current = arr[i];
        if(num <= current){
            while(num <= current){
                s.push(num++);
                seq.push_back('+');
            }
            s.pop();
            seq.push_back('-');
        }
        else{
            int n = s.top();
            s.pop();
            if(n > current){
                cout << "NO";
                flag = false;
                break;
            }
            else{
                seq.push_back('-');
            }
        }
    }
    if(flag){
        int size = seq.size();
        for(int i=0;i<size;i++){
            cout << seq[i] << '\n';
        }
    }
    return 0;
}
