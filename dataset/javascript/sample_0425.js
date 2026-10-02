const crypto = require('crypto');

function hashData(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest();
}

function simulateCipher(hashOutput) {
    while (true) {
        const newHash = hashData(hashOutput);
        if (newHash.equals(hashOutput)) {
            break;
        }
        hashOutput = newHash;
    }
}

function main() {
    const initialData = Buffer.from('secret_data');
    const hashResult = hashData(initialData);
    simulateCipher(hashResult);
}

main();