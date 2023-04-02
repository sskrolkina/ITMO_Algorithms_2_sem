#include <iostream>
#include <vector>
#include <string>

void Gray(int n){
  std::vector<std::string> result;

  result.emplace_back("0");
  result.emplace_back("1");

  for(int i = 2; i < (1 << n); i = i << 1){
    for(int j = i - 1; j >= 0; j--){
      result.emplace_back(result[j]);
    }
    for(int j = 0; j < i; j++){
    result[j] = "0" + result[j];
    }
    for(int j = i; j < 2 * i; j++){
      result[j] = "1" + result[j];
    }
  }
  for(int i = 0; i < result.size(); i++){
    std::cout << result[i] << '\n';
  }
}

int main(){
  int n;
  std::cin >> n;
  Gray(n);
}
