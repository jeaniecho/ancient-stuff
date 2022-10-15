#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;

    if (a <= 100000 && a > 0) {
        for (int b = 1; b <= a; b++) {
            cout << b << endl;
        }
    }
}
