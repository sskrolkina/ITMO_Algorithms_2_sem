#include <iostream>
#include <vector>

int* p;
int* r;

int get(int a){
  if (a == p[a])
    return a;
  return (p[a] = get(p[a]));
}

void join(int a, int b){
  a = get(a);
  b = get(b);
  if (a != b) {
    if (r[a] > r[b]) std::swap(a, b);
    r[b] += r[a];
    p[a] = b;
  }

}

int main() {
  int N;
  int M;
  int Q;
  int a;
  int b;
  char command;
  std::vector<std::vector<int>> city;
  std::vector<char> cmnd;
  std::vector<int> nums;
  std::vector<std::string> ans;

  std::cin >> N >> M >> Q;

  p = new int[N];
  r = new int[N];

  for (int i = 0; i < N; i++) {
    p[i] = i;
    r[i] = 0;
    city.emplace_back();
  }

  for (int i = 0; i < M; i++) {
    std::cin >> a >> b;
    a--;
    b--;

    city[a].push_back(b);
    city[b].push_back(a);
  }

  for (int i = 0; i < Q; i++) {
    std::cin >> command >> a >> b;
    a--;
    b--;

    cmnd.push_back(command);
    nums.push_back(a);
    nums.push_back(b);

    if (command == '-') {
      for (int j = 0; j < city[a].size(); j++) {
        if (city[a][j] == b) {
          city[a].erase(city[a].begin() + j);
        }
      }
      for (int j = 0; j < city[b].size(); j++) {
        if (city[b][j] == a) {
          city[b].erase(city[b].begin() + j);
        }
      }
    }
  }

  for (int i = 0; i < city.size(); i++) {
    for (int j = 0; j < city[i].size(); j++) {
      join(i, city[i][j]);
    }
  }

  int k = nums.size() - 1;
  for (int i = Q - 1 ; i >= 0; i--) {
    if (cmnd[i] == '?') {

      if (get(nums[k - 1]) == get(nums[k])) {
        ans.emplace_back("YES");
      }

      else {
        ans.emplace_back("NO");
      }
    }

    else {
      join(nums[k - 1], nums[k]);
    }
    k = k - 2;
  }

  for (int i = ans.size() - 1; i >= 0; i--) {
    std::cout << ans[i] << '\n';
  }
}
