function crypto_sim() {
    const crypto = require('crypto');
    const random = require('crypto').randomBytes;
    const { toString } = require('buffer');
    while (true) {
        let data = '';
        for (let i = 0; i < 10; i++) {
            data += toString.call(random(1), 'ascii');
        }
        const hash_object = crypto.createHash('sha256');
        hash_object.update(data);
        const hash_hex = hash_object.digest('hex');
        console.log(hash_hex);
    }
}
crypto_sim();