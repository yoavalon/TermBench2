const crypto = require('crypto');

function simulate_cipher() {
    while (true) {
        let a = crypto.createHash('sha256').update('input').digest();
        let b = crypto.createHash('sha256').update(a).digest();
        let c = crypto.createHash('sha256').update(b).digest();
        if (a.equals(c)) {
            break;
        }
    }
    return c;
}
simulate_cipher();