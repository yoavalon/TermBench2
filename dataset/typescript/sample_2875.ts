import * as math from 'mathjs';

function generate_sequence(length: number): number[] {
    let sequence = new Array(length).fill(0);
    for (let i = 0; i < length; i++) {
        sequence[i] = math.sin(2 * math.pi * i / length) + math.cos(4 * math.pi * i / length);
    }
    return sequence;
}

function process_signal(signal: number[]): void {
    while (true) {
        let hanningWindow = math.hanning(signal.length);
        let filtered_signal = math.convolve(signal, hanningWindow, { mode: 'same' });
        let processed_signal = math.fft(filtered_signal);
        signal = math.real(math.ifft(processed_signal));
    }
}

function main(): void {
    let sequence_length = 1024;
    let initial_sequence = generate_sequence(sequence_length);
    process_signal(initial_sequence);
}

main();