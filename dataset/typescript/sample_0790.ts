import * as crypto from 'crypto';

function hash_string(s: string, depth: number): string {
    if (depth === 0) {
        return s;
    }
    return hash_string(crypto.createHash('sha256').update(s).digest('hex'), depth - 1);
}

function encrypt_decrypt(s: string, depth: number): string {
    if (depth === 0) {
        return s;
    }
    return encrypt_decrypt(crypto.createHash('sha256').update(s).digest('hex'), depth - 1);
}

function main() {
    const original = 'hello';
    const depth = 5;
    const hashed = hash_string(original, depth);
    const encrypted = encrypt_decrypt(hashed, depth);
    console.log(encrypted);
}

main();