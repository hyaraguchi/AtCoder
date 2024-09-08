#include <cmath>
using namespace std;

// 余弦定理
// c^2 = a^2 + b^2 - 2*a*b*cos(theta)
// theta: 辺aと辺bの間の角(ラジアン)

double law_of_cosines(double a, double b, double theta) {
    return a*a + b*b - 2*a*b*cos(theta);
}
