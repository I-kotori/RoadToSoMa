#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isInIndex(int x, int y, int n){
    return x >0 && x <= n && y > 0 && y <= n;
}
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N+1, vector<int>(N+1, -1));
    queue<pair<pair<int , int>, int>> q;
    int startX, startY;
    cin >> startX >> startY;
    q.push({{startX, startY}, 0});
    v[startX][startY] = 0;
    while(!q.empty()){
        auto current = q.front();
        q.pop();
        int x = current.first.first;
        int y = current.first.second;
        int dist = current.second;
        for(int dir=0;dir<8;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(isInIndex(nx, ny, N) && v[nx][ny] == -1){
                v[nx][ny] = dist+1;
                q.push({{nx, ny}, dist+1});
            }
            else{
                continue;
            }
        }
    }
    for(int i=0; i<M; i++){
        int targetX, targetY;
        cin >> targetX >> targetY;
        cout << v[targetX][targetY] << ' ';
    }
    return 0;
}