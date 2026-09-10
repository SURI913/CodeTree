#include <iostream>
#include <vector>

using namespace std;
#define MAX 100

int N, M, K;
int numbers_2d[MAX][MAX];

//한줄씩 복사해서 터트림
vector<int> Bomb(const vector<int>& bomb_1d, bool& exploded){
    //M개 이상의 연속된 같은 숫자만
    vector<int> result;
    int left=0;
    int cnt =0;

    while(left < bomb_1d.size()){
        int right = left+1;
        while(right < bomb_1d.size() && bomb_1d[left] == bomb_1d[right]) right++;
        
        int cnt = right - left; //연속 구간개수
        if(cnt < M){
            //터진거 중 안터진거 저장
            for(int seq = left; seq < right; seq++){
                result.push_back(bomb_1d[seq]);
            }
        }
        else{
            exploded = true; //터질거 없음
        }
        left = right;
    }
    return result;
}

void CopyArr(int a[][MAX], int b[][MAX]){
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            a[r][c] = b[r][c];
        }
    }
}

//시계방향으로 값 정비하는 거 필요
void Rotate_2D(){
    int temp[MAX][MAX] = {0,};

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            temp[c][N - 1 - r] = numbers_2d[r][c];
        }
    }

    CopyArr(numbers_2d, temp);

    
}


bool ExplodedCheck(){
    bool exploded = false;
    while (true) {
        exploded = false;
        int answer[MAX][MAX]={0,};
        //이제 이거 안터질때까지 반복인건가
        for (int i = 0; i < N; i++) {
            vector<int> bomb_1d; 
            for (int j = 0; j < N; j++) {
                if(numbers_2d[j][i] != 0){
                    bomb_1d.push_back(numbers_2d[j][i]);
                }
                
            }
            
            bomb_1d = Bomb(bomb_1d, exploded);

            //값 반영 밑에서부터 채울 것
            for (int j = 0; j < bomb_1d.size(); j++) {
                answer[N - bomb_1d.size()+j][i] = bomb_1d[j];
            }

        }

        CopyArr(numbers_2d, answer);
        if(!exploded) break; //다 터졌으니 종료
    }

    return exploded;
}

int main() {
    cin >> N >> M >> K;
    //연속으로 M개 이상 같은 수자 폭탄 터짐

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> numbers_2d[i][j];
        }
    }

    ExplodedCheck();

    while(K--){
        Rotate_2D();//다터진 후에는 회전함
        ExplodedCheck();
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(numbers_2d[i][j] != 0) cnt++;
        }
    } 
    // Please write your code here.

    cout << cnt <<endl;

    return 0;
}
