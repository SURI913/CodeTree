#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int grid[20][20];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result=0;
    for(int cneterR =0; cneterR< n; cneterR++){
        for(int cneterC =0; cneterC<n; cneterC++){
            //여기까지가 마름모 지점 잡는 범위
            for(int k =0; k <= 2*(n-1); k++ ){
                //마름모 깊이
                int gold = 0; 
                for(int r =0; r<n; r++){
                    for(int c = 0; c<n; c++){
                        //여기서부터 마름모 깊이만큼 점점 커짐
                        //맨해튼 거리에 해당되고 금이 있으면 ++
                        if(abs(r-cneterR)+abs(c-cneterC) <= k && grid[r][c]==1) {
                            gold++;
                        }
                    }
                }
                
                //K값에 맞춰 채굴 손해가 없으면서 금을 제일 많이 얻을 수 있는방법
                int cost = k*k+(k+1)*(k+1); //채굴비용
                int profit =  gold * m;

                if(cost <= profit){
                    result = max(gold, result);
                }

            }

        }
    }

    cout << result<<endl;
    // Please write your code here.

    return 0;
}
