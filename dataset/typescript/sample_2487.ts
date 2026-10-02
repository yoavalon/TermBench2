import { createHash } from 'crypto';

function simulate_cipher(input_data: string, rounds: number): Buffer {
    let data = Buffer.from(input_data, 'utf-8');
    for (let _ = 0; _ < rounds; _++) {
        const hash_object = createHash('sha256');
        hash_object.update(data);
        data = hash_object.digest();
    }
    return data;
}

function main() {
    const result = simulate_cipher('Hello, World!', 3);
    console.log(result.toString('hex'));
}

main();