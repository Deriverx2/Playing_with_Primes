#include <iostream>
#include <vector>
#include <cmath>

using std::cin, std::cout, std::endl, std::vector;
using Int = unsigned long long;

void Sieve(Int n) {
    // if (n >= 2) {
    //     cout << "2 ";
    // }
    // if (n >= 3) {
    //     cout << "3 ";
    // }
    if (n < 5)
        return;
    vector<bool> sieveList(n, false);  // Change here
    int operations=0;
    for (int i = 1; i * i < n; i++) {
        int guess;
        int x = i * i;
        for (int j = 1; j * j < n; j++) {
            operations++;
            int y = j * j;
            guess = (4 * x) + (y);
            if (guess <= n && (guess % 12 == 1 || guess % 12 == 5))
                sieveList[guess] = !sieveList[guess];
            guess = (3 * x) + (y);
            if (guess <= n && guess % 12 == 7)
                sieveList[guess] = !sieveList[guess];
            guess = (3 * x) - (y);
            if (i > j && guess <= n && guess % 12 == 11)
                sieveList[guess] = !sieveList[guess];
        }
    }

    for (int r = 5; r * r <= n; r++) {
        if (sieveList[r]) {
            for (int i = r * r; i <= n; i += r * r) {
                sieveList[i] = false;
                operations++;
            }
        }
    }
    cout<<operations<<"+";

    // Printing primes from 5
    // for (int a = 5; a < n; a++) {
    //     if (sieveList[a])
    //         cout << a << " ";
    // }
}

int main() {
    cout << "Calculate primes in a given range" << endl;
    Int n;
    cout << "Enter a positive number: ";
    cin >> n;
    // cout << "Prime numbers:";
    Sieve(n);
    return 0;
}
