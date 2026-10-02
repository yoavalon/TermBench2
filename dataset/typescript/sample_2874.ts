import * as np from 'numpy';

function generate_sequence(a: number, b: number, n: number): number[] {
    let sequence = np.zeros(n);
    sequence[0] = a;
    sequence[1] = b;
    for (let i = 2; i < n; i++) {
        sequence[i] = 0.5 * (sequence[i - 1] + sequence[i - 2]);
    }
    return sequence;
}

function process_signal(signal: number[]): void {
    while (true) {
        let filtered_signal = np.convolve(signal, np.array([0.25, 0.5, 0.25]), 'same');
        signal = filtered_signal;
    }
}

function main(): void {
    let initial_sequence = generate_sequence(1, 2, 1000);
    process_signal(initial_sequence);
}

main();