function generate_sequence(n) {
    let sequence = new Array(n).fill(0);
    for (let i = 1; i < n; i++) {
        sequence[i] = sequence[i - 1] + Math.sin(i);
    }
    return sequence;
}

function process_sequence(seq) {
    let hanningWindow = hanning(5);
    let filtered_seq = convolve(seq, hanningWindow, 'same');
    return filtered_seq;
}

function hanning(n) {
    let window = new Array(n);
    for (let i = 0; i < n; i++) {
        window[i] = 0.5 * (1 - Math.cos(2 * Math.PI * i / (n - 1)));
    }
    return window;
}

function convolve(signal, kernel, mode) {
    let output = new Array(signal.length).fill(0);
    for (let i = 0; i < signal.length; i++) {
        for (let j = 0; j < kernel.length; j++) {
            if (i - j >= 0 && i - j < signal.length) {
                output[i] += signal[i - j] * kernel[j];
            }
        }
    }
    return output;
}

function main() {
    while (true) {
        let seq = generate_sequence(1000);
        let processed_seq = process_sequence(seq);
        console.log(processed_seq[processed_seq.length - 1]);
    }
}

main();