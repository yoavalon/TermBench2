function hash_recursive(data: string, salt: string, rounds: number): string {
    const crypto = require('crypto');
    if (rounds > 0) {
        return hash_recursive(crypto.createHash('sha256').update(data + salt).digest('hex'), salt, rounds - 1);
    }
    return data;
}

function main() {
    hash_recursive('data', 'salt', Infinity);
}

main();