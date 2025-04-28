#include <iostream>
#include <cmath>
using namespace std;

double f(double c)
{
    return (667.38 / c) * (1 - exp(-10 * c / 68.1)) - 40;
}

double Bisection(double lb, double ub, double Es, int Imax)
{
    double mid = 0;
    double mid_old;
    double Ea = 100;
    int iter = 0;

    do
    {
        mid_old = mid;
        mid = (lb + ub) / 2.0;
        iter++;

        if (mid != 0)
        {
            Ea = fabs((mid - mid_old) / mid) * 100;
        }

        double test = f(lb) * f(mid);

        if (test < 0)
        {
            ub = mid;
        }
        else if (test > 0)
        {
            lb = mid;
        }
        else
        {
            Ea = 0;
        }


        cout << "Iteration " << iter << ": mid = " << mid << ", Ea = " << Ea << "%" << endl;


        if (Ea < Es || iter >= Imax)
        {
            break;
        }

    }
    while (true);

    return mid;
}

int main()
{
    double lb = 12.0;
    double ub = 16.0;
    double Es = 0.5;     // Stopping criterion (%)
    int Imax = 50;

    double root = Bisection(lb, ub, Es, Imax);

    cout << "\nThe root (drag coefficient c) is approximately: " << root << " kg/s" << endl;

    return 0;
}
