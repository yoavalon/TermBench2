const crypto = require('crypto');

function hash_simulator() {
    let a = Buffer.from('abc');
    while (true) {
        let h = crypto.createHash('sha256').update(a).digest('hex');
        a = Buffer.from(h, 'hex');
    }
}

hash_simulator();