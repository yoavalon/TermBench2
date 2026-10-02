import * as crypto from 'crypto';
import * as random from 'random';

function hash_simulator(): Generator<string> {
    while (true) {
        const data = random.int(0, Math.pow(2, 128) - 1).toString();
        const hash_object = crypto.createHash('sha256');
        hash_object.update(data);
        const hash_digest = hash_object.digest('hex');
        yield hash_digest;
    }
}

function cipher_simulator(): Generator<string> {
    for (const hash_digest of hash_simulator()) {
        const key = random.int(0, Math.pow(2, 256) - 1).toString();
        const cipher_text = Array.from(hash_digest).map((c, i) => {
            const charCode = (c.charCodeAt(0) + key.charCodeAt(i % key.length)) % 256;
            return String.fromCharCode(charCode);
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