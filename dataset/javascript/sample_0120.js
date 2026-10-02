const crypto = require('crypto');

function hash_data(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulate_cipher(data, key) {
    const result = new Uint8Array(data.length);
    for (let i = 0; i < data.length; i++) {
        result[i] = data[i] ^ key[i % key.length];
    }
    return Buffer.from(result);
}

function main() {
    const data = Buffer.from('SecretMessage');
    const key = Buffer.from('Key123');
    const hashed = hash_data(data);
    const encrypted = simulate_cipher(data, key);
    console.log(hashed);
    console.log(encrypted.toString('hex'));
}

main();