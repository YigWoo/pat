#include <iostream>

using namespace std;
int main() {
  int n;
  cin >> n;

  int d1, d2, d3;
  d1 = d2 = d3 = 0;

  d1 = n % 10;
  n = n / 10;
  if (n != 0) {
    d2 = n % 10;
    n = n / 10;
    if (n != 0) {
      d3 = n;
    }
  }

  if (d3 != 0)
    for (int i = 0; i < d3; i++) cout << 'B';
  if (d2 != 0)
    for (int i = 0; i < d2; i++) cout << 'S';
  if (d1 != 0)
    for (int i = 0; i < d1; i++) cout << i+1;
}
