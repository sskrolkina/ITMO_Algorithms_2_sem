#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> city;
std::vector<int> dist;

void path(int s, int f, int n) {
  dist[s] = 1;
  std::queue<int> q;
  q.push(s);
  std::vector<bool> used(n + 1, false);
  used[s] = true;

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : city[v]) {
      int to = u;
      if (!used[to]) {
        used[to] = true;
        dist[to] = dist[v] + 1;
        q.push(to);
      }
    }
  }
}

int main() {
  int n;
  int m;
  int s;
  int f;
  int a;
  int b;

  std::cin >> n >> m;

  for (int i = 0; i < n + 1; i++) {
    city.emplace_back();
    dist.push_back(0);
  }

  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    city[a].push_back(b);
    city[b].push_back(a);
  }

  std::cin >> s >> f;

  path(s, f, n);

  std::cout << dist[f] - 1;

}
