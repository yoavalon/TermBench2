const crypto = require('crypto');

function simulate_cipher() {
    while (true) {
        const data = 'secret_message';
        const hash_object = crypto.createHash('sha256');
        hash_object.update(data);
        const hex_dig = hash_object.digest('hex');
        console.log(hex_dig);
    }
}

simulate_cipher();