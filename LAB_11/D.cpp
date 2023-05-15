#include <iostream>
#include <vector>

struct edge{
  int from;
  int to;
  int weight;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  int M;
  int Q;
  int start;
  int s;
  int f;
  int w;
  int x;
  std::vector<size_t> d;
  std::vector<edge> graph;

  std::cin >> N >> M >> Q >> start;
  start--;
  d.assign(N, INT64_MAX);

  for (int i = 0; i < M; i++) {
    std::cin >> s >> f >> w;
    s--;
    f--;
    graph.push_back({s, f, w});
    graph.push_back({f, s, w});
  }

  d[start] = 0;
  for(int i = 0; i < N - 1; i++){
    x = -1;
    for(auto j : graph){
      if(d[j.from] + j.weight < d[j.to]){
        d[j.to]= d[j.from] + j.weight;
        x = 1;
      }
    }
    if(x == -1) break;
  }

  for (int i = 0; i < Q; i++) {
    std::cin >> x;
    x--;
    if (d[x] == INT64_MAX) {
      std::cout << -1 << '\n';
    } else {
      std::cout << d[x] << '\n';
    }
  }
}
