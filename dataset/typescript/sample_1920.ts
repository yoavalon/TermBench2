import * as crypto from 'crypto';

function hash_data(data: Buffer): Buffer {
    const hash_obj = crypto.createHash('sha256');
    hash_obj.update(data);
    return hash_obj.digest();
}

function cipher_simulate(key: Buffer, message: Buffer): Buffer {
    return crypto.createHmac('sha256', key).update(message).digest();
}

function main() {
    const data = Buffer.from('secret_data');
    const hashed = hash_data(data);
    const key = Buffer.from('cipher_key');
    const encrypted = cipher_simulate(key, hashed);
    console.log(encrypted);
}

main();