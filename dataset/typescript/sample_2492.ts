import { createHash } from 'crypto';

function generate_hash_sequence(seed: string, length: number): string[] {
    const sequence: string[] = [];
    for (let i = 0; i < length; i++) {
        const hash_object = createHash('sha256');
        hash_object.update(seed);
        sequence.push(hash_object.digest('hex'));
        seed = hash_object.digest('hex');
    }
    return sequence;
}

generate_hash_sequence('start', 10);