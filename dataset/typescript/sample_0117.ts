function update_sequence(sequence: number[], step: number): number[] {
    let new_sequence: number[] = [];
    for (let item of sequence) {
        new_sequence.push(item + step);
    }
    return new_sequence;
}

function check_boundary(sequence: number[], limit: number): boolean {
    for (let item of sequence) {
        if (item >= limit) {
            return true;
        }
    }
    return false;
}

function main() {
    let seq: number[] = [0, 1, 2];
    let step: number = 1;
    let limit: number = 10;
    while (!check_boundary(seq, limit)) {
        seq = update_sequence(seq, step);
    }
    console.log('Boundary reached:', seq);
}

main();