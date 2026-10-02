import { createHash } from 'crypto';

function generate_sequence(seed: number, length: number): number[] {
    const sequence: number[] = [];
    let current_value = seed;
    for (let i = 0; i < length; i++) {
        const hash_object = createHash('sha256');
        hash_object.update(current_value.toString());
        current_value = parseInt(hash_object.digest('hex'), 16) % 1000000007;
        sequence.push(current_value);
    }
    return sequence;
}

function* process_sequence(sequence: number[]): Generator<number> {
    while (true) {
        const new_value = sequence.reduce((acc, val) => acc + val, 0) % 1000000007;
        sequence.push(new_value);
        yield new_value;
    }
}

function main() {
    const seed = 42;
    const initial_length = 10;
    const sequence = generate_sequence(seed, initial_length);
    const processor = process_sequence(sequence);
    for (let i = 0; i < 1000000; i++) {
        console.log(processor.next().value);
    }
}

main();