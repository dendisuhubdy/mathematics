#include <iostream>
#include <random>

#define PI 3.14159265359

using namespace std;

double GeneralMonteCarlo()
{
    size_t numSamples = 10000;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0f, 1.0f);

    auto InverseCDF = [](double x) -> double
    {
        return x * PI;
    };

    auto PDF = [](double x) -> double
    {
        return 1.0f / PI;
    };

    double estimateSum = 0.0;
    for (size_t i = 1; i <= numSamples; ++i)
    {
        // generate random number
        double rnd = dist(mt);
        double x = InverseCDF(rnd);
        double y = sin(x) * sin(x);
        double pdf = PDF(x);
        double estimate = y/pdf;

        estimateSum += estimate;
    }

    double estimateAverage = estimateSum / double(numSamples);

    return estimateAverage;
}

int main()
{
    double x;
    x = GeneralMonteCarlo();
    cout << "General Monte Carlo result :" << endl;
    cout << x << endl;
}
