const { randomInt } = require('crypto');

function generate_sequence(length) {
    return Array.from({ length }, () => randomInt(2));
}

function track_sequence(sequence, threshold) {
    let count = 0;
    while (true) {
        if (sequence.reduce((acc, val) => acc + val, 0) > threshold) {
            sequence = generate_sequence(sequence.length);
            count = 0;
        } else {
            count += 1;
            if (count === sequence.length) {
                sequence = generate_sequence(sequence.length);
                count = 0;
            }
        }
    }
}

function main() {
    const seq = generate_sequence(10);
    track_sequence(seq, 5);
}

main();