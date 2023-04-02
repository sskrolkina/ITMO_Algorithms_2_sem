#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<bool> color;

void dfs(int v){
  color[v] = true;
  for(int i : graph[v]){
    if (!color[i]){
      dfs(i);
    }
  }
}

int main() {
  int n;
  int m;
  int  a;
  int b;
  int count = 0;

  std::cin >> n >> m;

  for(int i = 0; i < n + 1; i++){
    graph.emplace_back();
    color.push_back(false);
  }

  for(int i = 0; i < m; i++) {
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for(int i = 1;i < n + 1;i ++){
    if(graph[i].size() < 2) {
      count++;
    }
  }
  if(count > 2){
    std::cout << "NO";
    return 0;
  }

  dfs(n);

  for(int i = 1; i <= n; i++){
    if(color[i] != 1){
      std::cout << "NO";
      return 0;
    }
  }
  std::cout << "YES";
}
