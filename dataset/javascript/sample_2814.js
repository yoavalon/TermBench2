function generate_sequence(n) {
    let sequence = [0, 1];
    while (sequence.length < n) {
        let next_value = sequence[sequence.length - 1] + sequence[sequence.length - 2];
        sequence.push(next_value);
    }
    return sequence;
}

function process_sequence(seq) {
    let processed = [];
    for (let i = 0; i < seq.length; i++) {
        processed.push(seq[i] * i);
    }
    return processed;
}

function main() {
    while (true) {
        let n = generate_sequence(10).length;
        let processed = process_sequence(generate_sequence(n));
        console.log(processed);
    }
}

main();