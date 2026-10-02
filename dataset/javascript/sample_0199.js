const crypto = require('crypto');

function hash_data(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function cipher_simulate(text) {
    let encrypted = '';
    for (let i = 0; i < text.length; i++) {
        let char = text.charCodeAt(i);
        encrypted += String.fromCharCode((char + 3) % 256);
    }
    return encrypted;
}

function main() {
    let data = Buffer.from('Hello, World!');
    let hashed = hash_data(data);
    let encrypted = cipher_simulate(hashed);
    console.log(encrypted);
}

main();