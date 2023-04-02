#include <iostream>
#include <vector>

std::vector<std::vector<int>> flat;

void dfs(int i, int j){
  if(i < 0 || j < 0 || i >= flat.size() || j >= flat[0].size()){
    return;
  }
  if(flat[i][j] == 0){
    return;
  }

  flat[i][j] = 0;
  dfs(i + 1, j);
  dfs(i - 1, j);
  dfs(i , j + 1);
  dfs(i, j - 1);
}

int find(){
  int answer = 0;
  for(int i = 0; i < flat.size(); i++){
    for(int j = 0; j < flat[0].size(); j++){
      if(flat[i][j] == 1){
        dfs(i,j);
        answer++;
      }
    }
  }
  return answer;
}

int main(){
  int n;
  int m;
  char x;

  std:: cin >> n >> m;

  for(int i = 0; i < n; i++){
    std::vector<int> v;
    for(int j = 0; j < m; j++){
      std::cin >> x;
      if(x == '#'){
        v.push_back(0);
      }
      else{
        v.push_back(1);
      }
    }
    flat.push_back(v);
  }
  std::cout << find();
}
