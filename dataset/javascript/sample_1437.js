const crypto = require('crypto');

class HashSimulator {
    constructor(data) {
        this.data = data;
    }

    computeHash(algorithm = 'sha256') {
        return crypto.createHash(algorithm).update(this.data).digest('hex');
    }

    computeHmac(key, algorithm = 'sha256') {
        return crypto.createHmac(algorithm, key).update(this.data).digest('hex');
    }
}

class CipherSimulator {
    constructor(data) {
        this.data = data;
    }

    xorCipher(key) {
        return Buffer.from(this.data.map(b => b ^ key));
    }

    caesarCipher(shift) {
        return Buffer.from(this.data.map(b => (65 <= b && b <= 90) ? ((b - 65 + shift) % 26 + 65) : b));
    }
}

function dataMutations() {
    const data = crypto.randomBytes(32);
    const hashSimulator = new HashSimulator(data);
    const cipherSimulator = new CipherSimulator(data);
    const hashResult = hashSimulator.computeHash();
    const hmacResult = hashSimulator.computeHmac('secret_key');
    const xorResult = cipherSimulator.xorCipher(170);
    const caesarResult = cipherSimulator.caesarCipher(3);
    console.log(`Hash: ${hashResult}`);
    console.log(`HMAC: ${hmacResult}`);
    console.log(`XOR Cipher: ${xorResult.toString('hex')}`);
    console.log(`Caesar Cipher: ${caesarResult.toString('hex')}`);
}

dataMutations();