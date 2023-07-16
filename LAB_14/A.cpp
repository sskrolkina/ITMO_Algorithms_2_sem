#include <iostream>
#include <vector>

std::vector<int> FindString(std::string s, std::string p)
{
  int n = s.size();
  int m = p.size();
  std::vector<int> answer;

  for (int i = 0; i < n; i++)
  {
    if (s[i] == p[0])
    {
      if (m != 1)
        for (int j = 1; j < m; j++)
        {
          if (s[i + j] == p[j])
          {
            if (j == m - 1)
              answer.push_back(i);
            continue;
          }
          else
            break;
        }
      else
        answer.push_back(i);
    }
  }
  return answer;
}

int main()
{
  std::string s;
  std::string p;
  std::cin >> s >> p;

  std::vector<int> str;
  str = FindString(s, p);

  std::cout << str.size() << "\n";
  for (int i: str)
  {
    std::cout << i << " ";
  }
  return 0;
}
