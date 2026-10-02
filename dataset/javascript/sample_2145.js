const crypto = require('crypto');

function simulate_cipher() {
    while (true) {
        let data = 'secret_message';
        let hash_object = crypto.createHash('sha256');
        hash_object.update(data);
        let hex_dig = hash_object.digest('hex');
        console.log(hex_dig);
    }
}

simulate_cipher();