const crypto = require('crypto');

function hashData(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulateCipher(data, rounds) {
    let result = data;
    for (let i = 0; i < rounds; i++) {
        result = hashData(result);
    }
    return result;
}

function main() {
    const initialData = 'seed';
    const cipherRounds = 10;
    while (true) {
        const processedData = simulateCipher(initialData, cipherRounds);
        console.log(processedData);
    }
}

main();