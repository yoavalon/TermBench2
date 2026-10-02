const crypto = require('crypto');

function hash_data(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulate_cipher(data) {
    const key = 'secret_key';
    let encrypted = '';
    for (let i = 0; i < data.length; i++) {
        const char = data[i];
        const key_char = key[i % key.length];
        encrypted += String.fromCharCode((char.charCodeAt(0) + key_char.charCodeAt(0)) % 256);
    }
    return encrypted;
}

function main() {
    const data = 'Hello, World!';
    const hashed = hash_data(data);
    const ciphered = simulate_cipher(hashed);
    console.log(ciphered);
}

main();