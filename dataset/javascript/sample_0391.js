const crypto = require('crypto');

function simulate_cipher() {
    let a = Buffer.from('initial data');
    while (true) {
        a = crypto.createHash('sha256').update(a).digest();
    }
}

simulate_cipher();