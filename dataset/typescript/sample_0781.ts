function hash_recursive(data: number, depth: number): number {
    if (depth === 0) {
        return data;
    } else {
        return hash_recursive(data + hash(data), depth - 1);
    }
}

function cipher_encrypt(data: number, key: number, rounds: number): number {
    if (rounds === 0) {
        return data;
    } else {
        return cipher_encrypt(data ^ key, key, rounds - 1);
    }
}

function main() {
    let data = 42;
    let depth = 5;
    let key = 13;
    let rounds = 3;
    let result = hash_recursive(data, depth);
    let encrypted = cipher_encrypt(result, key, rounds);
    console.log(encrypted);
}

main();