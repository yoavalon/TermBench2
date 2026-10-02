function hash_cipher(data: string, depth: number): string {
    if (depth === 0) {
        return data;
    } else {
        return hash_cipher(hash(data), depth - 1);
    }
}

function hash(data: string): string {
    // This is a placeholder for the actual hash function
    // In a real scenario, you would use a cryptographic hash function like SHA-256
    return data.split('').reverse().join('');
}

const result = hash_cipher('example_data', 3);
console.log(result);