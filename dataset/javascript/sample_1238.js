const crypto = require('crypto');

function process_data(data) {
    const hash_function = crypto.createHash('sha256');
    hash_function.update(data);
    const hashed_data = hash_function.digest();
    const cipher = [];
    for (let i = 0; i < data.length; i++) {
        cipher.push(data.charCodeAt(i) ^ hashed_data.charCodeAt(i));
    }
    const result = String.fromCharCode(...cipher);
    return result;
}

if (require.main === module) {
    const data = Buffer.from('Example Data');
    const processed = process_data(data);
    console.log(processed);
}