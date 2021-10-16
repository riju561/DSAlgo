#include <bits/stdc++.h>
using namespace std;
 
// For storing complex values of nth roots
// of unity we use complex<double>
typedef complex<double> cd;
 
// Recursive function of FFT
vector<cd> fft(vector<cd>& a)
{
    int n = a.size();
 
    // if input contains just one element
    if (n == 1)
        return vector<cd>(1, a[0]);
 
    // For storing n complex nth roots of unity
    vector<cd> w(n);
    for (int i = 0; i < n; i++) {
        double alpha = -2 * M_PI * i / n;
        w[i] = cd(cos(alpha), sin(alpha));
    }
 
    vector<cd> A0(n / 2), A1(n / 2);
    for (int i = 0; i < n / 2; i++) {
 
        // even indexed coefficients
        A0[i] = a[i * 2];
 
        // odd indexed coefficients
        A1[i] = a[i * 2 + 1];
    }
 
    // Recursive call for even indexed coefficients
    vector<cd> y0 = fft(A0);
 
    // Recursive call for odd indexed coefficients
    vector<cd> y1 = fft(A1);
 
    // for storing values of y0, y1, y2, ..., yn-1.
    vector<cd> y(n);
 
    for (int k = 0; k < n / 2; k++) {
        y[k] = y0[k] + w[k] * y1[k];
        y[k + n / 2] = y0[k] - w[k] * y1[k];
    }
    return y;
}
 
// Driver code
int main()
{
    int n;
    cout<<"Enter the no. of coefficients : ";
    cin>>n;
    
    vector<cd> a(n);
    for(int i = 0; i < n; i++)
    cin >> a[i];
    
    vector<cd> b = fft(a);
    
    cout << "The result :\n";
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << "\n";
    return 0;
}
