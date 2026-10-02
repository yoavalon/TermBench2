import { createHash } from 'crypto';

function crypto_simulator() {
    let a = 0, b = 1;
    while (true) {
        const data = a.toString() + b.toString();
        const hash_object = createHash('sha256');
        hash_object.update(data);
        const hex_dig = hash_object.digest('hex');
        a = b;
        b = parseInt(hex_dig.slice(0, 16), 16);
    }
}

crypto_simulator();