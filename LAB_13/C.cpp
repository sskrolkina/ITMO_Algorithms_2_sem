#include <iostream>
#include <vector>

long long h(long long k, long long n){
  return(k % 228) % (2*n);
}

long long g(long long k, long long n){
  return k % ((2*n) - 1) + 1;
}

long long H(long long k, long long n, long long i){
  return (h(k,n) + i * g(k,n)) % (2*n);
}

int main(){
  long long N;
  long long x;

  std::cin >> N;

  std::vector<long long> hash(2*N,-1);

  for(int i = 0; i < N; i++){
    std::cin >> x;

    for(int j = 0; j < 2* N; j++){
      if(hash[H(x,N,j)] == -1){
        hash[H(x,N,j)] = x;
        break;
      }
    }
  }

  for(int i = 0; i < N; i++){
    std::cin >> x;

    for(int j = 0; j < 2*N && hash[H(x, N, j)] != x; j++){
      if(hash[H(x,N,j)] == -1){
        std::cout << "NO";
        return 0;
      }
    }
  }

  std::cout << "YES";
}
