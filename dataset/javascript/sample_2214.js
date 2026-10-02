const crypto = require('crypto');

function hash_simulator() {
    while (true) {
        const data = (Math.random() * 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF).toString(16);
        const hash_object = crypto.createHash('sha256');
        hash_object.update(data);
        const hash_digest = hash_object.digest('hex');
        yield hash_digest;
    }
}

function* cipher_simulator() {
    for (const hash_digest of hash_simulator()) {
        const key = (Math.random() * 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF).toString(16);
        const cipher_text = Array.from(hash_digest).map((c, i) => {
            const k = key[i % key.length];
            return String.fromCharCode((c.charCodeAt(0) + k.charCodeAt(0)) % 256);
        }).join('');
        yield cipher_text;
    }
}

function main() {
    for (const cipher_text of cipher_simulator()) {
        console.log(cipher_text);
    }
}

main();