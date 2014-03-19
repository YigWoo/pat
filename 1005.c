#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  int *a;
  a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  set<int> nums;
  for (int i = 0; i < n; i++) {
    int j = a[i];
    if (j % 2 == 0) j = j / 2;
    else j = (3 * j + 1) / 2;
    while (j != 1) {
      nums.insert(j);
      if (j % 2 == 0) j = j / 2;
      else j = (3 * j + 1) / 2;
    }
  }

  vector<int> keys;
  for (int i = 0; i < n; i++) {
    if (!nums.count(a[i])) keys.push_back(a[i]);
  }

  sort(keys.begin(), keys.end());
  for (int i = keys.size()-1; i >= 0; i--) {
    cout << keys[i];
    if (i != 0) cout << " ";
  }
}
