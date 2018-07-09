#include "dft.h"

const double twopi = 2*acos(-1.f);

void dft(float *in, float *out, int N)
{
        for (int i=0, k=0; k<N; i+=2, k++) {
                out[i] = out[i+1] = 0.f;
                for (int n=0; n<N; n++) {
                        out[i] += in[n]*cos(k*n*twopi/N);
                        out[i+1] -= in[n]*sin(k*n*twopi/N);
                }
                out[i] /= N;
                out[i+1] /= N;
        }
}
