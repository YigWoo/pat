#include <iostream>
#include <string>

struct Student {
  std::string name;
  std::string stuNo;
  int mark;
};

void exch(Student *a, Student *b) {
  Student tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int less(const Student& a, const Student& b) {
  if (a.mark < b.mark) return 1;
  return 0;
}

int partition(Student a[], int l, int r) {
  int i = l-1;
  int j = r;
  Student v = a[r];

  for (;;) {
    while (less(a[++i], v));
    while (less(v, a[--j])) if (j == l) break;
    if (i >= j) break;
    exch(&a[i], &a[j]);
  }
  exch(&a[i], &a[r]);
  return i;
}

void quicksort(Student a[], int l, int r) {
  int i;
  if (l >= r) return;
  i = partition(a, l, r);
  quicksort(a, l, i-1);
  quicksort(a, i+1, r);
}

int main() {
  int kase;
  std::cin >> kase;
  int j = kase;
  Student *a;
  a = new Student[kase];
  while (j--) {
    std::cin >> a[j].name >> a[j].stuNo >> a[j].mark;
  }
  quicksort(a, 0, kase-1);
  std::cout << a[kase-1].name << " " << a[kase-1].stuNo << std::endl;
  std::cout << a[0].name << " " << a[0].stuNo << std::endl;
  delete[] a;
  return 0;

}
