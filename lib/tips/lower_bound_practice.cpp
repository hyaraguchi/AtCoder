#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 *  lower_bound, upper_bound を用いた二分探索。 
 * 　O(log n)
*/

int main() {
    vector<int> nums = {1,1,1,1,2,2,3,3,3,4,4,6,6,6};
    // 予めソートしておく。
    sort(nums.begin(), nums.end());  

    // 3より小さい要素数
    int lessThan3 = lower_bound(nums.begin(), nums.end(), 3) - nums.begin();

    // 3以下の要素数
    int equalOrLessThan3 = upper_bound(nums.begin(), nums.end(), 3) - nums.begin();

    // 3より大きい要素数 (= 全要素数 - 3以下の要素数)
    int moreThan3 = nums.size() - equalOrLessThan3;

    // 3以上の要素の数 (= 全要素数 - 3未満の要素数)
    int equalOrMoreThan3 = nums.size() - lessThan3;

    // 3より大きい数のうち最小値
    nums[equalOrLessThan3];
    // 3以下の数のうち最大値
    nums[equalOrLessThan3 - 1];
    
    return 0;
}