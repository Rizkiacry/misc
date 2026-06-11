#include <iostream>
using namespace std;

int main() {
  int a[11], x, i;
  i = 0;
  while (i <= 5) {
    cin >> x;
    a[i] = x;
    i++;
  }
  for (i = 0; i <= 5; i++) {
    cout << a[i] << " ";
  }
}
