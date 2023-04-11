import sys

sys.setrecursionlimit(10 ** 9)

N = int(input())
E = [list(map(int, input().split())) for _ in range(N - 1)]

# 各頂点に隣接する頂点のリスト
adj = [[] for _ in range(N)]
for v1, v2 in E:
    adj[v1 - 1].append(v2 - 1)
    adj[v2 - 1].append(v1 - 1)


def get_farthest_node(n, exc=-1):
    # 頂点 n からの経路が最長の頂点とその距離を求める
    dist = -1
    ans = -1
    for i in adj[n]:
        if i == exc:
            continue
        a, d = get_farthest_node(i, n)
        if d + 1 > dist:
            dist = d + 1
            ans = a
    if ans == -1:
        return n, 0
    return ans, dist


def get_diameter():
    node, _ = get_farthest_node(0)
    _, ans = get_farthest_node(node)
    return ans + 1


print(get_diameter())
