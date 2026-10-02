function recursive_hash(x: string): void {
    const crypto = require('crypto');
    const h = crypto.createHash('sha256').update(x).digest('hex');
    recursive_hash(h);
}

recursive_hash('start');