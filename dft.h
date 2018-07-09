#include <math.h>

/** 
 * dft() - convert time-domain signal
 *      to its frequency-domain representation
 * @in:	        waveform samples
 * @out:	frequency components (complex numbers)
 * @N:	        transform size
 *
 *
 */
void dft(float *in, float *out, int N);
