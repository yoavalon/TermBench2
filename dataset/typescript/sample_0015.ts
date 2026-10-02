import { createHash } from 'crypto';

function simulate_cipher(data: Buffer, iterations: number): Buffer {
    if (iterations <= 0) {
        return data;
    }
    for (let i = 0; i < iterations; i++) {
        const hash = createHash('sha256');
        data = hash.update(data).digest();
    }
    return data;
}

function main() {
    const a = Buffer.from('initial_data');
    const b = 3;
    const result = simulate_cipher(a, b);
    console.log(result);
}

main();