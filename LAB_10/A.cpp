#include <iostream>
#include <vector>

std::vector<std::vector<int>> Hogwarts;
std::vector<int> rooms;
std::vector<bool> used;
std::vector<int> components;
std::vector<int> comps;

void dfs(int v,int count){
  used[v] = true;
  comps.push_back(v);
  components[v] = count;

  for(int i = 0; i < Hogwarts[v].size(); i++){
    int u = Hogwarts[v][i];
    if(!used[u]){
      dfs(u,count);
    }
  }
}

int main(){
  int n;
  int m;
  int a;
  int b;
  int count = 1;
  bool check = false;
  std::vector<int> safe;

  std::cin >> n >> m;

  Hogwarts.assign(n,{});
  used.assign(n,false);
  components.assign(n,0);

  for(int i = 0; i < m; i++){
    std::cin >> a >> b;
    Hogwarts[a - 1].push_back(b - 1);
    Hogwarts[b - 1].push_back(a - 1);
  }

  for(int i = 0; i < n; i++){
    std::cin >> a;
    rooms.push_back(a);
  }

  for(int i = 0; i < n; i++){
    if(!used[i]){
      comps.clear();
      dfs(i,count);
      count++;

      for(int j = 0; j < comps.size(); j++){
        if(rooms[comps[j]] == 1){
          check = true;
        }
      }
      if(check){
        safe.push_back(1);
        check = false;
      }
      else{
        safe.push_back(0);
      }
    }
  }
  std::cout << count - 1 << '\n';

  for(int i = 0; i < n; i++){
    std::cout << components[i] << " ";
  }
  std::cout << '\n';

  for(int i = 0; i < count - 1; i++){
    std::cout << safe[i] << " ";
  }
}
