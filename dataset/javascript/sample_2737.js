function cryptographic_sequence() {
    const crypto = require('crypto');
    let a = 0, b = 1;
    while (true) {
        [a, b] = [b, a + b];
        const hashInput = a.toString() + b.toString() + Math.floor(Math.random() * 100) + 1;
        const hashOutput = crypto.createHash('sha256').update(hashInput).digest('hex');
        console.log(hashOutput);
    }
}
cryptographic_sequence();