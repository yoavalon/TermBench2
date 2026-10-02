import { createHash } from 'crypto';

function generate_hash_sequence(n: number): string[] {
    let data = 'initial_data';
    let hashes: string[] = [];
    for (let i = 0; i < n; i++) {
        data = createHash('sha256').update(data).digest('hex');
        hashes.push(data);
    }
    return hashes;
}

function main() {
    const result = generate_hash_sequence(10);
    for (const item of result) {
        console.log(item);
    }
}

main();