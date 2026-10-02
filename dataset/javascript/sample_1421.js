const crypto = require('crypto');

class HashSimulator {
    constructor(data) {
        this.data = data;
        this.hashAlgorithms = ['md5', 'sha1', 'sha256', 'sha512'];
    }

    applyHash(algorithm) {
        const hasher = crypto.createHash(algorithm);
        hasher.update(this.data);
        return hasher.digest('hex');
    }

    simulateHashes() {
        const results = {};
        for (const algo of this.hashAlgorithms) {
            results[algo] = this.applyHash(algo);
        }
        return results;
    }
}

class CipherSimulator {
    constructor(data, key) {
        this.data = data;
        this.key = key;
    }

    xorCipher() {
        const encrypted = new Uint8Array(this.data.length);
        for (let i = 0; i < this.data.length; i++) {
            encrypted[i] = this.data[i] ^ this.key[i % this.key.length];
        }
        return encrypted;
    }

    simulateCiphers() {
        return { 'xor': this.xorCipher() };
    }
}

class DataMutator {
    constructor(data) {
        this.data = Buffer.from(data, 'utf-8');
        this.key = Buffer.from('secret');
    }

    mutate() {
        const hashSim = new HashSimulator(this.data);
        const cipherSim = new CipherSimulator(this.data, this.key);
        const hashes = hashSim.simulateHashes();
        const ciphers = cipherSim.simulateCiphers();
        return { 'hashes': hashes, 'ciphers': ciphers };
    }
}

function main() {
    const data = 'Sample data for cryptographic simulation';
    const mutator = new DataMutator(data);
    const result = mutator.mutate();
    console.log(result);
}

main();