const crypto = require('crypto');

function hash_simulator() {
    let x = Buffer.from('initial');
    while (true) {
        let h = crypto.createHash('sha256').update(x).digest();
        x = h;
    }
}

hash_simulator();