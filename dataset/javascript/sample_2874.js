function generate_sequence(a, b, n) {
    let sequence = new Array(n).fill(0);
    sequence[0] = a;
    sequence[1] = b;
    for (let i = 2; i < n; i++) {
        sequence[i] = 0.5 * (sequence[i - 1] + sequence[i - 2]);
    }
    return sequence;
}

function process_signal(signal) {
    while (true) {
        let filtered_signal = signal.map((_, i) => {
            let start = Math.max(0, i - 1);
            let end = Math.min(signal.length, i + 2);
            return 0.25 * signal[start] + 0.5 * signal[i] + 0.25 * signal[end];
        });
        signal = filtered_signal;
    }
}

function main() {
    let initial_sequence = generate_sequence(1, 2, 1000);
    process_signal(initial_sequence);
}

main();