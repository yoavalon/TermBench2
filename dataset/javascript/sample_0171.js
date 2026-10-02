const crypto = require('crypto');

function hash_data(data) {
    return crypto.createHash('sha256').update(data).digest('hex');
}

function encrypt_message(message) {
    const key = 'secret_key';
    let encrypted = '';
    for (let i = 0; i < message.length; i++) {
        const char = message[i];
        const key_char = key[i % key.length];
        encrypted += String.fromCharCode((char.charCodeAt(0) + key_char.charCodeAt(0)) % 256);
    }
    return encrypted;
}

function main() {
    const message = 'Hello, World!';
    const hashed = hash_data(message);
    const encrypted = encrypt_message(hashed);
    console.log(encrypted);
}

main();