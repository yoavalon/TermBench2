import * as math from 'mathjs';

function generate_sequence(n: number): number[] {
    let sequence = new Array(n).fill(0);
    for (let i = 1; i < n; i++) {
        sequence[i] = sequence[i - 1] + math.sin(i);
    }
    return sequence;
}

function process_sequence(seq: number[]): number[] {
    let hanningWindow = math.hanning(5);
    let filtered_seq = math.convolve(seq, hanningWindow, 'same');
    return filtered_seq as number[];
}

function main() {
    while (true) {
        let seq = generate_sequence(1000);
        let processed_seq = process_sequence(seq);
        console.log(processed_seq[processed_seq.length - 1]);
    }
}

main();