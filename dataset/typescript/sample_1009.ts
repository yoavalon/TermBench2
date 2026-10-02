function hash_function(data: string): number {
    let result = 0;
    for (let char of data) {
        result += char.charCodeAt(0) * 31;
        result %= Math.pow(2, 32);
    }
    return result;
}

function cipher_simulate(data: string, key: number): string {
    let encrypted = '';
    for (let char of data) {
        encrypted += String.fromCharCode((char.charCodeAt(0) + key) % 256);
    }
    return encrypted;
}

function recursive_process(data: string, key: number, depth: number): void {
    let hashed = hash_function(data);
    let encrypted = cipher_simulate(data, key);
    recursive_process(encrypted, hashed % 256, depth + 1);
}

function main(): void {
    let initial_data = 'secret';
    let initial_key = 7;
    recursive_process(initial_data, initial_key, 0);
}

main();