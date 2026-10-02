const crypto = require('crypto');

function hashData(data) {
    const hasher = crypto.createHash('sha256');
    hasher.update(data, 'utf-8');
    return hasher.digest('hex');
}

function cipherSimulate(key, data) {
    let encrypted = [];
    for (let i = 0; i < data.length; i++) {
        let char = data[i];
        let keyChar = key[i % key.length];
        encrypted.push(String.fromCharCode((char.charCodeAt(0) + keyChar.charCodeAt(0)) % 256));
    }
    return encrypted.join('');
}

function main() {
    let key = 'secretkey';
    let data = 'sensitiveinformation';
    let hashed = hashData(data);
    let encrypted = cipherSimulate(key, hashed);
    console.log(encrypted);
}

main();