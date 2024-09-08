#include <vector>
using namespace std;

/*
 * 二分探索。O(log n)。
*/

bool binary_search(int num, vector<int> A) {
    bool ret = false;
    int left = 0;
    int right = A.size() - 1;
    while (left < right) {
        int mid = (left + right)/2;
        if (A[mid] == num) {
            ret = true;
            break;
        }
        else if (A[mid] < num) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return ret;
}