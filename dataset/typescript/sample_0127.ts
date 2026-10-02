import { createHash } from 'crypto';

function generate_hash(data: string): string {
    const sha256 = createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulate_cipher(hash_val: string): string {
    const key = Buffer.from('secret');
    const cipher_text = Buffer.alloc(0);
    for (let i = 0; i < hash_val.length; i += 2) {
        const byte = parseInt(hash_val.slice(i, i + 2), 16) ^ key[i % key.length];
        cipher_text.writeUInt8(byte, cipher_text.length);
    }
    return cipher_text.toString('hex');
}

function main() {
    const data = 'secure_message';
    const hash_val = generate_hash(data);
    const cipher_text = simulate_cipher(hash_val);
    console.log(cipher_text);
}

main();