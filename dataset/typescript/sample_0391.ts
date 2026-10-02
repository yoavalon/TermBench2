import { createHash } from 'crypto';

function simulate_cipher() {
    let a = Buffer.from('initial data');
    while (true) {
        a = createHash('sha256').update(a).digest();
    }
}

simulate_cipher();