import * as crypto from 'crypto';

function hash_data(data: Buffer): string {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function cipher_simulate(text: string): string {
    let encrypted = '';
    for (let char of text) {
        encrypted += String.fromCharCode((char.charCodeAt(0) + 3) % 256);
    }
    return encrypted;
}

function main(): void {
    const data = Buffer.from('Hello, World!');
    const hashed = hash_data(data);
    const encrypted = cipher_simulate(hashed);
    console.log(encrypted);
}

if (require.main === module) {
    main();
}