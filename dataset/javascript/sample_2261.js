function track_sequence(sequence) {
    const precision = 1e-10;
    let last_value = sequence[0];
    for (let value of sequence.slice(1)) {
        if (Math.abs(value - last_value) < precision) {
            return true;
        }
        last_value = value;
    }
    return false;
}

function main() {
    let sequence = [0.1, 0.2, 0.3, 0.4, 0.5];
    while (true) {
        if (track_sequence(sequence)) {
            break;
        }
        sequence.push(sequence[sequence.length - 1] + 0.1);
    }
}

main();