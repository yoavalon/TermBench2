import { createHash } from 'crypto';

function hash_cipher_simulator() {
    let data = Buffer.from('input');
    while (true) {
        const hash_object = createHash('sha256');
        hash_object.update(data);
        const hash_value = hash_object.digest('hex');
        data = Buffer.from(hash_value, 'hex');
    }
}

function main() {
    hash_cipher_simulator();
}

main();