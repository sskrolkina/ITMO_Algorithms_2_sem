#include <iostream>
#include <vector>

int main() {
  int n, m, K;
  std::string Masha;
  std::string Sasha;

  std::cin >> n >> m >> K;
  std::cin >> Masha >> Sasha;

  int count = 0;
  int j = 0;
  int dif = 0;
  int res = 0;

  std::vector<int> numbers;
  std::vector<char> symbols;

  std::vector<int> numbers1;
  std::vector<char> symbols1;

  for (char i : Masha) {
    if (isdigit(i)) {
      count = count * 10 + (i - '0');
    } else {
      numbers.push_back(0);
      numbers[j] += count;
      symbols.push_back(i);
      count = 0;
      j++;
    }
  }
  numbers.push_back(0);
  numbers[j] += count;
  count = 0;
  j = 0;

  for (char i : Sasha) {
    if (isdigit(i)) {
      count = count * 10 + (i - '0');
    } else {
      numbers1.push_back(0);
      numbers1[j] += count;
      symbols1.push_back(i);
      count = 0;
      j++;
    }
  }
  numbers1.push_back(0);
  numbers1[j] += count;

  int i = 0;
  int f = 0;

  while(i + 1 < numbers.size() && f + 1 < numbers1.size()) {
    if (numbers[i + 1] > numbers1[f + 1]) {
      if (symbols[i] == symbols1[f]) {
        numbers[i + 1] -= numbers1[f + 1];
        f++;
      } else {
        res += numbers1[f + 1];
        numbers[i + 1] -= numbers1[f + 1];
        f++;
      }
    } else if (numbers[i + 1] == numbers1[f + 1]) {
      if (symbols[i] == symbols1[f]) {
        i++;
        f++;
      } else {
        res += numbers[i + 1];
        i++;
        f++;
      }
    } else {
      if (symbols[i] == symbols1[f]) {
        numbers1[f + 1] -= numbers[i + 1];
        i++;
      } else {
        res += numbers[i + 1];
        numbers1[f + 1] -= numbers[i + 1];
        i++;
      }

    }
  }

  if (res < K) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
}
