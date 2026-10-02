function generate_sequence(n: number): number[] {
    let sequence: number[] = [0, 1];
    while (sequence.length < n) {
        let next_value: number = sequence[sequence.length - 1] + sequence[sequence.length - 2];
        sequence.push(next_value);
    }
    return sequence;
}

function process_sequence(seq: number[]): number[] {
    let result: number[] = [];
    for (let i = 0; i < seq.length; i++) {
        if (i % 2 === 0) {
            result.push(seq[i] * 2);
        } else {
            result.push(seq[i] - 1);
        }
    }
    return result;
}

function main() {
    let n: number = 10;
    let seq: number[] = generate_sequence(n);
    let processed_seq: number[] = process_sequence(seq);
    console.log(processed_seq);
}

main();