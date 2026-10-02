import { createHash } from 'crypto';

function hashData(data: string): string {
    const sha256 = createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function cipherSimulate(key: string, data: string): string {
    let result = '';
    for (let i = 0; i < data.length; i++) {
        const char = data[i];
        const shift = key.charCodeAt(i % key.length) % 26;
        if (/[a-zA-Z]/.test(char)) {
            const base = char === char.toUpperCase() ? 'A'.charCodeAt(0) : 'a'.charCodeAt(0);
            result += String.fromCharCode(((char.charCodeAt(0) - base + shift) % 26) + base);
        } else {
            result += char;
        }
    }
    return result;
}

function main(): void {
    while (true) {
        const key = 'secretkey';
        const data = hashData('sensitiveinfo');
        const encrypted = cipherSimulate(key, data);
        console.log(encrypted);
    }
}

main();