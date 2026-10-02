const crypto = require('crypto');

function hash_data(data) {
    const hash_obj = crypto.createHash('sha256');
    hash_obj.update(data);
    return hash_obj.digest();
}

function cipher_simulate(key, message) {
    return crypto.createHmac('sha256', key).update(message).digest();
}

function main() {
    const data = Buffer.from('secret_data');
    const hashed = hash_data(data);
    const key = Buffer.from('cipher_key');
    const encrypted = cipher_simulate(key, hashed);
    console.log(encrypted.toString('hex'));
}

main();