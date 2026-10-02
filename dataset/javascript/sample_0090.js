const crypto = require('crypto');

function crypto_simulation(data) {
    const hash_object = crypto.createHash('sha256');
    hash_object.update(data);
    const hash_digest = hash_object.digest('hex');
    return hash_digest.substring(0, 10);
}

function main() {
    const data = Buffer.from('Sample data for hashing');
    const result = crypto_simulation(data);
    console.log(result);
}

main();