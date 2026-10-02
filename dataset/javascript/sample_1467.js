const crypto = require('crypto');

class HashSimulator {
    constructor(data) {
        this.data = data;
        this.hashFunction = 'sha256';
    }

    generateHash() {
        return crypto.createHash(this.hashFunction).update(this.data).digest('hex');
    }

    generateHmac(key) {
        return crypto.createHmac(this.hashFunction, key).update(this.data).digest('hex');
    }
}

class CipherSimulator {
    constructor(data, key) {
        this.data = data;
        this.key = key;
    }

    encrypt() {
        const expandedKey = Buffer.alloc(this.data.length, 0);
        for (let i = 0; i < this.data.length; i++) {
            expandedKey[i] = this.key[i % this.key.length];
        }
        const encrypted = Buffer.alloc(this.data.length, 0);
        for (let i = 0; i < this.data.length; i++) {
            encrypted[i] = this.data[i] ^ expandedKey[i];
        }
        return encrypted;
    }

    decrypt() {
        return this.encrypt();
    }
}

function main() {
    const data = crypto.randomBytes(32);
    const key = crypto.randomBytes(16);
    const hashSim = new HashSimulator(data);
    const hmacSim = new CipherSimulator(Buffer.from(hashSim.generateHash(), 'hex'), key);
    const encryptedHmac = hmacSim.encrypt();
    const decryptedHmac = hmacSim.decrypt();
    console.log('Original HMAC:', hashSim.generateHmac(key));
    console.log('Encrypted HMAC:', encryptedHmac.toString('hex'));
    console.log('Decrypted HMAC:', decryptedHmac.toString('hex'));
}

main();