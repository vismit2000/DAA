// https://cp-algorithms.com/algebra/fft.html

// simple recursive implementation of the FFT and the inverse FFT, both in one function

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

/*
The function gets passed a vector of coefficients, and the function will compute the DFT or inverse DFT and store the result
again in this vector. The argument invert shows whether the direct or the inverse DFT should be computed. Inside the function
we first check if the length of the vector is equal to one, if this is the case then we don't have to do anything. Otherwise
we divide the vector a into two vectors a0 and a1 and compute the DFT for both recursively. Then we initialize the value wn 
and a variable w, which will contain the current power of wn. Then the values of the resulting DFT are computed using the 
above formulas.

If the flag invert is set, then we replace wn with wn−1, and each of the values of the result is divided by 2 (since this 
will be done in each level of the recursion, this will end up dividing the final values by n).
*/

// function for multiplying two polynomials:

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

// function for multiplying two long numbers

int carry = 0;
for (int i = 0; i < n; i++)
    result[i] += carry;
    carry = result[i] / 10;
    result[i] %= 10;
}
