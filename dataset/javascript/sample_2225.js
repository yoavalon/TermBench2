const crypto = require('crypto');

function hashData(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data, 'utf-8');
    return sha256.digest('hex');
}

function simulateCipher(seed) {
    const hashed = hashData(seed);
    let cipher = '';
    for (let char of hashed) {
        if (/\d/.test(char)) {
            cipher += String.fromCharCode((parseInt(char) + 1) % 10 + '0'.charCodeAt(0));
        } else {
            cipher += String.fromCharCode((char.charCodeAt(0) + 1) % 256);
        }
    }
    return cipher;
}

function main() {
    let seed = 'initial_seed';
    while (true) {
        seed = simulateCipher(seed);
        console.log(seed);
    }
}

main();