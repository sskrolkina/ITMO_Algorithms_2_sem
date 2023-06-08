#include <iostream>
#include <vector>

int N;
int max = 1000000000;
std::vector<int> key;
std::vector<bool> mst;

int min(){
  int m = max;
  int mini;

  for(int i = 0; i < N; i++){
    if(!mst[i] && key[i] < m){
      m = key[i];
      mini = i;
    }
  }
  return mini;
}

int main(){
  int result;
  int M;
  int a;
  int b;
  int c;

  std::cin >> N >> M;

  int graph[N][N];

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      graph[i][j] = 0;
    }
  }

  for(int i = 0; i < M;i++){
    std::cin >> a >> b >> c;
    graph[a-1][b-1] = c;
    graph[b-1][a-1] = c;
  }

  int mama[N];
  key.assign(N,max);
  mst.assign(N,false);

  key[0] = 0;
  mama[0] = -1;

  for(int i = 0; i < N - 1; i++){
    int v = min();
    mst[v] = true;

    for(int j = 0; j < N; j++){
      if(graph[v][j] && !mst[j] && graph[v][j] < key[j]){
        mama[j] = v;
        key[j] = graph[v][j];
      }
    }
  }

  for(int i = 1; i < N;i++){
    result += graph[i][mama[i]];
  }

  std::cout << result;
}
