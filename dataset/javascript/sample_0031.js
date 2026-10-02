function hash_cipher_simulation(data) {
    const crypto = require('crypto');
    for (let i = 0; i < 3; i++) {
        data = crypto.createHash('sha256').update(data).digest('hex');
    }
    return data;
}

if (require.main === module) {
    const result = hash_cipher_simulation('initial_data');
    console.log(result);
}