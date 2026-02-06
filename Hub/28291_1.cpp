#include<iostream>
#include<queue>
#include<string>
#define INF 1e9
using namespace std;

// ??? ?? ?? ???(??)? ?? ?
// {{x, y}, distance}
queue<pair<pair<int, int>, int>> q;

int arr[55][55];
bool visited[55][55];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool isInIndex(int x, int y, int w, int h){
    return x >= 0 && y >= 0 && x < w && y < h;
}

int main(){
    int w, h;
    cin >> w >> h;

    int N;
    cin >> N;

    // ? ???: -1 ?? INF? ??? (???? ??? ?? -1 ?? ???? ?? ?? ??)
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            arr[i][j] = INF; // ? ??
            visited[i][j] = false;
        }
    }

    // ?? ??
    for(int i=0;i<N;i++){
        string name;
        int x, y;
        cin >> name >> x >> y;
        if(name == "redstone_block"){
            arr[x][y] = 0;
            // ???(??)? ?? ???? ?? ??
            visited[x][y] = true;
            q.push({{x, y}, 0});
        }
        else if(name == "redstone_dust"){
            arr[x][y] = 1;
        }
        else if(name == "redstone_lamp"){
            arr[x][y] = 2;
        }
    }

    // BFS ??
    while(!q.empty()){
        pair<pair<int, int>, int> current = q.front();
        q.pop();

        int curX = current.first.first;
        int curY = current.first.second;
        int curDist = current.second;

        // ??? 15?? ???? ??? 0? ? (?? 0?? ?? 15 -> ?? 14?? ?? 1)
        // ??? ??? 14 ???? ? ?? ???? ??? ??? ? ??
        if(curDist >= 14) continue;

        for(int dir=0;dir<4;dir++){
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nextDist = curDist + 1;

            if(isInIndex(nx, ny, w, h) && !visited[nx][ny]){
                // ???? ??(1)? ??: ??? ????? ?? ??
                if(arr[nx][ny] == 1){
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, nextDist});
                }
                // ???? ??(2)? ??: ??? ??? ?? (?? ??? ?)
                // ??? ??? ?? ???? ???? ?? ?? ??
                else if(arr[nx][ny] == 2){
                    visited[nx][ny] = true;
                }
            }
        }
    }

    // ?? ??
    bool chk = true;
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            // ??(2)?? ???? ????(??? ? ????) ??
            if(arr[i][j] == 2 && visited[i][j] == false){
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