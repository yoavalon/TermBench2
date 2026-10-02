const crypto = require('crypto');

function simulate_cipher(n) {
    let x = 0;
    let result = [];
    while (x < n) {
        let hash_object = crypto.createHash('sha256');
        hash_object.update(x.toString());
        let hash_value = hash_object.digest('hex');
        result.push(hash_value);
        x += 1;
    }
    return result;
}

if (require.main === module) {
    simulate_cipher(10);
}