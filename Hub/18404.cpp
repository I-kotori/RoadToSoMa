#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool isInIndex(int x, int y, int n){
    return x >=0 && x < n && y >= 0 && y < n;
}
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
vector<bool> v;
int main(){
    int N, M;
    cin >> N >> M;
    int xAxis, yAxis; // 출발지점 세팅
    cin >> xAxis >> yAxis;
    for(int i=0;i<M;i++){
        bool chk = false;
        int x, y;
        cin >> x >> y;
        int cnt = 0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        q.push({{xAxis, yAxis},0});
        visited[xAxis][yAxis] = true;
        v.resize(N);
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            for(int dir=0;dir<8;dir++){
                int nx = current.first.first + dx[dir];
                int ny = current.first.second + dy[dir];
                int dist = current.second;
                if(!isInIndex(nx, ny, N)){
                    continue;
                }
                if(!visited[nx][ny]){
                    visited[nx][ny] = true;
                    if(nx == x && ny == y){
                        cout << dist + 1 << ' ';
                        chk = true;
                        break;
                    }
                    q.push({{nx, ny}, dist + 1});
                }
            }
            if(chk){
                break;
            }
        }
    }
    return 0;
}