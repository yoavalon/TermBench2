import { createHash } from 'crypto';

function generate_sequence(seed: number, length: number): number[] {
    const sequence: number[] = [];
    let current = seed;
    for (let i = 0; i < length; i++) {
        const hash_object = createHash('sha256');
        hash_object.update(current.toString());
        current = parseInt(hash_object.digest('hex'), 16);
        sequence.push(current);
    }
    return sequence;
}

function analyze_sequence(sequence: number[]): Record<number, number> {
    const stats: Record<number, number> = {};
    for (const num of sequence) {
        stats[num] = (stats[num] || 0) + 1;
    }
    return stats;
}

function main() {
    const seed = 42;
    const length = 10;
    const seq = generate_sequence(seed, length);
    const stats = analyze_sequence(seq);
    console.log(stats);
}

main();