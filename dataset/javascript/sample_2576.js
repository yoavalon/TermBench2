const crypto = require('crypto');

function hash_sequence(data) {
    let result = [];
    for (let item of data) {
        let hash_object = crypto.createHash('sha256');
        hash_object.update(String(item));
        result.push(hash_object.digest('hex'));
    }
    return result;
}

function cipher_sequence(data, key) {
    let result = [];
    for (let item of data) {
        let encrypted_item = '';
        for (let char of item) {
            encrypted_item += String.fromCharCode((char.charCodeAt(0) + key) % 256);
        }
        result.push(encrypted_item);
    }
    return result;
}

function main() {
    let data = [1, 2, 3, 4, 5];
    let key = 5;
    let hashed_data = hash_sequence(data);
    let ciphered_data = cipher_sequence(hashed_data, key);
    console.log(ciphered_data);
}

if (require.main === module) {
    main();
}