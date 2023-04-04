#include <iostream>
#include <vector>

std::vector<std::vector<int>> city;
std::vector<bool> used;
bool f = false;

void dfs(int u, int v) {
  used[u] = true;

  for (int i = 0; i < city[u].size(); i++) {
    int k = city[u][i];
    if (!used[k]) {
      dfs(k, v);
    }
  }
}

int main() {
  int N;
  int M;
  int Q;
  int a;
  int b;
  char command;

  std::cin >> N >> M >> Q;

  city.assign(N, {});
  used.assign(N, false);

  for (int i = 0; i < M; i++) {
    std::cin >> a >> b;
    city[a - 1].push_back(b - 1);
    city[b - 1].push_back(a - 1);
  }

  for (int i = 0; i < Q; i++) {
    std::cin >> command;
    std::cin >> a >> b;

    if (command == '?') {
      dfs(a - 1, b - 1);
      if (used[b - 1]) {
        std::cout << "YES" << '\n';
      } else {
        std::cout << "NO" << '\n';
      }
      used.assign(N, false);
      f = false;
    } else {
      for (int j = 0; j < city[a - 1].size(); j++) {
        if (city[a - 1][j] == b - 1) {
          city[a - 1].erase(city[a - 1].begin() + j);
        }
      }
      for (int j = 0; j < city[b - 1].size(); j++) {
        if (city[b - 1][j] == a - 1) {
          city[b - 1].erase(city[b - 1].begin() + j);
        }
      }
    }
  }
}
