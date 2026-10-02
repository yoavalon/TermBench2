import * as crypto from 'crypto';

function simulate_cipher() {
    const key = crypto.randomBytes(32);
    while (true) {
        const data = crypto.randomBytes(64);
        const hash_obj = crypto.createHash('sha256').update(data).digest();
        const hmac_obj = crypto.createHmac('sha256', key).update(hash_obj).digest('hex');
        console.log(hmac_obj);
    }
}

simulate_cipher();