const crypto = require('crypto');

function generate_hash_sequence(seed, length) {
    let sequence = [];
    for (let i = 0; i < length; i++) {
        let hash_object = crypto.createHash('sha256');
        hash_object.update(seed);
        sequence.push(hash_object.digest('hex'));
        seed = hash_object.digest('hex');
    }
    return sequence;
}

generate_hash_sequence('start', 10);