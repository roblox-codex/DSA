#include <iostream>
#include <random>

using namespace std;

double estimatePi(int numSamples) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(-1.0, 1.0);

    int numInsideCircle = 0;

    for (int i = 0; i < numSamples; i++) {
        double x = dis(gen);
        double y = dis(gen);
        double distance = x * x + y * y;

        if (distance <= 1.0) {
            numInsideCircle++;
        }
    }

    return 4.0 * numInsideCircle / numSamples;
}

int main() {
    int numSamples;
    cout << "Enter the number of samples: ";
    cin >> numSamples;

    double pi = estimatePi(numSamples);
    cout << "Estimated value of Pi: " << pi << endl;

    return 0;
}
