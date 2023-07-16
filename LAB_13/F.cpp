#include <iostream>
#include <vector>


int h1(const std::string& str, int n) {
  int x = 0;

  for(auto i : str) {
    x += x * 228 + i;
  }
  return x % (1000001);
}

int h2(const std::string& str, int n) {
  int x = 0;

  for(auto i : str) {
    x += x * 228 + i;
  }
  return (x + 123) % (1000001);
}


void insert_a( std::vector<std::string>& first, std::string& x, int n) {
  int hash1 = h1(x,n);
  int hash2 = h2(x,n);

  if(first[hash1].empty()) {
    first[hash1] = x;
  }

  else if(first[hash2].empty()) {
    first[hash2] = x;
  }

  else {
    first[hash1] = x;
    while(!first[hash1].empty() && first[hash1] != x) {
      if(h1(first[hash1],n) == hash1) {
        std::swap(first[h2(first[hash1],n)], first[hash1]);
      } else {
        std::swap(first[h1(first[hash1],n)], first[hash1]);
      }
    }

    first[hash2] = x;
    while(!first[hash2].empty() && first[hash2] != x) {
      if(h1(first[hash2],n) == hash1) {
        std::swap(first[h2(first[hash2],n)], first[hash2]);
      } else {
        std::swap(first[h1(first[hash2],n)], first[hash2]);
      }
    }
  }
}

void insert_b(std::vector<std::string>& second, std::string& x, int n) {
  int hash1 = h1(x,n);
  int hash2 = h2(x,n);

  if(second[hash1].empty()) {
    second[hash1] = x;
  }

  else if(second[hash2].empty()) {
    second[hash2] = x;
  }

  else {
    second[hash1] = x;
    while(!second[hash1].empty() && second[hash1] != x) {
      if(h1(second[hash1],n) == hash1) {
        std::swap(second[h2(second[hash1],n)], second[hash1]);
      } else {
        std::swap(second[h1(second[hash1],n)], second[hash1]);
      }
    }

    second[hash2] = x;
    while(!second[hash2].empty() && second[hash2] != x) {
      if(h1(second[hash2],n) == hash1) {
        std::swap(second[h2(second[hash2],n)], second[hash2]);
      } else {
        std::swap(second[h1(second[hash2],n)], second[hash2]);
      }
    }
  }
}

void insert_c(std::vector<std::string>& third, std::string& x, int n) {
  int hash1 = h1(x,n);
  int hash2 = h2(x,n);

  if(third[hash1].empty()) {
    third[hash1] = x;
  }

  else if(third[hash2].empty()) {
    third[hash2] = x;
  }

  else {
    third[hash1] = x;
    while(!third[hash1].empty() && third[hash1] != x) {
      if(h1(third[hash1],n) == hash1) {
        std::swap(third[h2(third[hash1],n)], third[hash1]);
      } else {
        std::swap(third[h1(third[hash1],n)], third[hash1]);
      }
    }

    third[hash2] = x;
    while(!third[hash2].empty() && third[hash2] != x) {
      if(h1(third[hash2],n) == hash1) {
        std::swap(third[h2(third[hash2],n)], third[hash2]);
      } else {
        std::swap(third[h1(third[hash2],n)], third[hash2]);
      }
    }
  }
}

bool check(std::vector<std::string>& a, const std::string& x,int n) {
  return (a[h1(x,n)] == x) || (a[h2(x,n)] == x);
}



int main(){
  std::vector<std::string> a1;
  std::vector<std::string> b1;
  std::vector<std::string> c1;
  int n;
  std::string k;
  int score[3] = {0,0,0};


  std::cin >> n;

  std::vector<std::string> first(1000001);
  std::vector<std::string> second(1000001);
  std::vector<std::string> third(1000001);

  for(int i = 0;i < n;i++){
    std::cin >> k;
    insert_a(first,k,n);
    a1.push_back(k);
  }
  for(int i = 0;i < n;i++){
    std::cin >> k;
    insert_b(second,k,n);
    b1.push_back(k);
  }
  for(int i = 0;i < n;i++){
    std::cin >> k;
    insert_c(third,k,n);
    c1.push_back(k);
  }

  std::string t;
  for(int i = 0;i < n;i++){
    t = a1[i];
    if(!check(second,t,n) && !check(third,t,n)){
      score[0] += 3;
    }
    else if(check(second,t,n) && check(third,t,n)){
      score[0] += 0;
    }
    else score[0] += 1;
  }
  for(int i = 0;i < n;i++){
    t = b1[i];
    if(!check(first,t,n) && !check(third,t,n)){
      score[1] += 3;
    }
    else if(check(first,t,n) && check(third,t,n)) {
      score[1] += 0;
    }
    else score[1] += 1;
  }
  for(int i = 0;i < n;i++){
    t = c1[i];
    if(!check(first,t,n) && !check(second,t,n)){
      score[2] += 3;
    }
    else if(check(first,t,n) && check(second,t,n)){
      score[2] += 0;
    }
    else score[2] += 1;
  }


  for(int i : score){
    std::cout << i << " ";
  }
}
