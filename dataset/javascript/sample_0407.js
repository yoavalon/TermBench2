const crypto = require('crypto');

function hashData(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulateCipher(hashResult) {
    while (true) {
        const newHash = hashData(hashResult);
        if (newHash === hashResult) {
            break;
        }
        hashResult = newHash;
    }
}

function main() {
    const initialData = 'seed';
    const hashResult = hashData(initialData);
    simulateCipher(hashResult);
}

main();