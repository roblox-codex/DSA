#include <iostream>
#include <random>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    if (n <= 3) {
        return true;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(2, n - 2);

    for (int i = 0; i < 5; i++) {
        int a = dis(gen);
        if (a % n == 0 || (int)pow(a, n - 1) % n != 1) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPrime(n)) {
        cout << n << " is probably prime." << endl;
    } else {
        cout << n << " is composite." << endl;
    }

    return 0;
}
