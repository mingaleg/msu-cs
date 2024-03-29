#include <iostream>
#include <math.h>

using 
  namespace std;
  
int main(){
    long double a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b > a)
        swap(a, b);
    if (d > c) 
        swap(c, d);
    long double k = c / d;
    if (a / b >= k)
        if ((c > a) || (d > b))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    else {
        long double b2 = (k * a - b) / (k * k - 1);
        long double b1 = b - b2, a1 = k * b2;
        long double c1 = sqrt(a1 * a1 + b1 * b1);
        if (c1 < c) 
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
