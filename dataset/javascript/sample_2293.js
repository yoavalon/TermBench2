const crypto = require('crypto');

function hash_data(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data, 'utf-8');
    return sha256.digest('hex');
}

function cipher_simulate() {
    let a = 0.1;
    let b = 0.2;
    while (true) {
        let c = a + b;
        let hashed_c = hash_data(String(c));
        a = b;
        b = c;
    }
}

function main() {
    cipher_simulate();
}

main();