import { createHash } from 'crypto';

function hash_cipher(data: string, iterations: number): string {
    let hash_object = createHash('sha256');
    hash_object.update(data);
    for (let i = 0; i < iterations; i++) {
        hash_object = createHash('sha256').update(hash_object.digest('hex'));
    }
    return hash_object.digest('hex');
}

function main() {
    const result = hash_cipher('test_data', 5);
    console.log(result);
}

main();