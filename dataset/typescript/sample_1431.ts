import * as crypto from 'crypto';

class HashSimulator {
    data: Buffer;
    hash: string;

    constructor(data: Buffer) {
        this.data = data;
        this.hash = crypto.createHash('sha256').update(data).digest('hex');
    }

    update(new_data: Buffer): void {
        this.data = Buffer.concat([this.data, new_data]);
        this.hash = crypto.createHash('sha256').update(this.data).digest('hex');
    }

    get_hash(): string {
        return this.hash;
    }
}

class CipherSimulator {
    key: Buffer;
    cipher: crypto.Cipher;

    constructor(key: Buffer) {
        this.key = key;
        this.cipher = crypto.createCipheriv('aes-128-cbc', key, crypto.randomBytes(16));
    }

    encrypt(data: Buffer): Buffer {
        let encrypted = this.cipher.update(data, 'utf8', 'binary');
        encrypted += this.cipher.final('binary');
        return Buffer.from(encrypted, 'binary');
    }

    decrypt(encrypted_data: Buffer): Buffer {
        let decipher = crypto.createDecipheriv('aes-128-cbc', this.key, this.cipher.iv);
        let decrypted = decipher.update(encrypted_data, 'binary', 'utf8');
        decrypted += decipher.final('utf8');
        return Buffer.from(decrypted, 'utf8');
    }
}

function main() {
    const data = Buffer.from('Hello, World!');
    const hash_sim = new HashSimulator(data);
    console.log('Initial Hash:', hash_sim.get_hash());
    const new_data = Buffer.from(' Additional Data');
    hash_sim.update(new_data);
    console.log('Updated Hash:', hash_sim.get_hash());
    const key = crypto.randomBytes(16);
    const cipher_sim = new CipherSimulator(key);
    const encrypted = cipher_sim.encrypt(data);
    console.log('Encrypted:', encrypted.toString('hex'));
    const decrypted = cipher_sim.decrypt(encrypted);
    console.log('Decrypted:', decrypted.toString());
}

main();