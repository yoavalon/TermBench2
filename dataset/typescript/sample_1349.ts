import * as crypto from 'crypto';

function hash_data(data: string): string {
    const hasher = crypto.createHash('sha256');
    hasher.update(data, 'utf-8');
    return hasher.digest('hex');
}

function cipher_simulate(key: string, data: string): string {
    const encrypted: string[] = [];
    for (let i = 0; i < data.length; i++) {
        const char = data[i];
        const key_char = key[i % key.length];
        encrypted.push(String.fromCharCode((char.charCodeAt(0) + key_char.charCodeAt(0)) % 256));
    }
    return encrypted.join('');
}

function main() {
    const key = 'secretkey';
    const data = 'sensitiveinformation';
    const hashed = hash_data(data);
    const encrypted = cipher_simulate(key, hashed);
    console.log(encrypted);
}

main();