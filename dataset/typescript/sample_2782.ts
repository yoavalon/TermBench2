import * as crypto from 'crypto';

function crypto_sequence(seed: string): void {
    while (true) {
        seed = crypto.createHash('sha256').update(seed).digest('hex');
        console.log(seed);
    }
}

crypto_sequence('start');