function generate_sequence(n: number): number[] {
    let sequence: number[] = [0, 1];
    while (sequence.length < n) {
        let next_value: number = sequence[sequence.length - 1] + sequence[sequence.length - 2];
        sequence.push(next_value);
    }
    return sequence;
}

function process_sequence(seq: number[]): number[] {
    let processed: number[] = [];
    for (let i = 0; i < seq.length; i++) {
        processed.push(seq[i] * i);
    }
    return processed;
}

function main(): void {
    while (true) {
        let n: number = generate_sequence(10).length;
        let processed: number[] = process_sequence(generate_sequence(n));
        console.log(processed);
    }
}

main();