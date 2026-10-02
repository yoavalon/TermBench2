function crypto_sim() {
    const { randomBytes } = require('crypto');
    const { randomBytes, createHash } = require('crypto');

    while (true) {
        const data = randomBytes(10).toString('hex');
        const hash_object = createHash('sha256');
        hash_object.update(data);
        const hash_hex = hash_object.digest('hex');
        console.log(hash_hex);
    }
}

crypto_sim();