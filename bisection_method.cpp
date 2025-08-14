#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
float f(float x)
{
    return (x * x * x - 4 * x - 9);
}
float bisect(float a, float b, float *x, int *itr)
{
    *x = (a + b) / 2;
    ++(*itr);
    cout << "Iteration no. " << setw(3) << *itr << ", x= " << setw(7) << setprecision(5) << *x << endl;
}
int main()
{
    int maxitr, itr = 0;
    float a, b, err, x, x1;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    if (f(a) * f(b) >= 0)
    {
        cout << "The initial interval [" << a << "," << b << "]" << " does not bracket a root\n";
        return 1;
    }
    cout << "Enter the value of allowed error: ";
    cin >> err;
    cout << "Enter the value of maximum iterations: ";
    cin >> maxitr;
    bisect(a, b, &x, &itr);
    x1 = x;
    do
    {
        if (f(a) * f(x) < 0)
            b = x;
        else
            a = x;
        bisect(a, b, &x, &itr);
        if (fabs(x - x1) < err)
        {
            cout << "\nAfter " << itr << " iterations, root = " << setprecision(4) << x << endl;
            return 0;
        }
        x1 = x;
    } while (itr < maxitr);
    cout << "Solution does not converge, iterations not sufficient" << endl;
}