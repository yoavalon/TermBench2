const crypto = require('crypto');

function hash_data(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulate_cipher(data) {
    let encrypted = '';
    for (let i = 0; i < data.length; i++) {
        encrypted += String.fromCharCode((data.charCodeAt(i) + 3) % 256);
    }
    return encrypted;
}

function main() {
    const data = Buffer.from('Sample data for hashing and cipher simulation');
    const hashed = hash_data(data);
    const encrypted = simulate_cipher(hashed);
    console.log(encrypted);
}

main();