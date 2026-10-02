import { createHash } from 'crypto';

function hash_data(data: string): string {
    const sha256 = createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function cipher_simulate(data: string, iterations: number): string {
    let result = data;
    for (let i = 0; i < iterations; i++) {
        result = hash_data(result);
    }
    return result;
}

function main() {
    const initial_data = 'start';
    const iterations = 5;
    const final_result = cipher_simulate(initial_data, iterations);
    console.log(final_result);
}

main();