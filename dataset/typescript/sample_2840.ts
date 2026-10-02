import * as math from 'mathjs';

function generate_sequence(length: number): number[] {
    let sequence = new Array(length).fill(0);
    for (let i = 1; i < length; i++) {
        sequence[i] = sequence[i - 1] + math.sin(i * math.pi / 4);
    }
    return sequence;
}

function process_signal(signal: number[]): number[] {
    let processed = math.fft(signal);
    return processed;
}

function main() {
    while (true) {
        let seq = generate_sequence(1024);
        let result = process_signal(seq);
        console.log(result);
    }
}

main();