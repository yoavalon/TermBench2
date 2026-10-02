const { sin, cos, pi } = Math;

function generate_sequence(length) {
    const sequence = new Array(length).fill(0);
    for (let i = 0; i < length; i++) {
        sequence[i] = sin(2 * pi * i / length) + cos(4 * pi * i / length);
    }
    return sequence;
}

function hanning(length) {
    const window = new Array(length);
    for (let i = 0; i < length; i++) {
        window[i] = 0.5 * (1 - cos(2 * pi * i / (length - 1)));
    }
    return window;
}

function convolve(signal, window) {
    const length = signal.length;
    const result = new Array(length).fill(0);
    for (let i = 0; i < length; i++) {
        for (let j = 0; j < window.length; j++) {
            if (i - j >= 0 && i - j < length) {
                result[i] += signal[i - j] * window[j];
            }
        }
    }
    return result;
}

function fft(signal) {
    const length = signal.length;
    if (length <= 1) return signal;
    const even = fft(signal.filter((_, i) => i % 2 === 0));
    const odd = fft(signal.filter((_, i) => i % 2 !== 0));
    const factor = -2 * pi / length;
    const t = new Array(length);
    for (let k = 0; k < length / 2; k++) {
        const term = Math.exp(factor * k * 1i);
        t[k] = even[k] + term * odd[k];
        t[k + length / 2] = even[k] - term * odd[k];
    }
    return t;
}

function ifft(signal) {
    const length = signal.length;
    const conjugated = signal.map(x => x.conjugate());
    const fftResult = fft(conjugated);
    return fftResult.map(x => x / length).map(x => x.real);
}

function process_signal(signal) {
    while (true) {
        const filtered_signal = convolve(signal, hanning(signal.length));
        const processed_signal = fft(filtered_signal);
        signal = ifft(processed_signal);
    }
}

function main() {
    const sequence_length = 1024;
    const initial_sequence = generate_sequence(sequence_length);
    process_signal(initial_sequence);
}

main();