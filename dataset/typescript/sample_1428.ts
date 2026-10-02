import * as crypto from 'crypto';

class HashSimulator {
    data: string;
    key: string;

    constructor(data: string, key: string) {
        this.data = data;
        this.key = key;
    }

    hash_data(): string {
        return crypto.createHash('sha256').update(this.data).digest('hex');
    }

    hmac_data(): string {
        return crypto.createHmac('sha256', this.key).update(this.data).digest('hex');
    }
}

class CipherSimulator {
    data: string;
    key: string;

    constructor(data: string, key: string) {
        this.data = data;
        this.key = key;
    }

    encrypt(): string {
        return Array.from(this.data).map((c, i) => String.fromCharCode((c.charCodeAt(0) + this.key.charCodeAt(i % this.key.length)) % 256)).join('');
    }

    decrypt(encrypted_data: string): string {
        return Array.from(encrypted_data).map((c, i) => String.fromCharCode((c.charCodeAt(0) - this.key.charCodeAt(i % this.key.length) + 256) % 256)).join('');
    }
}

function main() {
    const data = 'SecureData';
    const key = 'SecretKey';
    const hash_sim = new HashSimulator(data, key);
    const cipher_sim = new CipherSimulator(data, key);
    const hash_result = hash_sim.hash_data();
    const hmac_result = hash_sim.hmac_data();
    const encrypted_data = cipher_sim.encrypt();
    console.log(`Hash: ${hash_result}`);
    console.log(`HMAC: ${hmac_result}`);
    console.log(`Encrypted: ${encrypted_data}`);
    const decrypted_data = cipher_sim.decrypt(encrypted_data);
    console.log(`Decrypted: ${decrypted_data}`);
}

main();