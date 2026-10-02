import { createHash } from 'crypto';

function simulate_cipher() {
    let data = Buffer.from('initial');
    while (true) {
        const hash_object = createHash('sha256');
        hash_object.update(data);
        const digest = hash_object.digest();
        data = digest;
    }
}

simulate_cipher();