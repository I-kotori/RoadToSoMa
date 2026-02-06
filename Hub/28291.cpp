#include<iostream>
#include<queue>
#define INF 1e9
using namespace std;
queue<pair<pair<int, int>, int>> q;
bool isInIndex(int x, int y, int w, int h){
    return x >= 0 && y >= 0 && x < w && y < h;
}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int main(){
    int w, h;
    cin >> w >> h;
    int N;
    cin >> N;
    int arr[w+1][h+1];
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            arr[i][j] = INF;
        }
    }
    bool visited[w+1][h+1];
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            visited[i][j] = false;
        }
    }
    for(int i=0;i<N;i++){
        string name;
        int x, y;
        cin >> name >> x >> y;
        if(name == "redstone_block"){
            arr[x][y] = 0;
            q.push({{x,y}, 0});
        }
        else if(name == "redstone_dust"){
            arr[x][y] = 1;
        }
        else if(name == "redstone_lamp"){
            arr[x][y] = 2;
        }
    }
    bool chk = true;
    visited[0][0] = true;
    while(!q.empty()){
        auto current = q.front();
        q.pop();
        if (current.second >= 15) continue;
        for(int dir = 0; dir < 4; dir++){
            int nx = current.first.first + dx[dir];
            int ny = current.first.second + dy[dir];
            if(isInIndex(nx, ny, w, h) && !visited[nx][ny] && arr[nx][ny] == 1){
                visited[nx][ny] = true;
                q.push({{nx, ny}, current.second + 1});
            }
            else if(isInIndex(nx, ny, w, h) && arr[nx][ny] == 2){
                if(current.second + 1 >= 15){
                    chk = false;
                }
            }
        }
    }
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(visited[i][j] == false && arr[i][j] == 2){
                chk = false;
            }
        }
    }
    if(chk){
        cout << "success";
    }
    else{
        cout << "failed";
    }
    return 0;
}