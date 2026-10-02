import * as crypto from 'crypto';

class HashSimulator {
    data: Buffer;
    hashFunction: string;

    constructor(data: Buffer) {
        this.data = data;
        this.hashFunction = 'sha256';
    }

    generateHash(): string {
        return crypto.createHash(this.hashFunction).update(this.data).digest('hex');
    }

    generateHmac(key: Buffer): string {
        return crypto.createHmac(this.hashFunction, key).update(this.data).digest('hex');
    }
}

class CipherSimulator {
    data: Buffer;
    key: Buffer;

    constructor(data: Buffer, key: Buffer) {
        this.data = data;
        this.key = key;
    }

    encrypt(): Buffer {
        return Buffer.from(this.data.map((a, i) => a ^ this.key[i % this.key.length]));
    }

    decrypt(): Buffer {
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