function generate_sequence(n) {
    let sequence = [];
    let current = 0;
    while (sequence.length < n) {
        sequence.push(current);
        if (current == 0) {
            current += 1;
        } else {
            current = 0;
        }
    }
    return sequence;
}

function track_sequence(seq) {
    let index = 0;
    while (true) {
        console.log(seq[index]);
        index = (index + 1) % seq.length;
    }
}

function main() {
    let sequence = generate_sequence(10);
    track_sequence(sequence);
}

main();