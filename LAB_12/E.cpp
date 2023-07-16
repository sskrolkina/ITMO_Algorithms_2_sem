#include <iostream>
#include <vector>
#include <queue>

#define maxN 101

std::vector<bool> visited;
std::vector<std::vector<int>> help;
int N;

bool bfs(int s, int f,int *mama)
{

  std::queue<int> q;
  q.push(s);
  mama[s] = -1;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i = 0; i < N; i++) {
      if (!visited[i] && help[u][i] > 0) {
        q.push(i);
        mama[i] = u;
        visited[i] = true;
      }
    }
  }
  return visited[f];
}

int Ff(int s, int f) {
  visited.assign(N,false);
  int mama[N];
  int k;
  int max = 0;
  while (bfs(s, f,mama)) {
    visited.assign(N,false);
    int path = 1000000000;
    for (int i = f; i != s; i = mama[i]) {
      k = mama[i];
      path = std::min(path, help[k][i]);
    }

    for (int i = f; i != s; i = mama[i]) {
      k = mama[i];
      help[k][i] -= path;
      help[i][k] += path;
    }
    max += path;
  }
  return max;
}

int main(){
  int M;
  int a;
  int b;
  int c;

  std::cin >> N >> M;

  help.assign(N,std::vector<int>(M,{}));

  for(int i = 0; i < M; i++){
    std::cin >> a >> b >> c;
    help[a - 1][b - 1] = c;
  }

  std::cout << Ff(0,N-1);
}
