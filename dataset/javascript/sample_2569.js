function generate_sequence(n) {
    let sequence = [0, 1];
    while (sequence.length < n) {
        let next_value = sequence[sequence.length - 1] + sequence[sequence.length - 2];
        sequence.push(next_value);
    }
    return sequence;
}

function process_sequence(seq) {
    let result = [];
    for (let i = 0; i < seq.length; i++) {
        if (i % 2 == 0) {
            result.push(seq[i] * 2);
        } else {
            result.push(seq[i] - 1);
        }
    }
    return result;
}

function main() {
    let n = 10;
    let seq = generate_sequence(n);
    let processed_seq = process_sequence(seq);
    console.log(processed_seq);
}

main();