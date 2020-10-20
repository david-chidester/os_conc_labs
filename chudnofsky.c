#include <stdio.h>
#include <math.h>

unsigned long long int facTR(unsigned long long int n, unsigned long long int a){
    if (n == 0) return a;
    return facTR(n-1, n*a);
}
unsigned long long int fac(unsigned long long int n){
    return facTR(n, 1);
}

long double chudnofskyTR (int q){
    long long int numerator = (pow(-1, q) * fac(6*q) * (545140134*q + 13591409));
    long double denominator = fac(3*q) * fac(q)*fac(q)*fac(q) * pow(640320, (3*q)+1.5);
    return numerator/denominator;

}

long double chudnofsky (int itter){
    long double ans = 0;
    for (int i = 0; i < itter; i++)
        ans += chudnofskyTR(i);
    ans*=12;
    return pow(ans, -1);
}

int main(){
    // IEEE floats can only store enough for 15 digits of pi
    printf("%.14LF\n",chudnofsky(6));
    return 0;
}