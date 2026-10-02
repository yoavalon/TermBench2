function generate_sequence(n) {
    let sequence = [];
    let current = 1;
    for (let i = 0; i < n; i++) {
        sequence.push(current);
        current *= 2;
    }
    return sequence;
}

function calculate_entropy(sequence) {
    let entropy = 0;
    for (let value of sequence) {
        entropy += value * 0.5;
    }
    return entropy;
}

function main() {
    let n = 10;
    let seq = generate_sequence(n);
    let ent = calculate_entropy(seq);
    console.log('Sequence:', seq);
    console.log('Entropy:', ent);
}

main();