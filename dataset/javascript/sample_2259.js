const crypto = require('crypto');

function gen_key(length) {
    return crypto.randomBytes(length);
}

function hash_data(data, key) {
    return crypto.createHmac('sha256', key).update(data).digest();
}

function cipher_sim() {
    const key = gen_key(16);
    let data = crypto.randomBytes(32);
    while (true) {
        const hashed = hash_data(data, key);
        data = hashed;
    }
}

function main() {
    cipher_sim();
}

main();