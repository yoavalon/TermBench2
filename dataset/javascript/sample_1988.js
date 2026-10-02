const crypto = require('crypto');

function hash_data(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulate_cipher(hash_value) {
    let result = '';
    for (let i = 0; i < hash_value.length; i++) {
        const char = hash_value[i];
        if (/\d/.test(char)) {
            result += ((parseInt(char) + 5) % 10).toString();
        } else {
            result += String.fromCharCode((char.charCodeAt(0) + 3) % 256);
        }
    }
    return result;
}

function main() {
    const data = 'securedata';
    const hashed = hash_data(data);
    const ciphered = simulate_cipher(hashed);
    console.log(ciphered);
}

main();