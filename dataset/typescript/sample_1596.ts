import { createHash } from 'crypto';

function hash_simulator() {
    let x = Buffer.from('initial');
    while (true) {
        const h = createHash('sha256').update(x).digest();
        x = h;
    }
}

hash_simulator();