#include <iostream>
#include <vector>

std::vector<std::vector<int>> city;
std::vector<bool> colour;
std::vector<int> mama;
int cycle;

bool DFS(int v,int mom){
  colour[v] = true;
  for(int i : city[v]){
    if(i == mom) continue;
    if(colour[i]){
      cycle = i;
      return true;
    }
    mama[i] = v;
    if(DFS(i,mama[i])){
      return true;
    }
  }
  return false;
}

void Cycle(int N){
  colour.assign(N + 1, false);
  mama.assign(N + 1, -1);
  cycle = -1;

  for(int i = 0; i < N; i++){
    if(!colour[i] && DFS(i,mama[i])){
      break;
    }
  }
  if(cycle == -1){
    std::cout << "NO";
  }
  else{
    std::cout << "YES";
  }
}

int main(){
  int N;
  int M;
  int a;
  int b;
  std::cin >> N >> M;

  for(int i = 0; i < N + 1; i++){
    city.emplace_back();
  }

  for(int i = 0; i < M; i++){
    std::cin >> a >> b;
    city[a].push_back(b);
    city[b].push_back(a);
  }
  Cycle(N);
}
