const crypto = require('crypto');

function crypto_sequence(seed) {
    while (true) {
        seed = crypto.createHash('sha256').update(seed).digest('hex');
        console.log(seed);
    }
}

crypto_sequence('start');