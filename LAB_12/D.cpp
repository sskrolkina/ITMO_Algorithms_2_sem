#include <iostream>
#include <vector>

int N;
int M;

std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> help;
std::vector<bool> visited;
std::vector<int> mt;

bool KUN(int i) {
  if (visited[i]) {
    return false;
  }

  visited[i] = true;

  for (int to : help[i]) {
    if (mt[to] == -1 || KUN(mt[to])) {
      mt[to] = i;
      return true;
    }
  }

  return false;
}

int main(){
  int Q;
  int a;
  int b;
  int k1 = 0;
  int k2 = 0;
  int max = 1000000000;
  int result = 0;

  std::cin >> N >> M >> Q;

  graph.assign(N,std::vector<int>(M, 1));

  for (int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if((i + j) % 2 == 0) {
        graph[i][j] = k2;
        k2++;
      }
      else {
        graph[i][j] = k1;
        k1++;
      }
    }
  }

  help.assign(k1,std::vector<int>(0, 0));

  for(int s = 0; s < Q; s++) {
    std::cin >> a >> b;
    graph[a - 1][b - 1] = max;
  }

  for (int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(graph[i][j] != max) {
        if((i + j) % 2 != 0) {
          if(i > 0 && graph[i - 1][j] != max) {
            help[graph[i][j]].push_back(graph[i - 1][j]);
          }
          if(j > 0 && graph[i][j - 1] != max) {
            help[graph[i][j]].push_back(graph[i][j - 1]);
          }
          if(j < M - 1 && graph[i][j + 1] != max) {
            help[graph[i][j]].push_back(graph[i][j + 1]);
          }
          if(i < N - 1 && graph[i + 1][j] != max) {
            help[graph[i][j]].push_back(graph[i + 1][j]);
          }
        }
      }
    }
  }

  mt.assign(k2,-1);

  for(int i = 0; i < help.size(); i++){
    visited.assign(N*M+1,false);
    if(KUN(i)){
      result++;
    }
  }


  std::cout << 2 * result;

}
