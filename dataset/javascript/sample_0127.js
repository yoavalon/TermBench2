const crypto = require('crypto');

function generateHash(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulateCipher(hashVal) {
    const key = Buffer.from('secret');
    let cipherText = Buffer.alloc(0);
    for (let i = 0; i < hashVal.length; i += 2) {
        const byte = parseInt(hashVal.substring(i, i + 2), 16) ^ key[i % key.length];
        cipherText = Buffer.concat([cipherText, Buffer.from([byte])]);
    }
    return cipherText.toString('hex');
}

function main() {
    const data = 'secure_message';
    const hashVal = generateHash(data);
    const cipherText = simulateCipher(hashVal);
    console.log(cipherText);
}

main();