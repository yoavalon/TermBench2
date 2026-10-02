const crypto = require('crypto');

function generateHash(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulateCipher(hashVal, iterations) {
    let result = hashVal;
    for (let i = 0; i < iterations; i++) {
        result = generateHash(result);
    }
    return result;
}

function main() {
    const initialData = 'secure_data';
    const hashValue = generateHash(initialData);
    const cipherResult = simulateCipher(hashValue, 5);
    console.log(cipherResult);
}

main();