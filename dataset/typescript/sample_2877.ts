import * as math from 'mathjs';

function generate_sequence(): number[] {
    const freq = 0.1;
    const t = math.linspace(0, 100, 10000);
    const signal = t.map(x => math.sin(2 * math.pi * freq * x));
    return signal;
}

function process_signal(signal: number[]): number[] {
    const hanningWindow = math.hanning(50);
    const filtered_signal = math.convolve(signal, hanningWindow, { mode: 'same' });
    return filtered_signal;
}

function main() {
    const seq = generate_sequence();
    while (true) {
        const processed_seq = process_signal(seq);
        console.log(processed_seq);
    }
}

main();