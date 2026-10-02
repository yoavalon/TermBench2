import * as crypto from 'crypto';

function hash_data(data: string): string {
    const hash_object = crypto.createHash('sha256');
    hash_object.update(data);
    return hash_object.digest('hex');
}

function mutate_data(data: string, iterations: number): string {
    for (let _ = 0; _ < iterations; _++) {
        data = hash_data(data);
    }
    return data;
}

function main() {
    const initial_data = 'seed';
    const iterations = 5;
    const result = mutate_data(initial_data, iterations);
    console.log(result);
}

main();