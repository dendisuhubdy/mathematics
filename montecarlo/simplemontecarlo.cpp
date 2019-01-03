#include <iostream>
#include <random>

#define PI 3.14159265359

using namespace std;

double SimpleMonteCarlo()
{
    double rangeMin = 0;
    double rangeMax = PI;

    size_t numSamples = 10000;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(rangeMin, rangeMax);

    double ySum = 0.0;
    for (size_t i = 1; i <= numSamples; ++i)
    {
        // generate random number
        double x = dist(mt);
        // compute the function
        double y = sin(x) * sin(x);
        // accumulate in Sum
        ySum += y;
    }

    double yAverage = ySum / double(numSamples);

    double width = rangeMax - rangeMin;
    double height = yAverage;

    return width * height;
}

int main()
{
    double x;
    x = SimpleMonteCarlo();
    cout << "Simple Monte Carlo result :" << endl;
    cout << x << endl;
}
