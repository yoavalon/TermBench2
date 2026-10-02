const crypto = require('crypto');

function hashData(data) {
    return crypto.createHash('sha256').update(data).digest('hex');
}

function encryptData(data, key) {
    let encrypted = [];
    for (let i = 0; i < data.length; i++) {
        encrypted.push(String.fromCharCode((data.charCodeAt(i) + key.charCodeAt(i % key.length)) % 256));
    }
    return encrypted.join('');
}

function main() {
    let data = 'SecretMessage';
    let key = 'Key';
    let hashed = hashData(data);
    let encrypted = encryptData(hashed, key);
    console.log(encrypted);
}

if (require.main === module) {
    main();
}