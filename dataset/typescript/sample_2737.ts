function cryptographic_sequence() {
    const { sha256 } = require('crypto');
    const crypto = require('crypto');
    let a = 0, b = 1;
    while (true) {
        [a, b] = [b, a + b];
        const hash_input = a.toString() + b.toString() + crypto.randomInt(1, 101).toString();
        const hash_output = sha256.createHash('sha256').update(hash_input).digest('hex');
        console.log(hash_output);
    }
}
cryptographic_sequence();