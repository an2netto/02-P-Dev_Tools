
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>
#include <time.h>
#include "dft.h"

/**
 * timespec_diff() - returns time difference in milliseconds for two timespecs.
 * @stop:	time after event.
 * @start:	time before event.
 *
 * Uses difftime() for time_t seconds calculation.
 */
static double timespec_diff(struct timespec *stop, struct timespec *start)
{
	double diff = difftime(stop->tv_sec, start->tv_sec);
	diff *= 1000;
	diff += (stop->tv_nsec - start->tv_nsec) / 1e6;
	return diff;
}

int main(int argc, char *argv[]) 
{
        SNDFILE *fin;
        FILE *fout;
        SF_INFO input_info;
        float *sig, *spec, mag, sr;
        int size, i, k, read;
        double diff;

        struct timespec time_now, time_after;

        if(!(fin = sf_open(argv[1], SFM_READ, &input_info))) {
                printf("could not open %s\n", argv[1]);
                exit(-1);
        }
  
        size = atoi(argv[2]);//input_info.frames;
        sr = input_info.samplerate;
        sig = malloc(size * sizeof *sig);
        spec = malloc(size * 2 * sizeof *spec);
        read = sf_read_float(fin,sig,size);

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_now);
        dft(sig, spec, size);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_after);

        diff = timespec_diff(&time_after, &time_now);

        printf("%.6f", diff);
        
        /*
        fout = fopen("spec.txt","w");
        fprintf(fout,"sr %.0f\n", sr);
        fprintf(fout,"size %d\n", size);
        for (i=0, k=0; i<size; i++, k+=2) {
                if (i<size/2) {
                        mag = sqrt(spec[k]*spec[k] + spec[k+1]*spec[k+1])*2;
                        fprintf(fout,"[%.1f] %1.2f\n", i*sr/size, mag); 
                }
        }
        */
        

        sf_close(fin);
        //fclose(fout);
        free(sig);
        free(spec);
        return 0;	
}
