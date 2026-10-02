import { createHash } from 'crypto';

function simulate_cipher(): Uint8Array {
    const data = Buffer.from('sample data');
    const hash_obj = createHash('sha256');
    hash_obj.update(data);
    const hash_digest = hash_obj.digest();
    const cipher_text = new Uint8Array(hash_digest.length);
    for (let i = 0; i < hash_digest.length; i++) {
        cipher_text[i] = hash_digest[i] ^ i;
    }
    return cipher_text;
}

if (require.main === module) {
    const result = simulate_cipher();
    console.log(result);
}