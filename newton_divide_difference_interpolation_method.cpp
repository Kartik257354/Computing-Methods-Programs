#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double d(double x[], double y[][10], int n){
    for(int j=1;j<n;j++){
        for(int i=0;i<n-j;i++){
            y[i][j]=(y[i+1][j-1]-y[i][j-1])/(x[i+j]-x[i]);
        }
    }
}
double p(double y[][10], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<setw(10)<<y[i][j];
        }
        cout<<endl;
    }
}
double c(double x[], double y[][10], int n,int value){
    double product=1;
    double sum=y[0][0];
    for(int j=1;j<n;j++){
        product*=value-x[j-1];
        sum+=product*y[0][j];
    }
    return sum;
}
int main(){
    int n;
    cout<< "Enter number of data points: ";
    cin>>n;
    cout<< "Enter data points (x,y):\n";
    double x[n],y[n][10];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i][0];
    }
    d(x,y,n);
    cout<<"Divide Difference Table:\n";
    p(y,n);
    double a;
    cout<<"Enter the value of x for interpolation: ";
    cin>>a;
    cout<<"Interpolated Value: "
    <<c(x,y,n,a);
}