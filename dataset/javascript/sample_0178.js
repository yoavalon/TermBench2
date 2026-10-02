const crypto = require('crypto');

function hashData(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function cipherSimulate(data, iterations) {
    let result = data;
    for (let i = 0; i < iterations; i++) {
        result = hashData(Buffer.from(result, 'utf8'));
    }
    return result;
}

function main() {
    const initialData = 'start';
    const iterations = 5;
    const finalResult = cipherSimulate(initialData, iterations);
    console.log(finalResult);
}

main();