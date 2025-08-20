#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
float f(float x)
{
    return (x * log10(x) - 1.2);
}
float df(float x)
{
    return (log10(x) + 0.434294481);
}
int main()
{

    int maxitr, itr = 0;
    float err, x0, x1, h;
    cout << "Enter the value of approximated root: ";
    cin >> x0;
    cout << "Enter the value of allowed error: ";
    cin >> err;
    cout << "Enter the value of maximum iterations: ";
    cin >> maxitr;
    cout << fixed;
    for (itr = 1; itr <= maxitr; itr++)
    {
        h = f(x0) / df(x0);
        x1 = x0 - h;
        cout << "Iteration no. " << setw(2) << itr << ", x= " << setw(7) << setprecision(6) << x1 << endl;
        if (fabs(h) < err)
        {
            cout << "\nAfter " << itr << " iterations, root = " << setprecision(6) << x1 << endl;
            return 0;
        }
        x0 = x1;
    }
    cout << "Solution does not converge, iterations not sufficient" << endl;
}