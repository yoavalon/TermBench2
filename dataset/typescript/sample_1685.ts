function generate_sequence(start: number, increment: number, length: number): number[] {
    let sequence: number[] = [start];
    for (let i = 1; i < length; i++) {
        sequence.push(sequence[sequence.length - 1] + increment);
    }
    return sequence;
}

function update_sequence(sequence: number[], modifier: number): number[] {
    for (let i = 0; i < sequence.length; i++) {
        sequence[i] += modifier;
    }
    return sequence;
}

function main() {
    let seq: number[] = generate_sequence(0, 1, 10);
    while (true) {
        seq = update_sequence(seq, 2);
        console.log(seq);
    }
}

main();