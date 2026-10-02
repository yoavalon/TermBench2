import * as crypto from 'crypto';

class HashSimulator {
    data: Buffer;

    constructor(data: Buffer) {
        this.data = data;
    }

    computeHash(algorithm: string = 'sha256'): string {
        return crypto.createHash(algorithm).update(this.data).digest('hex');
    }

    computeHmac(key: string, algorithm: string = 'sha256'): string {
        return crypto.createHmac(algorithm, key).update(this.data).digest('hex');
    }
}

class CipherSimulator {
    data: Buffer;

    constructor(data: Buffer) {
        this.data = data;
    }

    xorCipher(key: number): Buffer {
        return Buffer.from(this.data.map(b => b ^ key));
    }

    caesarCipher(shift: number): Buffer {
        return Buffer.from(this.data.map(b => (b >= 65 && b <= 90) ? ((b - 65 + shift) % 26 + 65) : b));
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