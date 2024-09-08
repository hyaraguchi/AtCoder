#include <vector>
using namespace std;

/* 
 * 重み付きグラフの隣接リスト表現
 * Edge : 辺を表す構造体（src : 一方の頂点, dst : もう一方の頂点, weight : 重み）
 * MAX_V : 最大頂点数
 * G : グラフ
*/

struct Edge {
    int src, dst, weight;
};
const int MAX_V = 1.0e5;
vector<Edge> G[MAX_V];
