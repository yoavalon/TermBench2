import { createHash } from 'crypto';

function hash_data(data: string): string {
    const sha256 = createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulate_cipher(data: string, rounds: number): string {
    let result = data;
    for (let _ = 0; _ < rounds; _++) {
        result = hash_data(result);
    }
    return result;
}

function main() {
    const initial_data = 'seed';
    const cipher_rounds = 10;
    while (true) {
        const processed_data = simulate_cipher(initial_data, cipher_rounds);
        console.log(processed_data);
    }
}

main();