#include<iostream>
#include<numeric>
using namespace std;
int main(){
    int N;
    cin >> N;
    // 투 포인터를 이용한 풀이
    int start = 1; // k번째 시행에서 구간의 출발점을 가리키는 변수
    int end = 1; // k번째 시행에서 구간의 끝점을 가리키는 변수
    int sum = 1; // k번째 시행에서 구간의 합
    int cnt = 1; // 문제의 조건을 만족 한 횟수, 뭔 짓을 해도 무조건 자기 자신이 n이 되는 케이스가 있으니 1로 초기화
    while(end != N){
        if(sum == N){ // 직전 케이스에서 넘어왔을 때 타겟넘버와 구간 합이 같은 경우
            cnt++; // 답이기 때문에 하나 추가
            end++; // 이 구간에서 다음 구간으로 가야하기때문에 뒤를 늘림
            sum += end; // 뒤를 한 칸 늘렸기 떄문에 다음 구간 합에 늘린 만큼 추가함
        }
        else if(sum > N){ // 구간 합이 커졌기 때문에 앞을 한 칸 줄여야함
            sum -= start; // 그래서 그걸
            start++; // 시행하면됨
        }
        else{ // sum < N인 경우
            end++; // 작으니깐 뒤를 늘리고
            sum += end; // 늘린만큼 더해주면 됨
        }
    }
    cout << cnt; // 어때요 참 쉽죠?
    return 0;
}