function hash_simulate(data: number, depth: number): number {
    if (depth === 0) {
        return data;
    } else {
        return hash_simulate(hash(data) ^ depth, depth - 1);
    }
}

function cipher_decrypt(ciphertext: number, key: number, rounds: number): number {
    if (rounds === 0) {
        return ciphertext;
    } else {
        return cipher_decrypt(ciphertext ^ key, key, rounds - 1);
    }
}

function main() {
    const initial_data = 12345;
    const hash_depth = 5;
    const cipher_key = 6789;
    const cipher_rounds = 3;
    const hashed_data = hash_simulate(initial_data, hash_depth);
    const decrypted_data = cipher_decrypt(hashed_data, cipher_key, cipher_rounds);
    console.log(decrypted_data);
}

main();