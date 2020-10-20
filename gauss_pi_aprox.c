/* Gauss Legendre algorithm implimentation by David Chidester 
This algorithm aproximates pi */
#include <stdio.h>
#include <math.h>

double gauss_legendre(int itter){
    double a = 1;
    double b = 1/sqrt(2);
    double t = 0.25;
    double p = 1;
    for (int i = 0; i < itter; i++){
        double a_n = a;
        double b_n = b;
        double t_n = t;
        double p_n = p;
        a = (a_n + b_n)/2;
        b = sqrt(a_n*b_n);
        t = t_n - (p_n * ((a_n - a)*(a_n - a)));
        p*=2;
    }
    return (a+b)*(a+b)/(4*t);
}

int main(){
    // IEEE floats can only store enough for 15 digits of pi
    double pi = gauss_legendre(6);
    printf("%.14lf\n", pi);
    return 0;
}