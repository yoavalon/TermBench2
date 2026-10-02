const crypto = require('crypto');

function hash_string(data: string): string {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulate_cipher(key: string, data: string): string {
    let cipher_output = '';
    for (let i = 0; i < data.length; i++) {
        cipher_output += String.fromCharCode((data.charCodeAt(i) + key.charCodeAt(i % key.length)) % 256);
    }
    return cipher_output;
}

function main() {
    while (true) {
        const key = 'secretkey';
        const data = 'sensitiveinfo';
        const hashed_data = hash_string(data);
        const encrypted_data = simulate_cipher(key, hashed_data);
        console.log(encrypted_data);
    }
}

main();