https://ei1333.github.io/luzhiled/snippets/tree/heavy-light-decomposition.html

## Methods

- `add`: $u$ から $v$ に向かうパス上の頂点または辺に対して処理を行う．
    - `q(a,b)`: HL 分解後の木における番号 が $[a,b)$ の頂点に対して処理を行う．`edge` が true のときは，$u\in[a,b)$ について，$u$ から親に向かう辺についての処理を行う．

## Local Variables

- `in[v]`: 頂点 `v` の HL 分解後の木における番号
- `head[v]`: 頂点 `v` が属する Heavy path の先頭の頂点番号

## Samples

https://judge.yosupo.jp/submission/218279
