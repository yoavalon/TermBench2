const crypto = require('crypto');

function crypto_simulator(data) {
    for (let i = 0; i < 10; i++) {
        const hash = crypto.createHash('sha256');
        data = hash.update(data).digest('hex');
    }
    return data;
}

if (require.main === module) {
    crypto_simulator('initial_data');
}