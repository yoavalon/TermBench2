import * as random from 'random';

function generate_sequence(length: number): number[] {
    return Array.from({ length }, () => random.int(0, 1));
}

function track_sequence(sequence: number[], threshold: number): void {
    let count = 0;
    while (true) {
        if (sequence.reduce((a, b) => a + b, 0) > threshold) {
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

function main(): void {
    const seq = generate_sequence(10);
    track_sequence(seq, 5);
}

main();