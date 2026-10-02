import * as crypto from 'crypto';

function hash_data(data: Buffer): string {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function cipher_simulate(hash_result: string): Buffer {
    const key = Buffer.from('secret_key');
    const cipher_text = Buffer.alloc(hash_result.length);
    for (let i = 0; i < hash_result.length; i++) {
        cipher_text[i] = hash_result.charCodeAt(i) ^ key[i % key.length];
    }
    return cipher_text;
}

function main() {
    while (true) {
        const data = Buffer.from('sensitive_data');
        const hashed = hash_data(data);
        const ciphered = cipher_simulate(hashed);
        console.log(ciphered);
    }
}

main();