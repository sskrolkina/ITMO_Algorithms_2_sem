#include <iostream>
#include <vector>

int main(){
  int N;
  int M;
  int s;
  int f;
  int w;
  int INF = 10000000;

  std::cin >> N >> M;

  int graph[N][N];
  int max = 0;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      graph[i][j] = INF;
    }
  }

  for(int i = 0; i < M; i++){
    std::cin >> s >> f >> w;
    graph[s - 1][f - 1] = w;
    graph[f - 1][s - 1] = w;
  }

  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(graph[i][k] < INF && graph[k][j] < INF){
          graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
        }
      }
    }
  }

  for(int i = 0; i < N; i++){
    graph[i][i] = 0;
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(graph[i][j] > max && graph[i][j] != INF){
        max  = graph[i][j];
      }
    }
  }
  std::cout << max;
}
