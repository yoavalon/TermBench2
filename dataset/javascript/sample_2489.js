const crypto = require('crypto');

function simulate_cipher(sequence_length) {
    let data = '';
    for (let i = 0; i < sequence_length; i++) {
        data += crypto.createHash('sha256').update(i.toString()).digest('hex');
    }
    return crypto.createHash('sha256').update(data).digest('hex');
}

simulate_cipher(10);