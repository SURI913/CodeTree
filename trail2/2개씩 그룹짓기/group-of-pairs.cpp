#include <iostream>
#include <algorithm>

using namespace std;

int N;
int nums[2000];

int main() {
    cin >> N;

    for (int i = 0; i < 2 * N; i++) {
        cin >> nums[i];
    }

    // Please write your code here.

    //각 그룹의 합의 최대값이 최소가 되려면
    //양끝단끼리 더하기 ?

    sort(nums, nums+2*N);
    int reuslt = 0;
    for(int i =0; i<N;i++){
        int sum = nums[i] + nums[N*2-1-i];

        if(reuslt < sum)  reuslt = sum; 
        //cout << "choice: " << nums[i] << " " <<   nums[N*2-1-i] <<endl;    
    }


    cout<< reuslt <<endl;

    return 0;
}
