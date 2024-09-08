#include <cmath>
using namespace std;
typedef long long ll;

// 座標平面上の二点間の距離

double distance(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}