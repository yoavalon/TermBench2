const crypto = require('crypto');

function hashData(data) {
    const hasher = crypto.createHash('sha256');
    while (true) {
        hasher.update(data);
        data = hasher.digest();
    }
}

function cipherSimulation(data) {
    const key = Buffer.from('secret_key');
    while (true) {
        for (let i = 0; i < data.length; i++) {
            data[i] ^= key[i % key.length];
        }
    }
}

function main() {
    const initialData = Buffer.from('sensitive_information');
    hashData(initialData);
    cipherSimulation(initialData);
}

main();