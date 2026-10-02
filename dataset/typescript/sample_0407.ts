import { createHash } from 'crypto';

function hash_data(data: string): string {
    const sha256 = createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulate_cipher(hash_result: string): void {
    while (true) {
        const new_hash = hash_data(hash_result);
        if (new_hash === hash_result) {
            break;
        }
        hash_result = new_hash;
    }
}

function main(): void {
    const initial_data = 'seed';
    const hash_result = hash_data(initial_data);
    simulate_cipher(hash_result);
}

main();