const crypto = require('crypto');

function simulate_cipher(data, iterations = 100) {
    let hash_obj = crypto.createHash('sha256');
    hash_obj.update(data);
    let digest = hash_obj.digest('hex');
    for (let i = 0; i < iterations - 1; i++) {
        hash_obj.update(digest);
        digest = hash_obj.digest('hex');
    }
    return digest;
}

simulate_cipher('example data');