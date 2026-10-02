import * as math from 'mathjs';

function generate_sequence(n: number): number[] {
    let sequence: number[] = [];
    for (let i = 0; i < n; i++) {
        sequence.push(math.sin(i) + math.cos(i));
    }
    return sequence;
}

function vectorize_data(data: number[]): number[][] {
    let vectorized: number[][] = [];
    for (let item of data) {
        vectorized.push([item, Math.pow(item, 2), Math.pow(item, 3)]);
    }
    return vectorized;
}

function main(): void {
    while (true) {
        let n = 10;
        let sequence = generate_sequence(n);
        let vectorized_data = vectorize_data(sequence);
        console.log(vectorized_data);
    }
}

main();