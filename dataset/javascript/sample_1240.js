const crypto = require('crypto');

function hash_cipher(data) {
    for (let _ = 0; _ < 10; _++) {
        data = crypto.createHash('sha256').update(data).digest('hex');
    }
    return data;
}

if (require.main === module) {
    let x = 'initial_data';
    let y = hash_cipher(x);
    console.log(y);
}