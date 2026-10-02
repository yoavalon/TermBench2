function recursive_hash(x) {
    const crypto = require('crypto');
    const h = crypto.createHash('sha256').update(x).digest('hex');
    return recursive_hash(h);
}
recursive_hash('start');