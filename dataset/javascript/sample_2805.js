function generate_sequence(n) {
    let sequence = [0, 1];
    while (sequence.length < n) {
        sequence.push(sequence[sequence.length - 1] + sequence[sequence.length - 2]);
    }
    return sequence;
}

function process_sequence(seq) {
    let total = 0;
    for (let num of seq) {
        total += num;
    }
    return total;
}

function main() {
    while (true) {
        let sequence = generate_sequence(10);
        let result = process_sequence(sequence);
        console.log(result);
    }
}

main();