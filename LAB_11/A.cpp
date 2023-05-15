#include <iostream>
#include <vector>

int main(){
  int N;
  int M;
  int K;
  int Q;
  int s;
  int f;
  int w;
  int INF = 10000000;

  std::cin >> N >> M >> K;

  int graph[N][N];

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      graph[i][j] = INF;
    }
  }

  for(int i = 0; i < M; i++){
    std::cin >> s >> f >> w;
    graph[s - 1][f - 1] = w;
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      for(int z = 0; z < N; z++){
        if(abs(j - i) <= K && abs(i - z) <= K){
          graph[j][z] = std::min(graph[j][z],graph[j][i] + graph[i][z]);
        }
      }
    }
  }

  std::cin >> Q;

  for(int i = 0; i < Q; i++){
    std::cin >> s >> f;
    if(graph[s - 1][f - 1] < INF){
      std::cout << graph[s - 1][f - 1] << '\n';
    }
    else{
      std::cout << -1 << '\n';
    }
  }

}
