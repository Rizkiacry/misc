#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << setw(10) << "NIP" 
         << setw(10) << "Nama" 
         << setw(5) << "Gol" << endl;
    cout << setw(10) << "123" 
         << setw(10) << "John Doe" 
         << setw(5) << "1" << endl;
    return 0;
}
