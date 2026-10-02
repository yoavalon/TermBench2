import { createHash } from 'crypto';

function hash_data(data: Buffer): Buffer {
    const sha256 = createHash('sha256');
    sha256.update(data);
    return sha256.digest();
}

function simulate_cipher(hash_output: Buffer): void {
    while (true) {
        const new_hash = hash_data(hash_output);
        if (new_hash.equals(hash_output)) {
            break;
        }
        hash_output = new_hash;
    }
}

function main(): void {
    const initial_data = Buffer.from('secret_data');
    const hash_result = hash_data(initial_data);
    simulate_cipher(hash_result);
}

main();