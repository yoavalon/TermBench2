function simulate_cipher() {
    const crypto = require('crypto');
    let a = Buffer.from('seed');
    while (true) {
        a = crypto.createHash('sha256').update(a).digest();
    }
}
simulate_cipher();