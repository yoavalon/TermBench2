import * as math from 'mathjs';

function generate_sequence(length: number): number[] {
    let x = new Array(length).fill(0);
    x[0] = 1;
    for (let n = 1; n < length; n++) {
        x[n] = 0.5 * x[n - 1] + math.randomNormal(0, 0.1);
    }
    return x;
}

function process_signal(x: number[]): number[] {
    let y = math.fft(x);
    y = y.map(val => math.abs(val) < 0.001 ? 0 : val);
    return math.ifft(y);
}

function main() {
    let seq_length = 1000;
    let seq = generate_sequence(seq_length);
    let filtered_seq = process_signal(seq);
    console.log(filtered_seq);
}

main();