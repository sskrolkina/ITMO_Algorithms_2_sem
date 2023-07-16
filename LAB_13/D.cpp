#include <iostream>
#include <vector>

struct students{
  int g;
  int i;
  int p;
};

int h(int k, int n) {
  return k % n;
}


int main(){
  int M;
  int Q;
  char command;
  std::vector<int> result;
  int group;
  int isu;
  int points;

  std::cin >> M >> Q;


  std::vector<std::vector<students>> hash(M);

  for(int i = 0; i < Q; i++) {
    std::cin >> command;
    if (command == 'a') {
      std::cin >> group;

      int res = 0;
      int count = 0;

      for (int j = 0; j < hash[h(group, M)].size(); j++) {
        if (hash[h(group, M)][j].g == group) {
          res += hash[h(group, M)][j].p;
          count++;
        }
      }

      result.push_back(res / count);
    }

    else if (command == '-') {
      std::cin >> group >> isu;
      for (auto &j : hash[h(group, M)]) {
        if (j.i == isu) {
          j = {};
          break;
        }
      }
    }

    else if (command == '+') {
      std::cin >> group >> isu >> points;
      hash[h(group, M)].push_back({group, isu, points});
    }

    else if (command == 'm') {
      std::cin >> group;
      int max = -1000000000;
      for (int j = 0; j < hash[h(group, M)].size(); j++) {
        if (hash[h(group, M)][j].g == group) {
          if (max < hash[h(group, M)][j].p) {
            max = hash[h(group, M)][j].p;

          }
        }
      }
      result.push_back(max);
    }
  }

  for(int i : result){
    std::cout << i << '\n';
  }
}
