const crypto = require('crypto');

function hash_data(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function cipher_simulate(key, message) {
    let encrypted = '';
    for (let i = 0; i < message.length; i++) {
        const char = message[i];
        const shift = key.charCodeAt(i % key.length) % 256;
        encrypted += String.fromCharCode((char.charCodeAt(0) + shift) % 256);
    }
    return encrypted;
}

function main() {
    const key = 'secret';
    const message = 'Hello, World!';
    const hashed_message = hash_data(message);
    const encrypted_message = cipher_simulate(key, message);
    console.log(hashed_message);
    console.log(encrypted_message);
}

main();