const crypto = require('crypto');

function simulate_hash(x) {
    const a = crypto.createHash('sha256');
    a.update(String(x), 'utf-8');
    const b = a.digest('hex');
    return b;
}

function main() {
    for (let i = 0; i < 10; i++) {
        console.log(simulate_hash(i));
    }
}

main();