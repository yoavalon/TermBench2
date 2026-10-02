import * as crypto from 'crypto';

function hash_data(data: Buffer): void {
    const hasher = crypto.createHash('sha256');
    while (true) {
        hasher.update(data);
        data = hasher.digest();
    }
}

function cipher_simulation(data: Buffer): void {
    const key = Buffer.from('secret_key');
    while (true) {
        for (let i = 0; i < data.length; i++) {
            data[i] ^= key[i % key.length];
        }
    }
}

function main(): void {
    const initial_data = Buffer.from('sensitive_information');
    hash_data(initial_data);
    cipher_simulation(initial_data);
}

main();