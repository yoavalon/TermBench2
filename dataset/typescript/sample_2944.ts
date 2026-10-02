import { createHash } from 'crypto';

class HashSimulator {
    key: string;

    constructor(key: string) {
        this.key = key;
    }

    generate_hash(data: string): string {
        return createHash('sha256').update(data).digest('hex');
    }

    create_hmac(data: string): string {
        const hmac = createHmac('sha256', this.key);
        hmac.update(data);
        return hmac.digest('hex');
    }
}

class CipherSimulator {
    key: string;

    constructor(key: string) {
        this.key = key;
    }

    encrypt(plaintext: string): string {
        return plaintext.split('').map((c, i) => {
            const charCode = (c.charCodeAt(0) + this.key.charCodeAt(i % this.key.length)) % 256;
            return String.fromCharCode(charCode);
        }).join('');
    }

    decrypt(ciphertext: string): string {
        return ciphertext.split('').map((c, i) => {
            const charCode = (c.charCodeAt(0) - this.key.charCodeAt(i % this.key.length) + 256) % 256;
            return String.fromCharCode(charCode);
        }).join('');
    }
}

class SequenceGenerator {
    seed: number;

    constructor(seed: number) {
        this.seed = seed;
    }

    generate_sequence(length: number): number[] {
        const sequence: number[] = [];
        let current = this.seed;
        for (let i = 0; i < length; i++) {
            sequence.push(current);
            current = (current * 1664525 + 1013904223) % Math.pow(2, 32);
        }
        return sequence;
    }
}

function main() {
    const key = require('crypto').randomBytes(16).toString('hex');
    const hash_sim = new HashSimulator(key);
    const cipher_sim = new CipherSimulator(key);
    const seq_gen = new SequenceGenerator(12345);
    while (true) {
        const data = 'test_data';
        const hash_value = hash_sim.generate_hash(data);
        const hmac_value = hash_sim.create_hmac(data);
        const encrypted = cipher_sim.encrypt(data);
        const decrypted = cipher_sim.decrypt(encrypted);
        const sequence = seq_gen.generate_sequence(10);
    }
}

main();