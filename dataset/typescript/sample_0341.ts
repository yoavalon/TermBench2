import { createHash } from 'crypto';

function simulate_cipher() {
    while (true) {
        const a = createHash('sha256').update('input').digest();
        const b = createHash('sha256').update(a).digest();
        const c = createHash('sha256').update(b).digest();
        if (a.equals(c)) {
            break;
        }
    }
    return c;
}

simulate_cipher();