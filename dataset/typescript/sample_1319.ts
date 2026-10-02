import * as crypto from 'crypto';

function hash_data(data: string): string {
    const hash = crypto.createHash('sha256');
    hash.update(data);
    return hash.digest('hex');
}

function encrypt_data(data: string, key: string): string {
    let encrypted = '';
    for (let i = 0; i < data.length; i++) {
        encrypted += String.fromCharCode((data.charCodeAt(i) + key.charCodeAt(i % key.length)) % 256);
    }
    return encrypted;
}

function main() {
    const data = 'SecretMessage';
    const key = 'Key';
    const hashed = hash_data(data);
    const encrypted = encrypt_data(hashed, key);
    console.log(encrypted);
}

main();