#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#pragma region "Union-Find"

/**
 * Union-Find 木の実装
 * - 任意の 2 頂点の結合
 * - ある 2 頂点が連結かどうかの判定
 * が高速にできる
 */
class UnionFind {
    const int size;
    vector<int> parents;

public:
    UnionFind(const int _size) : size(_size), parents(size, -1) {}

    int root(const int v) {
        if (parents[v] == -1) {
            return v;
        } else {
            return parents[v] = root(parents[v]);
        }
    }

    // v1, v2 が連結か
    bool is_connected(const int v1, const int v2) {
        return root(v1) == root(v2);
    }

    // v1, v2 を結合
    void merge(const int v1, const int v2) {
        if (is_connected(v1, v2))
            return;
        parents[root(v2)] = v1;
    }
};

#pragma endregion

// 座標 (x, y) を一意なインデックスに変換する
int index(const int x, const int y, const int W) {
    return y * W + x;
}

int main(int argc, char *argv[]) {
    // 入力を受け取る
    int n, l;
    cin >> n >> l;

    vector<vector<int>> edges;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        edges.push_back(vector<int>{a, b, c, d});
    }

    // 通路の広さは通行可能かどうかに影響しないので，座標圧縮する

    // 登場した x, y の値の集合 (ソート済み)
    // 端まで切っているかは重要なので，端の値は追加しておく
    set<int> xs{0, l}, ys{0, l};
    for (auto &v : edges) {
        xs.insert(v[0]);
        ys.insert(v[1]);
        xs.insert(v[2]);
        ys.insert(v[3]);
    }

    // "登場した x, y の値 -> その値が小さい方から何番目か" を表すマップ
    unordered_map<int, int> x_map, y_map;
    int idx = 0;
    for (auto x : xs) x_map[x] = idx++;
    idx = 0;
    for (auto y : ys) y_map[y] = idx++;

    // 座標圧縮
    for (auto &v : edges) {
        v[0] = x_map[v[0]];
        v[1] = y_map[v[1]];
        v[2] = x_map[v[2]];
        v[3] = y_map[v[3]];
    }

    // 登場する x, y の値はそれぞれ高々 2(n+1) 個なので，
    // これで 0 <= v[i] < 2(n+1) になった

    const int xsize = xs.size();
    const int ysize = ys.size();

    /**
     * (0, 0) から (xsize - 1, ysize - 1) へ到達可能かを判定するには，
     * (0, ysize - 1) から (xsize - 1, 0) まで，外周または柵の上のみを
     * 通ることで到達可能かを調べれば良い．
     * ただし，外周には (0, 0), (xsize - 1, ysize - 1) は含まない．
     *
     * この判定には Union-Find 木が使える．
     *
     * 左上の外周，右下の外周 をそれぞれ結合した状態にして，
     * 柵を追加するたびに柵上の点を結合していき，
     * 左上と右下の点が連結かどうかを判定すればよい．
     */

    // (x, y) のインデックスは index(x, y, xsize) := y * xsize + x
    UnionFind uf(xsize * ysize);

    // 外周を結合
    for (int x = 1; x < xsize - 1; x++) {
        uf.merge(index(x - 1, ysize - 1, xsize), index(x, ysize - 1, xsize));
        uf.merge(index(x, 0, xsize), index(x + 1, 0, xsize));
    }
    for (int y = 1; y < ysize - 1; y++) {
        uf.merge(index(xsize - 1, y - 1, xsize), index(xsize - 1, y, xsize));
        uf.merge(index(0, y, xsize), index(0, y + 1, xsize));
    }

    // 柵上の点を結合しながら判定
    for (int i = 0; i < edges.size(); i++) {
        auto &edge = edges[i];
        if (edge[0] != edge[2]) {
            // 横方向
            auto a = min(edge[0], edge[2]);
            auto b = max(edge[0], edge[2]);
            for (int x = a; x < b; x++) {
                uf.merge(index(x, edge[1], xsize), index(x + 1, edge[1], xsize));
            }
        } else {
            // 縦方向
            auto a = min(edge[1], edge[3]);
            auto b = max(edge[1], edge[3]);
            for (int y = a; y < b; y++) {
                uf.merge(index(edge[0], y, xsize), index(edge[0], y + 1, xsize));
            }
        }
        // 左上と右下が繋がっているか
        if (uf.is_connected(index(0, ysize - 1, xsize), index(xsize - 1, 0, xsize))) {
            cout << "NO\n"
                 << (i + 1) << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
