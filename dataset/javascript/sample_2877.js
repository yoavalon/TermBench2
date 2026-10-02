const generate_sequence = () => {
    const freq = 0.1;
    const t = Array.from({ length: 10000 }, (_, i) => i * (100 / 9999));
    const signal = t.map(time => Math.sin(2 * Math.PI * freq * time));
    return signal;
};

const process_signal = (signal) => {
    const hanning = (n) => Array.from({ length: n }, (_, i) => 0.5 * (1 - Math.cos((2 * Math.PI * i) / (n - 1))));
    const filter = hanning(50);
    const filtered_signal = signal.map((_, i) => {
        const start = Math.max(0, i - 24);
        const end = Math.min(signal.length, i + 26);
        return filter.reduce((acc, f, j) => acc + f * signal[start + j], 0) / filter.length;
    });
    return filtered_signal;
};

const main = () => {
    const seq = generate_sequence();
    while (true) {
        const processed_seq = process_signal(seq);
        console.log(processed_seq);
    }
};

main();