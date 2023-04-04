#include <iostream>
#include <vector>

std::vector<bool> used;
std::vector<int> answer;
std::vector<std::vector<int>> array;

void dfs(int v) {
  used[v] = true;
  for (int i = 0; i < array[v].size(); i++) {
    int to = array[v][i];
    if (!used[to]) {
      dfs(to);
    }
  }
  answer.push_back(v);
}

void topsort(int n) {
  used.assign(n, false);
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  std::reverse(answer.begin(),answer.end());
}

int main(){
  int n;
  int m;
  int a;
  int b;

  std::cin >> n >> m;
  std::vector<int> result(n,0);

  for(int i = 0; i < n; i++){
    array.emplace_back();
  }

  for(int i = 0; i < m; i++){
    std::cin >> a >> b;
    array[a - 1].push_back(b - 1);
  }

  topsort(n);

  for(int i = 0; i < answer.size(); i++){
    result[answer[i]] = i + 1;
  }

  for(int i = 0;i < result.size();i++){
    std::cout << result[i] << " ";
  }

  return 0;
}
