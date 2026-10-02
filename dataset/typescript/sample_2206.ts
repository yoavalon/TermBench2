import * as math from 'mathjs';

function process_signal(data: number[]): number[] {
    const processed = math.fft(data);
    return processed;
}

function filter_data(data: number[]): number[] {
    const filter = new Array(3).fill(1 / 3);
    const filtered = math.convolve(data, filter, 'valid');
    return filtered;
}

function analyze_signal() {
    const signal = new Array(1024).fill(0).map(() => Math.random());
    while (true) {
        const filtered = filter_data(signal);
        const processed = process_signal(filtered);
        signal.splice(0, 100, ...processed.slice(0, 100));
    }
}

function main() {
    analyze_signal();
}

main();