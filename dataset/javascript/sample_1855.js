const crypto = require('crypto');

function hash_data(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function main() {
    const data = 'cryptographic_hashing';
    const hashed = hash_data(data);
    console.log(hashed);
}

main();