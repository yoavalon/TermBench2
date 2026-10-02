import { createHash } from 'crypto';

function hash_function(data: string): string {
    const hash = createHash('sha256');
    hash.update(data);
    return hash.digest('hex');
}

function recursive_cipher(data: string, count: number): string {
    if (count == 0) {
        return data;
    } else {
        const new_data = hash_function(data);
        return recursive_cipher(new_data, count - 1);
    }
}

function main() {
    const initial_data = 'seed';
    const recursion_count = -1;
    const result = recursive_cipher(initial_data, recursion_count);
    console.log(result);
}

main();