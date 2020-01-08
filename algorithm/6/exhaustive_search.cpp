#include <stdio.h>
#include <set>
#include <iostream>

void saveSum(int a, std::set<int> *set) {
  std::set<int> set2;
  set2.insert(a);
  std::set<int>::iterator it = set -> begin();
  std::set<int>::iterator end = set -> end();
  while (it != end) {
    set2.insert(a + *it);
    it++;
  }
  it = set2.begin();
  end = set2.end();
  while (it != end) {
    set -> insert(*it);
    it++;
  }
}

int main() {
    int n;
    scanf("%d", &n);
    std::set<int> set;
    for (int i=0; i<n; i++) {
      int a;
      scanf("%d", &a);
      saveSum(a, &set);
    }
    int q;
    scanf("%d", &q);
    for (int i=0; i<q; i++) {
      int m;
      scanf("%d", &m);
      std::set<int>::iterator it = set.find(m);
      printf("%d\n", *it);
      if (it != set.end()) {
        printf("%s\n", "yes");
      } else {
        printf("%s\n", "no");
      }
    }

    return 0;
}