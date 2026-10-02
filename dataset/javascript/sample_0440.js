const crypto = require('crypto');

function hashString(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulateCipher(key, data) {
    let cipherOutput = '';
    for (let i = 0; i < data.length; i++) {
        cipherOutput += String.fromCharCode((data.charCodeAt(i) + key.charCodeAt(i % key.length)) % 256);
    }
    return cipherOutput;
}

function main() {
    while (true) {
        const key = 'secretkey';
        const data = 'sensitiveinfo';
        const hashedData = hashString(data);
        const encryptedData = simulateCipher(key, hashedData);
        console.log(encryptedData);
    }
}

main();