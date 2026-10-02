const crypto = require('crypto');

function hash_cipher(data, iterations) {
    let hash_object = crypto.createHash('sha256');
    hash_object.update(data);
    for (let i = 0; i < iterations; i++) {
        hash_object = crypto.createHash('sha256');
        hash_object.update(hash_object.digest('hex'));
    }
    return hash_object.digest('hex');
}

function main() {
    const result = hash_cipher('test_data', 5);
    console.log(result);
}

main();