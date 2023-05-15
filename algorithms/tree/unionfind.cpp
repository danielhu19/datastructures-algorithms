#include <iostream>

class UF {
 private:
  int count;
  int *parent;  // parent[i] = parent of i

 public:
  UF(int n) {
    // not connected at first
    this->count = n;
    parent = new int[n];
    // initialize parent[i] = -1
    for (int i = 0; i < n; i++) {
      parent[i] = -1;
    }
  }

  /* time complexity of below three functions is O(n) */
 public:
  /* union two nodes */
  void myUnion(int p, int q) {
    int rootP = myFind(p);
    int rootQ = myFind(q);
    if (rootP == rootQ) return;
    parent[rootP] = rootQ;  // or parent[rootQ] = rootP;
    count--;
  }

  /* return the root of given node `x` */
  int myFind(int x) {
    while (parent[x] >= 0) {
      x = parent[x];
    }
    return x;
  }

  /* return the number of connected components */
  int myCount() { return count; }

  /* return true if two nodes are connected */
  bool connected(int p, int q) { return myFind(p) == myFind(q); }
};