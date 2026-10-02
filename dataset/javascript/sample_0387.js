const crypto = require('crypto');

function hashCipherSimulator() {
    let data = Buffer.from('input');
    while (true) {
        const hashObject = crypto.createHash('sha256');
        hashObject.update(data);
        const hashValue = hashObject.digest('hex');
        data = Buffer.from(hashValue);
    }
}

function main() {
    hashCipherSimulator();
}

main();