function update_sequence(sequence, step) {
    let new_sequence = [];
    for (let item of sequence) {
        new_sequence.push(item + step);
    }
    return new_sequence;
}

function check_boundary(sequence, limit) {
    for (let item of sequence) {
        if (item >= limit) {
            return true;
        }
    }
    return false;
}

function main() {
    let seq = [0, 1, 2];
    let step = 1;
    let limit = 10;
    while (!check_boundary(seq, limit)) {
        seq = update_sequence(seq, step);
    }
    console.log('Boundary reached:', seq);
}

main();