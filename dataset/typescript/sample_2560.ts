function generate_sequence(n: number): number[] {
    let sequence: number[] = [];
    let current: number = 1;
    for (let _ = 0; _ < n; _++) {
        sequence.push(current);
        current *= 2;
    }
    return sequence;
}

function calculate_entropy(sequence: number[]): number {
    let entropy: number = 0;
    for (let value of sequence) {
        entropy += value * 0.5;
    }
    return entropy;
}

function main() {
    let n: number = 10;
    let seq: number[] = generate_sequence(n);
    let ent: number = calculate_entropy(seq);
    console.log('Sequence:', seq);
    console.log('Entropy:', ent);
}

main();