#include <iostream>
#include <vector>

std::vector<std::vector<int>> city;
std::vector<int> colour;
std::vector<int> mama;
bool f;
int start = -1;

void DFS(int u, int k) {
  if (f) return;
  colour[u] = 1;
  for (int i = 0; i < city[u].size(); ++i) {
    int v = city[u][i];

    if (v == k) {
      f = true;
      return;
    } else if (colour[v] == 0) {
      DFS(v, k);
    }

    if(f) return;

  }
}

int main() {
  int N;
  int M;
  int Q;
  int a;
  int b;

  std::cin >> N >> M >> Q;

  city.assign(N, {});

  colour.assign(N, 0);

  for (int i = 0; i < M; i++) {
    std::cin >> a >> b;
    city[a - 1].push_back(b - 1);
  }


  for (int i = 0; i < Q; ++i) {
    std::cin >> a >> b;
    a--;
    b--;
    f= false;
    colour.assign(N, 0);
    DFS(a,b);
    if (f) {
      colour.assign(N, 0);
      f = false;
      DFS(b,a);
      if (f) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    } else {
      std::cout << "NO\n";
    }
  }
}
