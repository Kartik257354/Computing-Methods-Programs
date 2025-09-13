#include<iostream>
#include<cmath>
using namespace std;
double f(float x){
    return (1/(1+pow(x,2)));
}
int main()
{
    int n;
    float a,b;
    cout<<"Enter the lower limit of the integral: ";
    cin>>a;
    cout<<"Enter the upper limit of the integral: ";
    cin>>b;
    cout<<"Enter the number of grids: ";
    cin>>n;
    double y0=f(a);
    double yn=f(b);
    float h=(b-a)/n;
    float sum=0;
    float y;
    for(int i=0;i<n-1;i++){
        y=f(a+h);
        a+=h;
        sum+=y;
    }
    double i= (h/2)*(y0+yn+2*sum);
    cout<<"Value of integral is: "<<i;    
}