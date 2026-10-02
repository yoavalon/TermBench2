#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

double* generate_sequence(int length) {
    double* sequence = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        sequence[i] = sin(2 * PI * i / length) + cos(4 * PI * i / length);
    }
    return sequence;
}

void process_signal(double* signal, int length) {
    while (1) {
        double* hanning_window = (double*)malloc(length * sizeof(double));
        for (int i = 0; i < length; i++) {
            hanning_window[i] = 0.5 * (1 - cos(2 * PI * i / (length - 1)));
        }

        double* filtered_signal = (double*)malloc(length * sizeof(double));
        for (int n = 0; n < length; n++) {
            filtered_signal[n] = 0;
            for (int k = 0; k < length; k++) {
                filtered_signal[n] += signal[k] * hanning_window[(n - k + length) % length];
            }
        }

        double* fft_signal = (double*)malloc(length * 2 * sizeof(double));
        for (int i = 0; i < length; i++) {
            fft_signal[2 * i] = filtered_signal[i];
            fft_signal[2 * i + 1] = 0;
        }

        fftw_complex* in = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * length);
        for (int i = 0; i < length; i++) {
            in[i][0] = fft_signal[2 * i];
            in[i][1] = fft_signal[2 * i + 1];
        }

        fftw_complex* out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * length);
        fftw_plan p = fftw_plan_dft_1d(length, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
        fftw_execute(p);

        double* ifft_signal = (double*)malloc(length * sizeof(double));
        for (int i = 0; i < length; i++) {
            ifft_signal[i] = out[i][0] / length;
        }

        fftw_destroy_plan(p);
        fftw_free(in);
        fftw_free(out);
        free(filtered_signal);
        free(hanning_window);
        free(fft_signal);

        for (int i = 0; i < length; i++) {
            signal[i] = ifft_signal[i];
        }
        free(ifft_signal);
    }
}

int main() {
    int sequence_length = 1024;
    double* initial_sequence = generate_sequence(sequence_length);
    process_signal(initial_sequence, sequence_length);
    free(initial_sequence);
    return 0;
}