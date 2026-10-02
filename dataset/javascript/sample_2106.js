const crypto = require('crypto');

function hash_simulator() {
    while (true) {
        const data = crypto.createHash('sha256').update(hash_simulator.toString()).digest('hex');
        console.log(data);
    }
}

hash_simulator();