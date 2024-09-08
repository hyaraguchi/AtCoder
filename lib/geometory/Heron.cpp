#include <cmath>
using namespace std;
typedef long long ll;

// ヘロンの公式（三辺a, b, cから三角形の面積を求める）

double Heron(double a, double b, double c) {
    double s = (a+b+c)/2;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}