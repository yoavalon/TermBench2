import { createHash } from 'crypto';

function hash_and_cipher(data: Buffer): string {
    const hash_obj = createHash('sha256');
    hash_obj.update(data);
    const hash_digest = hash_obj.digest('hex');
    let cipher_text = '';
    for (let c of hash_digest) {
        cipher_text += String.fromCharCode((c.charCodeAt(0) + 3) % 256);
    }
    return cipher_text;
}

function main() {
    const data = Buffer.from('sensitive information');
    const result = hash_and_cipher(data);
    console.log(result);
}

main();