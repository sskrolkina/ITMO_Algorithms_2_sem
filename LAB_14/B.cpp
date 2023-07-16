#include <vector>
#include <iostream>

int main() {
  std::string s;
  std::cin >> s;

  int n = s.length();
  std::vector<int> prefix(n);
  for (int i = 1; i < n; ++i) {
    int value = prefix[i - 1];
    while (value > 0 && s[i] != s[value])
      value = prefix[value - 1];

    if (s[i] == s[value])
      value++;
    prefix[i] = value;
  }

  for (int i : prefix)
    std::cout << i << " ";
}
