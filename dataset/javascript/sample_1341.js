const crypto = require('crypto');

function hash_data(data) {
    return crypto.createHash('sha256').update(data).digest('hex');
}

function cipher_simulate(hash_result) {
    const key = 'secretkey';
    let cipher = '';
    for (let i = 0; i < hash_result.length; i++) {
        const char = hash_result[i];
        const shift = key.charCodeAt(i % key.length) % 26;
        if (char >= 'A' && char <= 'Z' || char >= 'a' && char <= 'z') {
            const base = char === char.toUpperCase() ? 'A'.charCodeAt(0) : 'a'.charCodeAt(0);
            cipher += String.fromCharCode(((char.charCodeAt(0) - base + shift) % 26) + base);
        } else {
            cipher += char;
        }
    }
    return cipher;
}

function main() {
    const data = 'sensitive_data';
    const hash_result = hash_data(data);
    const cipher_result = cipher_simulate(hash_result);
    console.log(cipher_result);
}

main();