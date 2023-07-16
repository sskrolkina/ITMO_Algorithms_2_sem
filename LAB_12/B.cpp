#include <iostream>
#include <vector>

#define int long long

int* p;
int* r;

void init(int N) {
  for (int i = 0; i < N; i++) {
    p[i] = i;
    r[i] = 0;
  }
}

int get(int a) {
  if (a == p[a])
    return a;
  return (p[a] = get(p[a]));
}

void join(int a, int b) {
  a = get(a);
  b = get(b);
  if (a != b) {
    if (r[a] > r[b]) {
      std::swap(a, b);
    }
    r[b] += r[a];
    p[a] = b;
  }
}

signed main() {
  int N;
  int M;
  int a;
  int b;
  int c;
  int result = 0;

  std::cin >> N >> M;

  p = new int[N + 1];
  r = new int[N + 1];

  init(N + 1);

  std::vector<std::vector<int>> graph;

  for(int i = 0; i < M; i++) {
    std::cin >> a >> b >> c;
    graph.push_back({a,b,c});
  }

  for(int i = 1; i < N; i++){
    for(int j = i; j > 0 && graph[j-1][2] > graph[j][2];j--){
      std::swap(graph[j-1],graph[j]);
    }
  }

  for(auto i : graph) {
    if(get(i[0]) != get(i[1])) {
      join(i[0], i[1]);
      result += i[2];
    }
  }

  std::cout << result;

  return 0;
}
