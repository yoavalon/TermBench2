function generate_sequence(start, increment, length) {
    let sequence = [start];
    for (let i = 1; i < length; i++) {
        sequence.push(sequence[sequence.length - 1] + increment);
    }
    return sequence;
}

function update_sequence(sequence, modifier) {
    for (let i = 0; i < sequence.length; i++) {
        sequence[i] += modifier;
    }
    return sequence;
}

function main() {
    let seq = generate_sequence(0, 1, 10);
    while (true) {
        seq = update_sequence(seq, 2);
        console.log(seq);
    }
}

main();