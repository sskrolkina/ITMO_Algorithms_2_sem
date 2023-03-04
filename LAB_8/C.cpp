#include <iostream>
#include <vector>

int main() {
  int s;
  std::cin >> s;
  std::string Ham;

  while (std::cin >> Ham) {
    int dig;
    std::vector<int>control;
    std::vector <int> code;
    std::vector<int> result;
    int sum;

    control.push_back(0);
    code.push_back(0);
    int n = 1;
    for(int i = 1;i < Ham.length();i++){
      dig = (Ham[i] - '0');
      if(i == (n * 2) - 1) {
        control.push_back(i);
        n *= 2;
      }
      code.push_back(dig);
    }
    for(int i : control){
      code[i] = 0;
    }
    for(int i : control){
      sum = 0;
      for(int j = i;j < code.size();j += (i + 1) * 2){
        n = j;
        while(n < j +(i + 1) && n < code.size()){
          sum += code[n];
          n++;
        }
      }
      code[i] = sum % 2;
    }
    sum = 0;
    bool f = false;
    for(int i : control){
      dig = Ham[i] - '0';
      if(code[i] != dig){
        sum += (i + 1);
        f = true;
      }
    }
    if(f){
      if(code[sum-1] == 0)code[sum-1] = 1;
      else code[sum-1] = 0;
    }
    n = 1;
    for(int i = 1;i < code.size();i++){
      if(i == (n * 2) - 1) {
        n *= 2;
      }
      else result.push_back(code[i]);
    }

    for(int i : result){
      std::cout << i;
    }
    std::cout << '\n';
  }
}
