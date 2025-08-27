#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
float f(float x)
{
    return (x * x * x - 2 * x - 5);
}
float secant(float a, float b, float &x, int &itr)
{
    x = (a * f(b) - b * f(a)) / (f(b) - f(a));
    ++(itr);
    cout << "Iteration no. " << setw(3) << itr << ", x= " << setw(9) << fixed << setprecision(6) << x << endl;
}
int main()
{
    int maxitr, itr = 0;
    float x0, x1, err, x;
    cout << "Enter the value of first guess: ";
    cin >> x0;
    cout << "Enter the value of second guess: ";
    cin >> x1;
    cout << "Enter the value of allowed error: ";
    cin >> err;
    cout << "Enter the value of maximum iterations: ";
    cin >> maxitr;
    do
    {
        if (f(x0) == f(x1))
        {
            cout << "Mathematical Error!\n";
            return 1;
        }
        secant(x0, x1, x, itr);
        if (fabs(x - x1) < err)
        {
            cout << "After " << itr << " iterations, root = " << fixed << setprecision(6) << x << endl;
            return 0;
        }
        x0 = x1;
        x1 = x;
    } while (itr < maxitr);
    cout << "Solution does not converge, iterations not sufficient" << endl;
    cout << "Finally calculated approximate root = " << fixed << setprecision(6) << x << endl;
}