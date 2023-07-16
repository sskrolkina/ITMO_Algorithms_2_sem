#include <iostream>
#include <vector>
#include <cmath>

int h(int k, int n){
  return (k + 1000000) % (3 * n);
}

int factorial(int S) {
  int x = 1;
  while(S != 0){
    x = x * S;
    S--;
  }
  return x;
}

int main(){
  int n;
  int x;
  std::cin >> n;
  std::vector<std::vector<int>> S;
  std::vector<int> help;

  for(int i = 0; i < (3 * n); i++){
    S.emplace_back();
  }

  for(int i = 0;i < n; i++) {
    std::cin >> x;
    help.push_back(x);
  }

  for(int i = 0; i < n; i++){
    S[h(help[i] - i,n)].push_back(help[i]);
  }

  int result = 0;
  int k = 2;

  for(int i = 0; i < S.size(); i++) {
    int f = S[i].size();
    int o = abs(f - 2);
    result += factorial(f) / (2* factorial(o));
  }

  std::cout << result;

}
