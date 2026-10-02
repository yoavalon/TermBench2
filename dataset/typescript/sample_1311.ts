import * as crypto from 'crypto';

function hash_data(data: string): string {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulate_cipher(data: string): string {
    let encrypted = '';
    for (let i = 0; i < data.length; i++) {
        const char = data.charCodeAt(i);
        encrypted += String.fromCharCode((char + 3) % 256);
    }
    return encrypted;
}

function main() {
    const data = 'Sample data for hashing and cipher simulation';
    const hashed = hash_data(data);
    const encrypted = simulate_cipher(hashed);
    console.log(encrypted);
}

main();