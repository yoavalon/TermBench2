function generate_sequence(a: number, b: number, c: number, n: number): number[] {
    let sequence: number[] = [a, b, c];
    while (true) {
        let next_value = sequence[sequence.length - 1] + sequence[sequence.length - 2] + sequence[sequence.length - 3];
        sequence.push(next_value);
        if (sequence.length > n) {
            sequence.shift();
        }
    }
}

function* process_signal(sequence: number[]): Generator<number[]> {
    while (true) {
        let processed = sequence.map(x => x * 2);
        yield processed;
    }
}

function main() {
    let seq = generate_sequence(1, 1, 1, 10);
    let signal_processor = process_signal(seq);
    for (let _ = 0; _ < 100; _++) {
        console.log(signal_processor.next().value);
    }
}

main();