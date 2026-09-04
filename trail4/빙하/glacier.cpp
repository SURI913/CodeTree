#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int a[200][200];

int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
bool visited[200][200]={false,};
int melttingTime;
int lastIce;

void initVisited(){
    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            visited[i][j] = false;
        }
    }
}

enum State{
    WATER,
    ICE,
};

bool IsRange(int r, int c){
    return (r >=0 && r<N && c>=0 && c<M);
}

void BFS(int r, int c){
    queue<pair<int,int>>q;
    q.push({r,c});
    visited[r][c] = true;

    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(!IsRange(nr,nc)) continue;
            if(a[nr][nc] == WATER && !visited[nr][nc]) {
                //이거 자체가 바깥 물만 체크임
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

bool CheckOutsiderWater(int r, int c){
    for(int i =0; i< 4;i++){
        int nr = r+dr[i];
        int nc = c+dc[i];

        if(IsRange(nr, nc) && visited[nr][nc]) return true; //범위안에있고 방문했던 물이면?
    }
    return false;
}

void Melt(){
    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            if(a[i][j] == ICE &&  CheckOutsiderWater(i,j)){
                //얼음이고, 주변에 물이 있다고 확인된 얼음이면 녹이기
                a[i][j] = WATER;
                lastIce++; //일단 녹일때마다 카운트 하고 결국 마지막에 남은건 마지막에 녹인 거니까
            }
        }
    }

    melttingTime++; //주변 한번 녹일 때마다 한시간
}

bool isRemainIce(){
    for(int i=0; i< N; i++){
        for(int j=0;j <M; j++){
            if(a[i][j] == ICE) return true;
        }
    }

    return false;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    //

    while (isRemainIce()) {
        initVisited();
        lastIce = 0;
        BFS(0,0); // < --- 물의 위치를 전부 visited로 체크
        //체크한걸 가지고 물 근처에 인접한 아이스 녹임
        Melt();
        //빙하 남았는지 체크 후 남았다면 반복.
    }


    cout << melttingTime << ' '<< lastIce <<'\n';

    return 0;
}
