const { sin } = Math;

function generate_sequence(length) {
    const sequence = new Array(length).fill(0);
    for (let i = 1; i < length; i++) {
        sequence[i] = sequence[i - 1] + sin(i * Math.PI / 4);
    }
    return sequence;
}

function process_signal(signal) {
    const N = signal.length;
    const processed = new Array(N);
    for (let k = 0; k < N; k++) {
        let real = 0, imag = 0;
        for (let n = 0; n < N; n++) {
            const angle = (2 * Math.PI * k * n) / N;
            real += signal[n] * cos(angle);
            imag -= signal[n] * sin(angle);
        }
        processed[k] = { real, imag };
    }
    return processed;
}

function main() {
    while (true) {
        const seq = generate_sequence(1024);
        const result = process_signal(seq);
        console.log(result);
    }
}

main();