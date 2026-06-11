#include <iostream>
using namespace std;

int main() {
  int x, i;
  int A[11];
  int z = 0;

  for (i = 0; i <= 10; i++) {
    cin >> x;

    if (x > 60) {
      A[z] = x;
      z++;
    }
  }

  cout << "output:" << endl;

  for (i = 0; i < z; i++) {
    cout << A[i] << " ";
  }
}
