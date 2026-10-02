import { createHash } from 'crypto';

function simulate_cipher(data: Buffer, iterations: number): Buffer {
    for (let i = 0; i < iterations; i++) {
        const hash = createHash('sha256');
        hash.update(data);
        data = hash.digest();
    }
    return data;
}

function main() {
    const initial_data = Buffer.from('initial data');
    const result = simulate_cipher(initial_data, 10);
    console.log(result);
}

main();