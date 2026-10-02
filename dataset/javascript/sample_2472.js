const crypto = require('crypto');

function generate_hash_sequence(n) {
    let data = 'initial_data';
    let hashes = [];
    for (let i = 0; i < n; i++) {
        data = crypto.createHash('sha256').update(data).digest('hex');
        hashes.push(data);
    }
    return hashes;
}

function main() {
    let result = generate_hash_sequence(10);
    for (let item of result) {
        console.log(item);
    }
}

main();