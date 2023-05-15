#include <iostream>
#include <vector>

struct edge{
  int from;
  int to;
  int weight;
};


const int INF = 1000000;
int cycle;

void BelFord(int n, std::vector<edge>& graph, std::vector<int>& d, std::vector<int>& parent) {
  d[0] = 0;

  for (int j = 0; j < n; j++) {
    cycle = -1;
    for (edge edge : graph) {
      if(d[edge.from] == INF) continue;
      if (d[edge.to] > d[edge.from] + edge.weight) {
        d[edge.to] = d[edge.from] + edge.weight;
        parent[edge.to] = edge.from;
        cycle = edge.to;
      }
    }
    if(cycle == -1) break;
  }
}

int main() {
  int N;
  int k;
  int n;
  int m;
  int s;
  int f;
  int w;

  std::cin >> N >> k;

  for (int i = 0; i < N; i++) {
    std::vector<edge> graph;
    std::vector<int> parent;
    std::vector<int> d;
    std::cin >> n >> m;

    d.assign(n, INF);
    parent.assign(n, -1);

    for (int j = 0; j < m; j++) {
      std::cin >> s >> f >> w;

      graph.push_back({s - 1, f - 1, w});
    }

    BelFord(n, graph,d,parent);

    if (cycle != -1) {
      int end = cycle;
      std::vector<int> path;

      for (int z = 0; z < n; z++) {
        end = parent[end];
      }

      for (int z = end; z != end || path.empty(); z = parent[z]) {
        path.push_back(z);
      }
      path.push_back(end);

      if (path.size() <= k) {
        std::cout << "YES" << '\n';
        break;
      }

      std::cout << "NO" << '\n';
    }

    else {
      std::cout << "YES" << '\n';
    }
  }
}

