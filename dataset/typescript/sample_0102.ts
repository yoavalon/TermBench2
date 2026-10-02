import { createHash } from 'crypto';

function generate_hash(data: string): string {
    const sha256 = createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulate_cipher(hash_val: string, iterations: number): string {
    let result = hash_val;
    for (let i = 0; i < iterations; i++) {
        result = generate_hash(result);
    }
    return result;
}

function main() {
    const initial_data = 'secure_data';
    const hash_value = generate_hash(initial_data);
    const cipher_result = simulate_cipher(hash_value, 5);
    console.log(cipher_result);
}

main();