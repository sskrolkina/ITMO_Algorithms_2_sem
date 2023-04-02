#include <iostream>
#include <queue>

int dist[101][101][101];
bool andora[101][101][101];

struct place{
  int x;
  int y;
  int z;
};

void path(place s, int e){
  dist[s.x][s.y][s.z] = 1;
  std::queue<place> q;
  q.push(s);

  while(!q.empty()){
    place v = q.front();
    q.pop();
    andora[v.x][v.y][v.z] = true;
    if(dist[v.x][v.y][v.z] > e) continue;
    if(!andora[v.x + 1][v.y][v.z] && v.x + 1 < 101){
      andora[v.x + 1][v.y][v.z] = true;
      dist[v.x + 1][v.y][v.z] = dist[v.x][v.y][v.z] + 1;
      q.push({v.x + 1,v.y,v.z});
    }
    if(!andora[v.x][v.y + 1][v.z] && v.y + 1 < 101){
      andora[v.x][v.y + 1][v.z] = true;
      dist[v.x][v.y + 1][v.z] = dist[v.x][v.y][v.z] + 1;
      q.push({v.x,v.y + 1,v.z});
    }
    if(!andora[v.x][v.y][v.z + 1] && v.z + 1 < 101){
      andora[v.x][v.y][v.z + 1] = true;
      dist[v.x][v.y][v.z + 1] = dist[v.x][v.y][v.z] + 1;
      q.push({v.x,v.y,v.z + 1});
    }
    if(!andora[v.x - 1][v.y][v.z]&& v.x - 1 >= 0){
      andora[v.x - 1][v.y][v.z] = true;
      dist[v.x - 1][v.y][v.z] = dist[v.x][v.y][v.z] + 1;
      q.push({v.x - 1,v.y,v.z});
    }
    if(!andora[v.x][v.y - 1][v.z]&& v.y - 1 >= 0){
      andora[v.x][v.y - 1][v.z] = true;
      dist[v.x][v.y - 1][v.z ] = dist[v.x][v.y][v.z] + 1;
      q.push({v.x,v.y - 1,v.z});
    }
    if(!andora[v.x][v.y][v.z - 1]&& v.z - 1 >= 0){
      andora[v.x][v.y][v.z - 1] = true;
      dist[v.x][v.y][v.z - 1] = dist[v.x][v.y][v.z] + 1;
      q.push({v.x,v.y,v.z - 1});
    }
  }
}

int main(){
  int k;
  int e;
  int x;
  int y;
  int z;
  int h;

  std::cin >> k >> e;

  for(int i = 0; i < 101; i++){
    for(int j = 0; j < 101; j++){
      for(int b = 0; b < 101; b++){
        andora[i][j][b] = false;
        dist[i][j][b] = 0;
      }
    }
  }

  std::cin >> x >> y >> z;
  place s{x,y,z};

  std::cin >> x >> y >> z;
  place f{x,y,z};

  for(int i = 0; i < k; i++){
    std::cin >> x >> y >> z >> h;
    for(int j = z; j < z + h && j < 101; j++){
      andora[x][y][j] = true;
    }
  }

  path(s,e);

  std::cout << dist[f.x][f.y][f.z] - 1;
}
