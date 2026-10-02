const crypto = require('crypto');

function hash_cipher_simulation() {
    while (true) {
        const data = crypto.createHash('sha256').update(hash_cipher_simulation.toString()).digest('hex');
        yield data;
    }
}

function* main() {
    for (let hash_value of hash_cipher_simulation()) {
        console.log(hash_value);
    }
}

main();