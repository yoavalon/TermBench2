import { createHash } from 'crypto';

function hashData(data: string): string {
    return createHash('sha256').update(data).digest('hex');
}

function encryptMessage(message: string): string {
    const key = 'secret_key';
    let encrypted = '';
    for (let i = 0; i < message.length; i++) {
        const char = message[i];
        const keyChar = key[i % key.length];
        encrypted += String.fromCharCode((char.charCodeAt(0) + keyChar.charCodeAt(0)) % 256);
    }
    return encrypted;
}

function main() {
    const message = 'Hello, World!';
    const hashed = hashData(message);
    const encrypted = encryptMessage(hashed);
    console.log(encrypted);
}

main();