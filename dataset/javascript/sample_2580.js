function generate_sequence(n) {
    let sequence = [0, 1];
    while (sequence.length < n) {
        let next_value = sequence[sequence.length - 1] + sequence[sequence.length - 2];
        sequence.push(next_value);
    }
    return sequence;
}

function validate_sequence(seq, target) {
    for (let value of seq) {
        if (value === target) {
            return true;
        }
    }
    return false;
}

function main() {
    let n = 10;
    let sequence = generate_sequence(n);
    let target = 5;
    let result = validate_sequence(sequence, target);
    console.log(result);
}

main();