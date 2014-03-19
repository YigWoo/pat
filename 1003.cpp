#include <iostream>
#include <string>
using namespace std;

bool checkPAT(string str) {
  int np = 0;
  int nt = 0;
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] != 'P' && str[i] != 'A' && str[i] != 'T')
      return false;
    if ((str[i] == 'P' && ++np > 1) || (str[i] == 'T' && ++nt > 1)) {
      return false;
    }
  }
  return true;
}

bool isPattern(string pattern) {
  int n1 = 0;
  int n2 = 0;
  int n3 = 0;

  if (!checkPAT(pattern)) {
    return false;
  }

  int posP = pattern.find('P');
  int posT = pattern.find('T');

  if (posP >= posT-1 ) {
    return false;
  }

  n1 = posP;
  n2 = posT - posP - 1;
  n3 = pattern.length() - posT - 1;

  /*  cout << endl;
      cout << n1 << " " << n2 << " " << n3 << endl; */
  /* if (n2 == 0) return false; */
  if (n1 == 0 && n3 == 0) return true;
  else {
    if (n3 != n1 * n2) {
      return false;
    }
    return true;
  }
}

int main() {
  int kase;
  cin >> kase;
  for (int i = 0; i < kase; i++) {
    string pattern;
    cin >> pattern;
    bool res;
    res = isPattern(pattern);
    if (res) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
