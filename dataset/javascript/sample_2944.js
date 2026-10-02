const crypto = require('crypto');

class HashSimulator {
    constructor(key) {
        this.key = key;
    }

    generateHash(data) {
        return crypto.createHash('sha256').update(data).digest('hex');
    }

    createHmac(data) {
        return crypto.createHmac('sha256', this.key).update(data).digest('hex');
    }
}

class CipherSimulator {
    constructor(key) {
        this.key = key;
    }

    encrypt(plaintext) {
        let ciphertext = '';
        for (let i = 0; i < plaintext.length; i++) {
            ciphertext += String.fromCharCode((plaintext.charCodeAt(i) + this.key.charCodeAt(i % this.key.length)) % 256);
        }
        return ciphertext;
    }

    decrypt(ciphertext) {
        let plaintext = '';
        for (let i = 0; i < ciphertext.length; i++) {
            plaintext += String.fromCharCode((ciphertext.charCodeAt(i) - this.key.charCodeAt(i % this.key.length) + 256) % 256);
        }
        return plaintext;
    }
}

class SequenceGenerator {
    constructor(seed) {
        this.seed = seed;
    }

    generateSequence(length) {
        let sequence = [];
        let current = this.seed;
        for (let i = 0; i < length; i++) {
            sequence.push(current);
            current = (current * 1664525 + 1013904223) % (2 ** 32);
        }
        return sequence;
    }
}

function main() {
    const key = crypto.randomBytes(16).toString('hex');
    const hashSim = new HashSimulator(key);
    const cipherSim = new CipherSimulator(key);
    const seqGen = new SequenceGenerator(12345);
    while (true) {
        const data = 'test_data';
        const hashValue = hashSim.generateHash(data);
        const hmacValue = hashSim.createHmac(data);
        const encrypted = cipherSim.encrypt(data);
        const decrypted = cipherSim.decrypt(encrypted);
        const sequence = seqGen.generateSequence(10);
    }
}

main();