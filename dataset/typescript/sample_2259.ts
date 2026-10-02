import * as crypto from 'crypto';

function gen_key(length: number): Buffer {
    return crypto.randomBytes(length);
}

function hash_data(data: Buffer, key: Buffer): Buffer {
    return crypto.createHmac('sha256', key).update(data).digest();
}

function cipher_sim(): void {
    const key = gen_key(16);
    let data = crypto.randomBytes(32);
    while (true) {
        const hashed = hash_data(data, key);
        data = hashed;
    }
}

function main(): void {
    cipher_sim();
}

main();