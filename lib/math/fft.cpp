#include <vector>
#include <complex>
using namespace std;

// 参照：https://www.creativ.xyz/fast-fourier-transform/
// http://www.prefield.com/algorithm/math/fft.html
// https://atcoder.jp/contests/atc001/submissions/19020598

typedef complex<double> Complex;
const Complex I(0, 1);

vector<Complex> fft(vector<Complex> a, bool inverse = false) {
    int n = a.size();
    double theta = (inverse ? 2*M_PI/n : -2*M_PI/n);
    for (int m = n; m >= 2; m /= 2) {
        int mh = m/2;
        for (int i = 0; i < mh; i++) {
            Complex w = exp(i*theta*I);
            for (int j = i; j < n; j += m) {
                int k = j + mh;
                Complex x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        theta *= 2;
    }
    int i = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
    if (inverse) {
        for (int i = 0; i < n; i++) a[i] /= n;
    }
    return a;
}

vector<Complex> fft(vector<double> a, bool inverse = false) {
    vector<Complex> a_complex(a.size());
    for (int i = 0; i < a.size(); i++) {
        a_complex[i] = Complex(a[i], 0);
    }
    return fft(a_complex, inverse);
}

vector<double> convolve(vector<double> a, vector<double> b) {
    int s = a.size() + b.size() - 1; 
    int t = 1; 
    while (t < s) t *= 2;
    a.resize(t);
    b.resize(t); 
    vector<Complex> A = fft(a);
    vector<Complex> B = fft(b);
    for (int i = 0; i < t; i++) {
        A[i] *= B[i]; 
    }
    A = fft(A, true); 
    a.resize(s);      
    for (int i = 0; i < s; i++) a[i] = A[i].real(); 
    return a;
}