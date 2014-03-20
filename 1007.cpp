#include <iostream>
#include <cmath>

using namespace std;

bool rabbinMiller(int n, int iter) {
}

bool primalityTest(int n) {
  if (n < 2) return false;
  if (n != 2 && n % 2 == 0) return false;

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}


int main() {
  int num;
  cin >> num;

  int count = 0;
  int p1 = 2, p2 = 3;

  int k = 4;
  while (k <= num) {
    int nextP = 0;
    for (; k++ < num; ) { // if you write k++ in last part, it will never be executed
      if (primalityTest(k)) {
        nextP = k;
        break;
      }
    }
    p1 = p2;
    p2 = nextP;
    if (p2 - p1 == 2) count++;
  }

  cout << count << endl;
  return 0;
}
