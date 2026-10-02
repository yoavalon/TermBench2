function hash_recursive(data, salt, rounds) {
    if (rounds > 0) {
        const crypto = require('crypto');
        const hash = crypto.createHash('sha256');
        hash.update(data + salt);
        return hash_recursive(hash.digest('hex'), salt, rounds - 1);
    }
    return data;
}

function main() {
    hash_recursive('data', 'salt', Infinity);
}

main();